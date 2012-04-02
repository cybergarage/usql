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
    
    remove(dbFilename);
    
    LevelDBTest levelDb;
    BOOST_CHECK(levelDb.open(dbFilename));

    BOOST_CHECK(levelDb.execSQLStatement("INSERT INTO TESTDB (ID) VALUES (1)", sqlResult));
}