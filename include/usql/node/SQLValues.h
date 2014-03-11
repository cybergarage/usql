/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLVALUES_H
#define CG_USQL_SQLVALUES_H

#include <usql/node/SQLExpression.h>

namespace uSQL {

class SQLValues : public SQLExpression {

public:

  SQLValues() {
    setType(VALUES);
  }
  
  const char *getTypeName() {
    return "SQLValues";
  }
  
  std::string &toString(std::string &buf);
};

}

#endif
