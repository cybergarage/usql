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

#ifndef CG_USQL_TESTCASE_H
#define CG_USQL_TESTCASE_H

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
