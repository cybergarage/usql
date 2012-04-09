/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "MySQLProxy.h"

using namespace std;
using namespace uSQL;

uSQL::MySQLProxy::MySQLProxy()
{
    this->mySQL = mysql_init(NULL);
}

uSQL::MySQLProxy::~MySQLProxy()
{
    mysql_close(this->mySQL);
}

bool uSQL::MySQLProxy::connect(std::string &host, std::string &user, std::string &passwd, std::string &database)
{
    if (!mysql_real_connect(this->mySQL, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0))
        return false;
    return true;
}

bool uSQL::MySQLProxy::select(SQLStatement *stmt, SQLProxyResult &result) 
{
    string hashKey;
    if (getKey(stmt, hashKey, result) == false)
        return false;
/*
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
*/
    
    return true;
}

bool uSQL::MySQLProxy::insert(SQLStatement *stmt, SQLError &error) 
{
    string hashKey;
    if (getKey(stmt, hashKey, error) == false)
        return false;
        
    SQLProxyDataSet valuesDict;
    if (getInsertDictionary(stmt, valuesDict, error) == false)
        return false;

/*
    Status status = this->db->Put(leveldb::WriteOptions(), hashKey, valuesDict.toString());
    if(!status.ok()) {
        error.setMessage(status.ToString());
        return false;
    }
*/
    
    return true;
}

bool uSQL::MySQLProxy::update(SQLStatement *stmt, SQLError &error) 
{
    //Status status;
    
    string hashKey;
    if (getKey(stmt, hashKey, error) == false)
        return false;

/*
    std::string valuesString;
    status = this->db->Get(leveldb::ReadOptions(), hashKey, &valuesString);
    if(!status.ok()) {
        error.setMessage(status.ToString());
        return false;
    }
*/

/*    
    SQLProxyDataSet valuesDict;
    if (valuesDict.parse(valuesString) == false) {
        error.setMessage("Stored data was corrupted");
        return false;
    }
    if (getUpdateDictionary(stmt, valuesDict, error) == false)
        return false;
*/    

/*
    status = this->db->Put(leveldb::WriteOptions(), hashKey, valuesDict.toString());
    if(!status.ok()) {
        error.setMessage(status.ToString());
        return false;
    }
*/
    
    return true;
}


bool uSQL::MySQLProxy::remove(SQLStatement *stmt, SQLError &error)
{
    string hashKey;
    if (getKey(stmt, hashKey, error) == false)
        return false;

/*
    Status status = this->db->Delete(leveldb::WriteOptions(), hashKey);
    if(!status.ok()) {
        error.setMessage(status.ToString());
        return false;
    }
*/
    
    return true;
}

bool uSQL::MySQLProxy::query(SQLStatement *stmt, SQLProxyResult &result) 
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
