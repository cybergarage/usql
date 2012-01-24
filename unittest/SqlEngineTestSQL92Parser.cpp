/******************************************************************
*
* uSQL for C++
*
* SQLEngineTestGQLParser.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <cybergarage/sql/SQL92Parser.h>

#include "SqlEngineTestCase.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParser92Test)
{
	vector<string> sqlStrings;

    sqlStrings.push_back("SELECT * FROM SAMPLE1");
    sqlStrings.push_back("SELECT * FROM SAMPLE2 WHERE A = B");
    sqlStrings.push_back("SELECT * FROM SAMPLE3 LIMIT 10");

    sqlStrings.push_back("INSERT INTO abc VALUE 1234");
    sqlStrings.push_back("INSERT INTO abc ( value ) VALUE 1234");
    
	SQL92Parser sqlParser;
    SqlEngineTestCase sqlTestCase(&sqlParser);
    sqlTestCase.parse(sqlStrings);
}
