/******************************************************************
*
* uSQL for C++
*
* SqlEngineTestCase.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <usql/SQLParser.h>

#include "SqlEngineTestCase.h"

using namespace std;
using namespace uSQL;

SqlEngineTestCase::SqlEngineTestCase(uSQL::SQLParser *sqlParser)
{
  this->sqlParser = sqlParser;
}

void SqlEngineTestCase::parse(std::vector<std::string> &sqlStrings)
{
  vector<string>::iterator sqlString = sqlStrings.begin();
  while(sqlString != sqlStrings.end()) {
    
    cout << "I : " << *sqlString << endl;
    
    BOOST_CHECK(sqlParser->parse(*sqlString));
    
    string parseResult;
    sqlParser->getStatement()->toString(parseResult);
    boost::trim(parseResult);
    
    int compareResult = parseResult.compare(*sqlString);
    BOOST_CHECK(compareResult == 0);

    if (compareResult != 0) {
      cout << "O : " << parseResult << endl;
      std::string buf;
      cout << sqlParser->getStatement()->toTreeString(buf);
    }
        
    sqlString++;
  }
}
