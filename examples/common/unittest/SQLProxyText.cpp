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

#define SQLPROXYTEST_KEY_COUNT (sizeof(SQLPROXYTEST_KEY_INSERT)/sizeof(const char *))

static const char *SQLPROXYTEST_KEY_INSERT[] = {
"INSERT INTO TESTDB (KEY) VALUES (1)"
};

BOOST_AUTO_TEST_CASE(SQLProxyKeyTest)
{
    for (int n=0; n<SQLPROXYTEST_KEY_COUNT; n++) {
    
        SQL92Parser sqlParser;
    
        BOOST_CHECK(sqlParser.parse("INSERT INTO TESTDB (KEY) VALUES (1)"));
        BOOST_CHECK_EQUAL(sqlParser.getStatementCount(), 1);
        
        SQLStatement *stmt = sqlParser.getStatement(0);

        SQLProxy sqlProxy;
        string stmtKey;
        SQLError sqlError;
        string stmtBuf;
        
        BOOST_CHECK_MESSAGE(sqlProxy.getKey(stmt, stmtKey, sqlError), stmt->toString(stmtBuf) << ":" << sqlError.getMessage());
        BOOST_CHECK_MESSAGE((0 < stmtKey.length()), stmtKey);
    }
}
