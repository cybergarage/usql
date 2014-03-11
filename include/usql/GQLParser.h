/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_GQLPARSER_H
#define CG_USQL_GQLPARSER_H

#include <usql/SQLParser.h>

namespace uSQL {

class GQLParser  : public SQLParser {

public:

  GQLParser();

  bool parse(const std::string &queryString);
};

}

#endif
