/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#ifndef _USQL_ANTLR4_SQLLISTENER_H_
#define _USQL_ANTLR4_SQLLISTENER_H_

#include <usql/parser/antlr4/SQL92BaseListener.h>

namespace uSQL::ANTLR4 {

  class SQLListener : public SQL92BaseListener {
    
  public:
    
    SQLListener();
    ~SQLListener();
  };
  
}

#endif
