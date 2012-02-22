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
    
    /*
        if (unqlParser.parse(line) == false) {
            printf("Parser Error :  %s\n", line);
            continue;
        }
        
        SQLStatementList *stmtList = unqlParser.getStatements();
        for (SQLStatementList::iterator stmt = stmtList->begin(); stmt != stmtList->end(); stmt++) {
            SQLResult sqlResult;
            if (levelDb.execSQLStatement(*stmt, sqlResult) == true) {
                if (sqlResult.hasMessage())
                    cout << sqlResult.getExecMessage() << endl;
                cout << "Done." << endl;
            }
            else {
                OutputSQLError(sqlResult.getErrorMessage());
                continue;
            }
        }
    */
}