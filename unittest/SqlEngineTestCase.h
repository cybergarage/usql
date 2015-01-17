/******************************************************************
*
* uSQL for C++
*
* SqlEngineTestCase.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _USQL_TESTCASE_H_
#define _USQL_TESTCASE_H_

#include <string>
#include <vector>

#include <usql/SQLParser.h>

class SqlEngineTestCase {

  uSQL::SQLParser *sqlParser;
  
public:

  SqlEngineTestCase(uSQL::SQLParser *sqlParser);
  
  void parse(std::vector<std::string> &sqlStrings);
};

#endif
