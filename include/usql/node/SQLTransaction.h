/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLTRANSACTION_H
#define CG_USQL_SQLTRANSACTION_H

#include <usql/SQLNode.h>

namespace uSQL {

class SQLTransaction : public SQLNode {

public:

  SQLTransaction() {
    setType(TRANSACTION);
  }

  const char *getTypeName() {
    return "SQLTransaction";
  }
  
};

}
#endif
