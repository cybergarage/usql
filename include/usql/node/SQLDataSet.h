/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDATASET_H
#define CG_USQL_SQLDATASET_H

#include <usql/node/SQLExpression.h>

namespace uSQL {

class SQLDataSet : public SQLExpression {

public:

  SQLDataSet() {
  }

  virtual ~SQLDataSet() {
  }

};

}

#endif
