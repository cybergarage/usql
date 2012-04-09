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

    bool execCommand(SQLStatement *stmt, SQLProxyResult &result);
    bool select(SQLStatement *stmt, SQLProxyResult &result);

public:

	MySQLProxy();
    virtual ~MySQLProxy();
    
    bool connect(const std::string &host, const std::string &user, const std::string &passwd, const std::string &db);
    bool close();
    
    bool query(SQLStatement *stmt, SQLProxyResult &result);
};

}

#endif
