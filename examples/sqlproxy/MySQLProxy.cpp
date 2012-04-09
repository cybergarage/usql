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

static const char *USQL_MYSQL_PROXY_MEMCACHED_HOST = "localhost";

uSQL::MySQLProxy::MySQLProxy()
{
    this->mySQL = mysql_init(NULL);
}

uSQL::MySQLProxy::~MySQLProxy()
{
    mysql_close(this->mySQL);
}

bool uSQL::MySQLProxy::connect(const std::string &host, const std::string &user, const std::string &passwd, const std::string &database)
{
    if (!MemcachedProxy::connect(USQL_MYSQL_PROXY_MEMCACHED_HOST))
        return false;
    if (!mysql_real_connect(this->mySQL, host.c_str(), user.c_str(), passwd.c_str(), database.c_str(), 0, NULL, 0))
        return false;
    return true;
}

bool uSQL::MySQLProxy::execCommand(SQLStatement *stmt, SQLProxyResult &result) 
{
    string hashKey;
    if (getKey(stmt, hashKey, result)) {
        SQLError sqlError;
        MemcachedProxy::remove(stmt, result);
    }
    
    string stmtString;
    stmt->toString(stmtString);
    if (mysql_query(this->mySQL, stmtString.c_str()) != 0)
        return false;
        
    return true;
}

bool uSQL::MySQLProxy::select(SQLStatement *stmt, SQLProxyResult &result) 
{
    string hashKey;
    if (getKey(stmt, hashKey, result) == false)
        return false;

    if (MemcachedProxy::get(stmt, result)) {
        result.setCashed(true);
        return true;
    }
    
    string stmtString;
    stmt->toString(stmtString);
    if (mysql_query(this->mySQL, stmtString.c_str()) != 0)
        return false;

    bool selectlResult = false;

    MYSQL_RES *mySQLRes;
    if ((mySQLRes = mysql_store_result(this->mySQL))) {
        int numRows = mysql_num_rows(mySQLRes);
        if (0 < numRows) {
            MYSQL_FIELD *mySQLField;
            std::vector<std::string> keys;
            while ((mySQLField = mysql_fetch_field(mySQLRes)))
                keys.push_back(mySQLField->name);
            MYSQL_ROW mySQLRow = mysql_fetch_row(mySQLRes);
            if (mySQLRow) {
                SQLProxyDataSet *resultSet = result.getResultSet();
                int numFields = mysql_num_fields(mySQLRes);
                for (int n=0 ; n<numFields; n++) {
                    string key = keys.at(n);
                    resultSet->set(key, mySQLRow[n] ? mySQLRow[n] : "");
                }
                selectlResult = set(stmt, resultSet, result);
            }
        }
        mysql_free_result(mySQLRes) ;
    }
    
    return selectlResult;
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
    
    if (sqlCmd->isSelect()) {
        execResult = select(stmt, result);
    }
    else {
        execResult = execCommand(stmt, result);
    }
    
    return execResult;
}
