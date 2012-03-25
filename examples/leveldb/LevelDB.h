/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_LEVELDB_H
#define CG_USQL_LEVELDB_H

#include <string>
#include <leveldb/db.h>
#include "SQLProxy.h"
#include "SQLProxyResult.h"

namespace uSQL {

class LevelDB : public SQLProxy {
    
private:
    
    leveldb::DB* db;
    
private:
    
    bool select(SQLStatement *stmt, SQLProxyDataSet &values, SQLProxyResult &result);
    bool insert(SQLStatement *stmt, SQLError &error);
    bool update(SQLStatement *stmt, SQLError &error);
    bool remove(SQLStatement *stmt, SQLError &error);
    bool execSQLStatement(SQLStatement *stmt, SQLProxyResult &result);

public:

	LevelDB();
    virtual ~LevelDB();

	bool open(const std::string &filename);
	bool execSQLStatement(const std::string &sqlString, SQLProxyResult &result);
};

}

#endif
