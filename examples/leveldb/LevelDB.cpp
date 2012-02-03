/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "LevelDB.h"
#include "MD5.h"
#include "Dictionary.h"

using namespace std;
using namespace uSQL;

uSQL::LevelDB::LevelDB()
{
}

uSQL::LevelDB::~LevelDB()
{
}

std::string &uSQL::LevelDB::getKey(SQLNode *dataSource, SQLWhere *sqlWhere, std::string &key) 
{
    string tableName = dataSource->getValue();
    string whereString;
    sqlWhere->toString(whereString);
    
    string keyString;
    keyString = tableName;
    keyString.append(whereString);
    
    return MD5::hash(keyString, key);
}

bool uSQL::LevelDB::open(const std::string &filename)
{
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, filename, &this->db);    
    return status.ok();
}

bool uSQL::LevelDB::put(SQLStatement *stmt, SQLError &error) 
{
    error.setMessage("List of values less than number of Columns");
    
    return true;
}

bool uSQL::LevelDB::gut(SQLStatement *stmt, SQLError &error)
{
    return true;
}

bool uSQL::LevelDB::execSQLStatement(SQLStatement *stmt, SQLError &error) 
{
    SQLCommand *sqlCmd = stmt->getCommandNode();
    
    if (!sqlCmd) {
        error.setMessage("COMMAND section was not found");
        return false;
    }
    
    if (!sqlCmd->isSelect() && !sqlCmd->isInsert() && !sqlCmd->isUpdate() && !sqlCmd->isDelete()) {
        error.setMessage("Invalid command");
        return false;
    }
    
    SQLFrom *sqlFrom = stmt->getFromNode();
    if (!sqlFrom) {
        error.setMessage("FROM section was not found");
        return false;
    }
    
    SQLNodeList *sqlDataSources = sqlFrom->getChildNodes();
    if (sqlDataSources->size() < 1) {
        error.setMessage("Data souce was not found");
        return false;
    }
    
    SQLNode *dataSource = sqlDataSources->at(0);
    string tablenName = dataSource->getValue();
    
    SQLWhere *sqlWhere = stmt->getWhereNode();
    if (!sqlWhere) {
        error.setMessage("WHERE section was not found");
        return false;
    }
    
    string hashKey;
    getKey(dataSource, sqlWhere, hashKey);
    
    cout << "Done." << endl;
    
    return true;
}