/******************************************************************
*
* uSQL for C++
*
* SqlEngineTestParser.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _USQL_TESTCASEPARSER_H_
#define _USQL_TESTCASEPARSER_H_

#include <usql/SQLParser.h>

class SqlEngineTestParser  : public uSQL::SQLParser {

public:

  SqlEngineTestParser() {
  }

  bool parse(const std::string &queryString) {
    return SQLParser::parse(queryString);
  }
};

#endif


