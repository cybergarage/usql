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
    
    std::string &getKey(SQLNode *dataSource, SQLWhere *sqlWhere, std::string &key);
    
    bool put(SQLStatement *stmt, SQLError &error);
    bool gut(SQLStatement *stmt, SQLError &error);

public:

	LevelDB();
    virtual ~LevelDB();

	bool open(const std::string &filename);
    bool execSQLStatement(SQLStatement *stmt, SQLError &error);
    
    const char *getErrorMessage() {
        return errorString.c_str();
    }
};

}

#endif
