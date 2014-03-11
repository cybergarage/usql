/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLPROXY_H
#define CG_USQL_SQLPROXY_H

#include <string>
#include <usql/SQL92Parser.h>
#include "SQLProxyDataSet.h"
#include "SQLProxyResult.h"

namespace uSQL {

class SQLProxy {
  
private:
  
  std::string errorString;

private:

  bool getStatementKey(SQLStatement *stmt, std::string &key, SQLError &error);
  
public:

  SQLProxy();
  virtual ~SQLProxy();

  bool getKey(SQLCollection *collectionNode, SQLExpression *exprNode, std::string &key);
  bool getKey(SQLStatement *stmt, std::string &key, SQLError &error);
  
  bool getInsertDictionary(SQLStatement *stmt, SQLProxyDataSet &dictionary, SQLError &error);
  bool getUpdateDictionary(SQLStatement *stmt, SQLProxyDataSet &dictionary, SQLError &error);
  
  
  const char *getErrorMessage() {
    return errorString.c_str();
  }
  
  void trimSQLString(std::string &value);
  
public: 

  virtual bool connect(const std::string &host, const std::string &user, const std::string &passwd, const std::string &db) = 0;
  virtual bool query(SQLStatement *stmt, SQLProxyResult &result) = 0;
};

}

#endif
