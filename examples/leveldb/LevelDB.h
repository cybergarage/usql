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
#include <cybergarage/sql/UnQLParser.h>

namespace uSQL {

class LevelDB {
    
private:
    
    leveldb::DB* db;
    std::string errorString;
    
private:
    
    const char *getKey(SQLNode *dataSource, SQLWhere *sqlWhere, std::string &key);
    
    bool put(SQLStatement *stmt);
    bool gut(SQLStatement *stmt);

public:

	LevelDB();
    virtual ~LevelDB();

	bool open(const std::string &filename);
    bool execSQLStatement(SQLStatement *stmt);
    
    const char *getErrorMessage() {
        return errorString.c_str();
    }
};

}

#endif
