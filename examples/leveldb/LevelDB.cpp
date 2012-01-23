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

using namespace std;
using namespace uSQL;

uSQL::LevelDB::LevelDB()
{
}

uSQL::LevelDB::~LevelDB()
{
}

const char *uSQL::LevelDB::getKey(SQLNode *dataSource, SQLWhere *sqlWhere, std::string &key) 
{
    string tableName = dataSource->getValue();
    string whereString;
    sqlWhere->toString(whereString);
    
    key = tableName;
    key.append(whereString);
    
    return key.c_str();
}

bool uSQL::LevelDB::open(const std::string &filename)
{
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, filename, &this->db);    
    return status.ok();
}

bool uSQL::LevelDB::put(SQLStatement *stmt) 
{
    return true;
}

bool uSQL::LevelDB::gut(SQLStatement *stmt)
{
    return true;
}

bool uSQL::LevelDB::execSQLStatement(SQLStatement *stmt) 
{
    errorString = "";
    
    SQLCommand *sqlCmd = stmt->getCommandNode();
    if (!sqlCmd) {
        errorString = "COMMAND section was not found";
        return false;
    }
    
    if (!sqlCmd->isSelect() && !sqlCmd->isInsert() && !sqlCmd->isUpdate() && !sqlCmd->isDelete()) {
        errorString = "Invalid command";
        return false;
    }
    
    SQLFrom *sqlFrom = stmt->getFromNode();
    if (!sqlFrom) {
        errorString = "FROM section was not found";
        return false;
    }
    
    SQLNodeList *sqlDataSources = sqlFrom->getChildNodes();
    if (sqlDataSources->size() < 1) {
        errorString = "Data souce was not found";
        return false;
    }
    
    SQLNode *dataSource = sqlDataSources->at(0);
    string tablenName = dataSource->getValue();
    
    SQLWhere *sqlWhere = stmt->getWhereNode();
    if (!sqlWhere) {
        errorString = "WHERE section was not found";
        return false;
    }
    
    string levelDbKey;
    getKey(dataSource, sqlWhere, levelDbKey);
    
    cout << "Done." << endl;
    
    return true;
}