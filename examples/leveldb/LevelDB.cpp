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
using namespace leveldb;

uSQL::LevelDB::LevelDB()
{
}

uSQL::LevelDB::~LevelDB()
{
}

bool uSQL::LevelDB::open(const std::string &filename)
{
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, filename, &this->db);    
    return status.ok();
}

bool uSQL::LevelDB::select(SQLStatement *stmt, Dictionary &values, SQLResult &result) 
{
    string hashKey;
    if (getKey(stmt, hashKey, result) == false)
        return false;

    std::string valuesString;
    Status status = this->db->Get(leveldb::ReadOptions(), hashKey, &valuesString);
    if(!status.ok()) {
        result.setErrorMessage(status.ToString());
        return false;
    }
    
    if (values.parse(valuesString) == false) {
        result.setErrorMessage("Stored data was corrupted");
        return false;
    }
    
    return true;
}

bool uSQL::LevelDB::insert(SQLStatement *stmt, SQLError &error) 
{
    string hashKey;
    if (getKey(stmt, hashKey, error) == false)
        return false;
        
    Dictionary valuesDict;
    if (getInsertDictionary(stmt, valuesDict, error) == false)
        return false;

    Status status = this->db->Put(leveldb::WriteOptions(), hashKey, valuesDict.toString());
    if(!status.ok()) {
        error.setMessage(status.ToString());
        return false;
    }
    
    return true;
}

bool uSQL::LevelDB::update(SQLStatement *stmt, SQLError &error) 
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
    
    Dictionary valuesDict;
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


bool uSQL::LevelDB::remove(SQLStatement *stmt, SQLError &error)
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

bool uSQL::LevelDB::execSQLStatement(SQLStatement *stmt, SQLResult &result) 
{
    SQLCommand *sqlCmd = stmt->getCommandNode();
    
    if (!sqlCmd) {
        result.setErrorMessage("COMMAND section was not found");
        return false;
    }

    bool execResult = false;
    
    if (sqlCmd->isSelect()) {
    }
    else if (sqlCmd->isDelete()) {
        execResult = remove(stmt, result);
    }
    else {
        result.setErrorMessage("Invalid command");
    }
    
    return execResult;
}