/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_MYSQLPROXY_H
#define CG_USQL_MYSQLPROXY_H

#include <string>
#include <mysql/mysql.h>

#include "MemcachedProxy.h"

namespace uSQL {

class MySQLProxy : public MemcachedProxy {

    MYSQL *mySQL;

private:

    bool select(SQLStatement *stmt, SQLProxyResult &result);
    bool insert(SQLStatement *stmt, SQLError &error);
    bool update(SQLStatement *stmt, SQLError &error);
    bool remove(SQLStatement *stmt, SQLError &error);

public:

	MySQLProxy();
    virtual ~MySQLProxy();
    
    bool connect(std::string &host, std::string &user, std::string &passwd, std::string &db);
    bool close();
    
    bool query(SQLStatement *stmt, SQLProxyResult &result);
};

}

#endif
