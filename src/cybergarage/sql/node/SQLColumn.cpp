/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/SQLStatement.h>
#include <cybergarage/sql/node/SQLValue.h>

std::string &uSQL::SQLColumn::toString(std::string &buf) 
{
    return toExpressionString(buf);
}
