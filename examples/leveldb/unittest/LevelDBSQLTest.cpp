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

BOOST_AUTO_TEST_CASE(LevelDbTest)
{
    const char *dbFilename = "/tmp/testdb";

    remove(dbFilename);
    
    LevelDB levelDb;
    BOOST_CHECK(levelDb.open(dbFilename));
}