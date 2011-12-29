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

#include <cybergarage/sql/GQLParser.h>

#include "SqlEngineTestCase.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(GQLParserTest)
{
	vector<string> gqlStrings;

    gqlStrings.push_back("SELECT * FROM SAMPLE1");
    gqlStrings.push_back("SELECT * FROM SAMPLE2 WHERE A = B");
    gqlStrings.push_back("SELECT * FROM SAMPLE3 LIMIT 10");
    
	GQLParser gqlParser;
    SqlEngineTestCase sqlTestCase(&gqlParser);
    sqlTestCase.parse(gqlStrings);
}

BOOST_AUTO_TEST_CASE(GQLReferenceExamplesTest)
{
	vector<string> gqlStrings;

    /* GQL Reference Examples http://code.google.com/appengine/docs/python/datastore/gqlreference.html#Examples */
    //gqlStrings.push_back("SELECT * FROM Person WHERE age >= 18 AND age <= 35");
    /*
    gqlStrings.push_back("SELECT * FROM Person ORDER BY age DESC LIMIT 3");
    gqlStrings.push_back("SELECT * FROM Person WHERE name IN ('Betty', 'Charlie')");
    gqlStrings.push_back("SELECT __key__ FROM Person WHERE age=NULL");
    gqlStrings.push_back("SELECT * WHERE ANCESTOR IS KEY('Person', 'Amy')");
	*/
        
	GQLParser gqlParser;
    SqlEngineTestCase sqlTestCase(&gqlParser);
    sqlTestCase.parse(gqlStrings);
}