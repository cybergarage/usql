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

#include "LevelDBTest.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(LevelDbTest)
{
    const char *dbFilename = "/tmp/testdb";
    SQLProxyResult sqlResult;
    SQLProxyDataSet *sqlResultSet = sqlResult.getResultSet();
    
    boost::filesystem::remove_all(dbFilename);
    
    LevelDBTest levelDb;
    BOOST_CHECK(levelDb.open(dbFilename));

    // Empty
    
    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());
    
    BOOST_CHECK(levelDb.execSQLStatement("DELETE FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());
    
    BOOST_CHECK(!levelDb.execSQLStatement("UPDATE TESTDB SET NAME = \"TARO\", ADDR = \"TOKYO\" WHERE ID = 1", sqlResult));
    
    // 1
    
    BOOST_CHECK(levelDb.execSQLStatement("INSERT INTO TESTDB (ID) VALUES (1)", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());
    
    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(sqlResultSet->hasData());
    BOOST_CHECK(sqlResultSet->size() == 1);
    BOOST_CHECK(sqlResultSet->isValue("ID", "1"));
    
    BOOST_CHECK(levelDb.execSQLStatement("UPDATE TESTDB SET NAME = \"TARO\", ADDR = \"TOKYO\" WHERE ID = 1", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());

    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(sqlResultSet->hasData());
    BOOST_CHECK(sqlResultSet->size() == 3);
    BOOST_CHECK(sqlResultSet->isValue("ID", "1"));
    BOOST_CHECK(sqlResultSet->isValue("NAME", "TARO"));
    BOOST_CHECK(sqlResultSet->isValue("ADDR", "TOKYO"));
    
    // 1, 2

    BOOST_CHECK(levelDb.execSQLStatement("INSERT INTO TESTDB (ID) VALUES (2)", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());
    
    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 2", sqlResult));
    BOOST_CHECK(sqlResultSet->hasData());
    BOOST_CHECK(sqlResultSet->size() == 1);
    BOOST_CHECK(sqlResultSet->isValue("ID", "2"));
    
    BOOST_CHECK(levelDb.execSQLStatement("UPDATE TESTDB SET NAME = \"HANAKO\", ADDR = \"OSAKA\" WHERE ID = 2", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());

    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 2", sqlResult));
    BOOST_CHECK(sqlResultSet->hasData());
    BOOST_CHECK(sqlResultSet->size() == 3);
    BOOST_CHECK(sqlResultSet->isValue("ID", "2"));
    BOOST_CHECK(sqlResultSet->isValue("NAME", "HANAKO"));
    BOOST_CHECK(sqlResultSet->isValue("ADDR", "OSAKA"));

    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(sqlResultSet->hasData());
    BOOST_CHECK(sqlResultSet->size() == 3);
    BOOST_CHECK(sqlResultSet->isValue("ID", "1"));
    BOOST_CHECK(sqlResultSet->isValue("NAME", "TARO"));
    BOOST_CHECK(sqlResultSet->isValue("ADDR", "TOKYO"));
    
    // 2

    BOOST_CHECK(levelDb.execSQLStatement("DELETE FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());
    
    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());    

    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 2", sqlResult));
    BOOST_CHECK(sqlResultSet->hasData());
    BOOST_CHECK(sqlResultSet->size() == 3);
    BOOST_CHECK(sqlResultSet->isValue("ID", "2"));
    BOOST_CHECK(sqlResultSet->isValue("NAME", "HANAKO"));
    BOOST_CHECK(sqlResultSet->isValue("ADDR", "OSAKA"));
    
    // Empty

    BOOST_CHECK(levelDb.execSQLStatement("DELETE FROM TESTDB WHERE ID = 2", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());
    
    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 2", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());    

    BOOST_CHECK(levelDb.execSQLStatement("SELECT * FROM TESTDB WHERE ID = 1", sqlResult));
    BOOST_CHECK(!sqlResultSet->hasData());    
    
}