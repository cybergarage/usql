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

#ifndef CG_USQL_TESTCASEPARSER_H
#define CG_USQL_TESTCASEPARSER_H

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


