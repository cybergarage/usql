/******************************************************************
*
* uSQL for C++
*
* SQLParser.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLPARSER_H
#define CG_USQL_SQLPARSER_H

#include <string>

namespace uSQL {

class SQLParser {

public:

	SQLParser();

	virtual bool parse(const std::string &queryString) = 0;
};

}

#endif
