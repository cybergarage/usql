/******************************************************************
*
* uSQL for C++
*
* SQL92Parser.cpp
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <antlr3.h>
#include <cybergarage/sql/SQL92Parser.h>

uSQL::SQL92Parser::SQL92Parser()
{
}

bool uSQL::SQL92Parser::parse(const std::string &queryString)
{
	return SQLParser::parse(queryString);
}
