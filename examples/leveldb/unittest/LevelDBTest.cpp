/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "LevelDBTest.h"

using namespace std;
using namespace uSQL;
using namespace leveldb;

uSQL::LevelDBTest::LevelDBTest()
{
}

uSQL::LevelDBTest::~LevelDBTest()
{
}

bool uSQL::LevelDBTest::execSQLStatement(const std::string &sqlString, SQLProxyResult &result)
{
    SQL92Parser sqlParser;
    if (sqlParser.parse(sqlString) == false)
        return false;
        
    SQLStatementList *stmtList = sqlParser.getStatements();
    for (SQLStatementList::iterator stmt = stmtList->begin(); stmt != stmtList->end(); stmt++) {
        if (LevelDB::execSQLStatement((*stmt), result) == false)
            return false;
    }

    return true;
}
