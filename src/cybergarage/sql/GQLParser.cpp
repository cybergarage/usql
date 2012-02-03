/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <antlr3.h>
#include <cybergarage/sql/GQLParser.h>

uSQL::GQLParser::GQLParser()
{
}

bool uSQL::GQLParser::parse(const std::string &queryString)
{
	bool parseResult = SQLParser::parse(queryString);
    setStatementType(uSQL::SQLStatement::GQL);
    return parseResult;
}
