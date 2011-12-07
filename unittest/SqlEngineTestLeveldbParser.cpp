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

#include <cybergarage/sql/UnQLParser.h>

#include "SqlEngineTestCase.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserLeveldbTest)
{
	vector<string> unqlStrings;
    
    unqlStrings.push_back("SELECT FROM /tmp/testdb");
    unqlStrings.push_back("SELECT FROM \"/tmp/testdb\"");
    unqlStrings.push_back("INSERT INTO /tmp/testdb VALUE {type:\"message\"}");
    unqlStrings.push_back("INSERT INTO \"/tmp/testdb\" VALUE {type:\"message\"}");

    UnQLParser unqlParser;
    SqlEngineTestCase sqlTestCase(&unqlParser);
    sqlTestCase.parse(unqlStrings);
}