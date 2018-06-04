/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <strstream>

#include <usql/platform.h>
#include <usql/SQLParser.h>
#include <usql/parser/antlr/SQLLexer.h>
#include <usql/parser/antlr/SQLParser.h>

uSQL::SQLParser::SQLParser()
{
}

uSQL::SQLParser::~SQLParser()
{
  clear();
}

void uSQL::SQLParser::setStatementType(int type)
{
  for (std::vector<SQLStatement *>::iterator stmt = statements.begin(); stmt != statements.end(); stmt++)
    (*stmt)->setStatementType(type);
}

void uSQL::SQLParser::clear()
{
  for (std::vector<SQLStatement *>::iterator stmt = statements.begin(); stmt != statements.end(); stmt++)
    delete *stmt;
  this->statements.clear();
  this->error.clear();
}

bool uSQL::SQLParser::parse(const std::string &queryString)
{
  clear();
  return false;
}
