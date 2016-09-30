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

#include <usql/SQLParser.h>

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserStatementAddTest)
{
  SQLStatement sqlStmt;
  
  for (size_t n=0; n<100; n++) {
    SQLSelect *sqlCmd = new SQLSelect();
    sqlStmt.addChildNode(sqlCmd);
    //BOOST_CHECK(sqlStmt.numChildNodes() == (n+1));
  }
}
