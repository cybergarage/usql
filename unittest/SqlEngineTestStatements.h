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

#ifndef CG_USQL_TESTSTATEMENTS_H
#define CG_USQL_TESTSTATEMENTS_H

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
