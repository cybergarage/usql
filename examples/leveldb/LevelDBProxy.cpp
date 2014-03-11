/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "LevelDBProxy.h"
#include "MD5.h"
#include "SQLProxyDataSet.h"

using namespace std;
using namespace uSQL;
using namespace leveldb;

uSQL::LevelDBProxy::LevelDBProxy()
{
  this->db = NULL;
}

uSQL::LevelDBProxy::~LevelDBProxy()
{
  close();
}

bool uSQL::LevelDBProxy::open(const std::string &filename)
{
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, filename, &this->db);  
  return status.ok();
}

bool uSQL::LevelDBProxy::close()
{
  if (this->db) {
    delete this->db;
    this->db = NULL;
  }
  return true;
}


bool uSQL::LevelDBProxy::getInsertStatementKey(SQLStatement *stmt, std::string &key, SQLError &error) 
{
  SQLCollection *collectionNode = stmt->getCollectionNode();
  if (!collectionNode) {
    error.setMessage("Collection was not found");
    return false;
  }

  SQLColumns *sqlColumns = stmt->getColumnsNode();
  if (!sqlColumns) {
    error.setMessage("COLUMN section was not found");
    return false;
  }
  SQLNode *sqlColumn = sqlColumns->getChildNode(0);
  if (!sqlColumn) {
    error.setMessage("Key column was not found");
    return false;
  }
  
  SQLValues *sqlValues = stmt->getValuesNode();
  if (!sqlValues) {
    error.setMessage("VALUE section was not found");
    return false;
  }
  SQLNode *sqlValue = sqlValues->getChildNode(0);
  if (!sqlValue) {
    error.setMessage("Key value was not found");
    return false;
  }

  SQLExpression exprNode;
  SQLOperatorSEQ *eqNode = new SQLOperatorSEQ();
  SQLExpression *leftExprNode = new SQLExpression();
  leftExprNode->setValue(sqlColumn->getValue());
  eqNode->addExpression(leftExprNode);
  SQLExpression *rightExprNode = new SQLExpression();
  rightExprNode->setValue(sqlValue->getValue());
  eqNode->addExpression(rightExprNode);
  exprNode.addExpression(eqNode);
  
  return SQLProxy::getKey(collectionNode, &exprNode, key);
}

bool uSQL::LevelDBProxy::getStatementKey(SQLStatement *stmt, std::string &key, SQLError &error) 
{
  SQLCollections *sqlFrom = stmt->getCollectionsNode();
  if (!sqlFrom) {
    error.setMessage("FROM section was not found");
    return false;
  }
  
  if (sqlFrom->getChildCount() < 1) {
    error.setMessage("Data source was not found");
    return false;
  }
  if (1 < sqlFrom->getChildCount()) {
    error.setMessage("Data source is more than one");
    return false;
  }
  
  SQLCollection *dataSource = sqlFrom->getCollectionNode(0);
  
  SQLWhere *sqlWhere = stmt->getWhereNode();
  if (!sqlWhere) {
    error.setMessage("WHERE section was not found");
    return false;
  }
  
  if (sqlWhere->getChildCount() < 1) {
    error.setMessage("Expression was not found");
    return false;
  }
  
  SQLExpression *exprNode = sqlWhere->getExpression(0);

  return SQLProxy::getKey(dataSource, exprNode, key);
}

bool uSQL::LevelDBProxy::getKey(SQLStatement *stmt, std::string &key, SQLError &error) 
{
  SQLCommand *sqlCmd = stmt->getCommandNode();
  if (!sqlCmd) {
    error.setMessage("COMMAND section was not found");
    return false;
  }
  
  if (sqlCmd->isInsert()) 
    return getInsertStatementKey(stmt, key, error);

  return getStatementKey(stmt, key, error);
}


bool uSQL::LevelDBProxy::select(SQLStatement *stmt, SQLProxyResult &result) 
{
  string hashKey;
  if (getKey(stmt, hashKey, result) == false)
    return false;

  std::string valuesString;
  Status status = this->db->Get(leveldb::ReadOptions(), hashKey, &valuesString);
  if(!status.ok()) {
    result.setErrorMessage(status.ToString());
    return true;
  }
  
  SQLProxyDataSet *values = result.getResultSet();
  if (values->parse(valuesString) == false) {
    result.setErrorMessage("Stored data was corrupted");
    return false;
  }
  
  return true;
}

bool uSQL::LevelDBProxy::insert(SQLStatement *stmt, SQLError &error) 
{
  string hashKey;
  if (getKey(stmt, hashKey, error) == false)
    return false;
    
  SQLProxyDataSet valuesDict;
  if (getInsertDictionary(stmt, valuesDict, error) == false)
    return false;

  Status status = this->db->Put(leveldb::WriteOptions(), hashKey, valuesDict.toString());
  if(!status.ok()) {
    error.setMessage(status.ToString());
    return false;
  }
  
  return true;
}

bool uSQL::LevelDBProxy::update(SQLStatement *stmt, SQLError &error) 
{
  Status status;
  
  string hashKey;
  if (getKey(stmt, hashKey, error) == false)
    return false;

  std::string valuesString;
  status = this->db->Get(leveldb::ReadOptions(), hashKey, &valuesString);
  if(!status.ok()) {
    error.setMessage(status.ToString());
    return false;
  }
  
  SQLProxyDataSet valuesDict;
  if (valuesDict.parse(valuesString) == false) {
    error.setMessage("Stored data was corrupted");
    return false;
  }
  
  if (getUpdateDictionary(stmt, valuesDict, error) == false)
    return false;

  status = this->db->Put(leveldb::WriteOptions(), hashKey, valuesDict.toString());
  if(!status.ok()) {
    error.setMessage(status.ToString());
    return false;
  }
  
  return true;
}


bool uSQL::LevelDBProxy::remove(SQLStatement *stmt, SQLError &error)
{
  string hashKey;
  if (getKey(stmt, hashKey, error) == false)
    return false;

  Status status = this->db->Delete(leveldb::WriteOptions(), hashKey);
  if(!status.ok()) {
    error.setMessage(status.ToString());
    return false;
  }
  
  return true;
}

bool uSQL::LevelDBProxy::query(SQLStatement *stmt, SQLProxyResult &result) 
{
  result.clear();
  
  SQLCommand *sqlCmd = stmt->getCommandNode();
  
  if (!sqlCmd) {
    result.setErrorMessage("COMMAND section was not found");
    return false;
  }

  bool execResult = false;
  
  if (sqlCmd->isInsert()) {
    execResult = insert(stmt, result);
  }
  else if (sqlCmd->isSelect()) {
    execResult = select(stmt, result);
  }
  else if (sqlCmd->isDelete()) {
    execResult = remove(stmt, result);
  }
  else if (sqlCmd->isUpdate()) {
    execResult = update(stmt, result);
  }
  else {
    result.setErrorMessage("Invalid command");
  }
  
  return execResult;
}
