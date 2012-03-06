/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <boost/test/unit_test.hpp>
#include <boost/filesystem.hpp>

#include <string>
#include <vector>

#include "LevelDB.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(LevelDBSQLInsertTest)
{
    const char *dbFilename = "/tmp/testdb";

    remove(dbFilename);
    
    LevelDB levelDb;
    BOOST_CHECK(levelDb.open(dbFilename));

    UnQLParser unqlParser;
    
    BOOST_CHECK(unqlParser.parse("INSERT INTO TESTDB (KEY) VALUES (1)"));
    
    SQLStatementList *stmtList = unqlParser.getStatements();
    for (SQLStatementList::iterator stmt = stmtList->begin(); stmt != stmtList->end(); stmt++) {
        SQLProxy sqlProxy;
        string key;
        SQLError sqlError;
        string stmtBuf;
        BOOST_CHECK_MESSAGE(sqlProxy.getKey(*stmt, key, sqlError), (*stmt)->toString(stmtBuf) << ":" << sqlError.getMessage());
    }
}