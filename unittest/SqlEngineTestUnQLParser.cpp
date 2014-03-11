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

#include <usql/UnQLParser.h>

#include "SqlEngineTestCase.h"

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserUnQLTest)
{
  vector<string> unqlStrings;
  
  unqlStrings.push_back("CREATE COLLECTION abc");
  unqlStrings.push_back("CREATE COLLECTION def");
  
  unqlStrings.push_back("DROP COLLECTION abc");
  unqlStrings.push_back("DROP COLLECTION def");

  unqlStrings.push_back("CREATE INDEX abc");
  unqlStrings.push_back("CREATE INDEX def");
  
  unqlStrings.push_back("DROP INDEX abc");
  unqlStrings.push_back("DROP INDEX def");
  
  unqlStrings.push_back("INSERT INTO abc VALUE 1234");
  unqlStrings.push_back("INSERT INTO abc VALUE 3.141592653");
  unqlStrings.push_back("INSERT INTO abc VALUE \"This is a string\"");
  unqlStrings.push_back("INSERT INTO abc VALUE [\"this\",\"is\",\"an\",\"array\"]");
  unqlStrings.push_back("INSERT INTO abc VALUE {type:\"message\",content:\"This is an object\"}");
  
  unqlStrings.push_back("SELECT FROM abc");
  unqlStrings.push_back("SELECT a FROM abc");
  unqlStrings.push_back("SELECT MAX(a) FROM abc");
  unqlStrings.push_back("SELECT {x:abc.type,y:abc.content.x,z:abc.content.x} FROM abc");
  //unqlStrings.push_back("SELECT { x:abc.type,y:abc.content.x,z:abc.content.x+50 } FROM abc");
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\"");
  
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" GROUP BY abc.name");
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" GROUP BY abc.name,abc.date");
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" GROUP BY abc.name,abc.date HAVING abc.type");
  
  
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" ORDER BY abc.name ASC");
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" ORDER BY abc.name DESC");
  //unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" ORDER BY abc.name ASC, abc.type ASC");
  //unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" ORDER BY abc.name DESC, abc.type ASC");

  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" LIMIT 10");
  unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" LIMIT 0,10");
  //unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" OFFSET 10");
  //unqlStrings.push_back("SELECT FROM abc WHERE abc.type == \"message\" LIMIT 0,10 OFFSET 10");

  unqlStrings.push_back("UPDATE abc SET abc.type = \"message\"");
  unqlStrings.push_back("UPDATE abc SET abc.id = \"0123456789\",abc.type = \"message\"");
  
  unqlStrings.push_back("DELETE FROM abc");
  unqlStrings.push_back("DELETE FROM abc WHERE abc == 1234");
  
  UnQLParser unqlParser;
  SqlEngineTestCase sqlTestCase(&unqlParser);
  sqlTestCase.parse(unqlStrings);
}
