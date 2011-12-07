/******************************************************************
*
* uSQL for C++
*
* GQLParser.cpp
*
* Copyright (C) Satoshi Konno 2011
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
	return SQLParser::parse(queryString);
}
