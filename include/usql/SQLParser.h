/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _USQL_SQLPARSER_H_
#define _USQL_SQLPARSER_H_

#include <string>
#include <vector>
#include <stack>

#include <usql/SQLError.h>
#include <usql/SQLStatement.h>
#include <usql/SQLNode.h>
#include <usql/SQLNodes.h>

namespace uSQL {

class SQLParser {

private:

  SQLStatementList statements;
  SQLError error;
  
private:

  void clear();

public:

  SQLParser();
  
  virtual ~SQLParser();

  virtual bool parse(const std::string &queryString);
  
  void setStatementType(int type);
  
  void addStatement(SQLStatement *stmt)
  {
    statements.push_back(stmt);
  }

  int getStatementCount() {
    return (int)statements.size();
  }
  
  SQLStatement *getStatement(size_t n)
  {
    if ((statements.size()-1) < n)
      return NULL;
    return statements.at(n);
  }
  
  SQLStatement *getStatement()
  {
    return getStatement(0);
  }

  SQLStatementList *getStatements()
  {
    return &statements;
  }

  SQLError *getError()
  {
    return &error;
  }
};

}

#endif
