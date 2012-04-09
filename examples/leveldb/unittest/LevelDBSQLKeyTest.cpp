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

#include "LevelDBProxy.h"

using namespace std;
using namespace uSQL;

#define SQLPROXYTEST_KEY_COUNT (sizeof(SQLPROXYTEST_KEY_INSERT)/sizeof(const char *))

static const char *SQLPROXYTEST_KEY_INSERT[] = {
"INSERT INTO TESTDB (ID) VALUES (1)",
"INSERT INTO TESTDB (ID, NAME) VALUES (1, \"TEST\")",
"INSERT INTO TESTDB (ID, NAME, ADDR) VALUES (1, \"TEST\", \"TOKYO\")"
};

static const char *SQLPROXYTEST_KEY_SELECT[] = {
"SELECT * FROM TESTDB WHERE ID = 1",
"SELECT * FROM TESTDB WHERE ID = 1",
"SELECT * FROM TESTDB WHERE ID = 1"
};

static const char *SQLPROXYTEST_KEY_DELETE[] = {
"DELETE FROM TESTDB WHERE ID = 1",
"DELETE FROM TESTDB WHERE ID = 1",
"DELETE FROM TESTDB WHERE ID = 1"
};

static const char *SQLPROXYTEST_KEY_UPDATE[] = {
"UPDATE TESTDB SET NAME = \"TEST\" WHERE ID = 1",
"UPDATE TESTDB SET NAME = \"TEST\" WHERE ID = 1",
"UPDATE TESTDB SET NAME = \"TEST\", ADDR = \"TOKYO\" WHERE ID = 1"
};

BOOST_AUTO_TEST_CASE(LevelDBSQLKeyTest)
{
    for (int i=0; i<SQLPROXYTEST_KEY_COUNT; i++) {
    
        vector<string> sqlStrings;
        vector<string> stmtKeys;
        
        sqlStrings.push_back(SQLPROXYTEST_KEY_INSERT[i]);
        sqlStrings.push_back(SQLPROXYTEST_KEY_SELECT[i]);
        sqlStrings.push_back(SQLPROXYTEST_KEY_DELETE[i]);
        sqlStrings.push_back(SQLPROXYTEST_KEY_UPDATE[i]);

        for (int j=0; j<sqlStrings.size(); j++) {
            string sqlString = sqlStrings.at(j);
            
            SQL92Parser sqlParser;
            BOOST_CHECK(sqlParser.parse(sqlString));
            BOOST_CHECK_EQUAL(sqlParser.getStatementCount(), 1);
            SQLStatement *stmt = sqlParser.getStatement(0);
            
            LevelDBProxy sqlProxy;
            SQLError sqlError;
            string stmtKey;
            string stmtBuf;
            BOOST_CHECK_MESSAGE(sqlProxy.getKey(stmt, stmtKey, sqlError), stmt->toString(stmtBuf) << ":" << sqlError.getMessage());
            BOOST_CHECK_MESSAGE((0 < stmtKey.length()), stmtKey);
            
            stmtKeys.push_back(stmtKey);
            
            cout << "[" << i << "]" << stmtKey << " : " << sqlString << endl;
            
        }

        string firstStmtKey = stmtKeys.at(0);
        for (int n=1; n<stmtKeys.size(); n++) {
            string stmtKey = stmtKeys.at(n);
            BOOST_CHECK_MESSAGE((firstStmtKey.compare(stmtKey) == 0), firstStmtKey << " != " << stmtKey);
        }
    }
}
