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
#include "SqlEngineTestStatements.h"
#include "SqlEngineTestParser.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLExpressionTest)
{
	SqlEngineTestStatements testStmts;

    testStmts.addStatement("SELECT * FROM A WHERE age == 18");
    testStmts.addStatement("SELECT * FROM A WHERE age = 18");
    testStmts.addStatement("SELECT * FROM A WHERE age < 18");
    testStmts.addStatement("SELECT * FROM A WHERE age <= 18");
    testStmts.addStatement("SELECT * FROM A WHERE age > 18");
    testStmts.addStatement("SELECT * FROM A WHERE age >= 18");
    testStmts.addStatement("SELECT * FROM A WHERE age != 18");
    
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 AND age <= 35");
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 OR age <= 35");
    
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 AND age <= 35 AND age <= 10");
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 OR age <= 35 OR age <= 10");
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 AND age <= 35 OR age <= 10");
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 OR age <= 35 AND age <= 10");
    
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 AND age <= 35 AND age <= 10 AND age >= 5");
    testStmts.addStatement("SELECT * FROM Person WHERE age >= 18 OR age <= 35 OR age <= 10 OR age >= 5");
    
	SqlEngineTestParser testParser;
    SqlEngineTestCase sqlTestCase(&testParser);
    sqlTestCase.parse(testStmts);
}
