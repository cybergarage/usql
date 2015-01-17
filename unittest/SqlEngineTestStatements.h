/******************************************************************
*
* uSQL for C++
*
* SqlEngineTestStatements.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _USQL_TESTSTATEMENTS_H_
#define _USQL_TESTSTATEMENTS_H_

#include <string>
#include <vector>

class SqlEngineTestStatements : public std::vector<std::string> {

public:

  SqlEngineTestStatements() {
  }
  
  void addStatement(const char *stmt) {
    push_back(stmt);
  }
};

#endif
