/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#ifndef _USQL_ANTLR4_SQLPARSER_H_
#define _USQL_ANTLR4_SQLPARSER_H_

#include <usql/parser/antlr4/SQL92Parser.h>

namespace uSQL::ANTLR4 {

  class SQLParser {
    
  public:
    
    SQLParser();
    virtual ~SQLParser();
  };
  
}

#endif
