/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "SQLProxy.h"
#include "MD5.h"
#include "SQLProxyDataSet.h"

using namespace std;
using namespace uSQL;

uSQL::SQLProxy::SQLProxy()
{
}

uSQL::SQLProxy::~SQLProxy()
{
}

bool uSQL::SQLProxy::getKey(SQLCollection *collectionNode, SQLExpression *exprNode, std::string &key) 
{
    string keyString;
    
    string tableName = collectionNode->getValue();
    keyString = tableName;

    string exprString;
    exprNode->toString(exprString);
    keyString.append(exprString);
    
    MD5::hash(keyString, key);

    return true;
}

bool uSQL::SQLProxy::getInsertStatementKey(SQLStatement *stmt, std::string &key, SQLError &error) 
{
    SQLCollection *collectionNode = stmt->getCollectionNode();
    if (!collectionNode) {
        error.setMessage("Collection was not found");
        return false;
    }

    SQLColumn *sqlColumns = stmt->getColumnNode();
    if (!sqlColumns) {
        error.setMessage("COLUMN section was not found");
        return false;
    }
    SQLNode *sqlColumn = sqlColumns->getChildNode(0);
    if (!sqlColumn) {
        error.setMessage("Key column was not found");
        return false;
    }
    
    SQLValue *sqlValues = stmt->getValueNode();
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
    
    return getKey(collectionNode, &exprNode, key);
}

bool uSQL::SQLProxy::getStatementKey(SQLStatement *stmt, std::string &key, SQLError &error) 
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

    return getKey(dataSource, exprNode, key);
}

bool uSQL::SQLProxy::getKey(SQLStatement *stmt, std::string &key, SQLError &error) 
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


bool uSQL::SQLProxy::getInsertDictionary(SQLStatement *stmt, SQLProxyDataSet &dictionary, SQLError &error)
{
    SQLColumn *sqlColumn = stmt->getColumnNode();
    if (!sqlColumn) {
        error.setMessage("Column section was not found");
        return false;
    }

    SQLValue *sqlValue = stmt->getValueNode();
    if (!sqlValue) {
        error.setMessage("VALUES section was not found");
        return false;
    }

    SQLNodeList *sqlColums = sqlColumn->getChildNodes();
    SQLNodeList *sqlValues = sqlValue->getChildNodes();
    
    if (sqlColums->size() != sqlValues->size()) {
        error.setMessage("List of values less than number of Columns");
        return false;
    }
    
    size_t columsCount = sqlColums->size();
    for (size_t n=0; n<columsCount; n++) {
        SQLNode *colum = sqlColums->getNode(n); 
        SQLNode *value = sqlValues->getNode(n);
        dictionary.set(colum->toString(), value->toString());
    }
    
    return true;
}

bool uSQL::SQLProxy::getUpdateDictionary(SQLStatement *stmt, SQLProxyDataSet &dictionary, SQLError &error)
{
    SQLSet *sqlSet = stmt->getSetNode();
    if (!sqlSet) {
        error.setMessage("Set section was not found");
        return false;
    }

    int dictCount = sqlSet->getDictionaryCount();
    for (int n=0; n<dictCount; n++) {
        SQLDictionary *dict = sqlSet->getDictionary(n);
        string keyName = dict->getName();
        string keyValue;
        dict->getValue()->toString(keyValue);
        dictionary.set(keyName, keyValue);
    }
    
    return true;
}
