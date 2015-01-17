/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _USQL_GQLPARSER_H_
#define _USQL_GQLPARSER_H_

#include <usql/SQLParser.h>

namespace uSQL {

class GQLParser  : public SQLParser {

public:

  GQLParser();

  bool parse(const std::string &queryString);
};

}

#endif
