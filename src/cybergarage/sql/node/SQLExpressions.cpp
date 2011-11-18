/******************************************************************
*
* uSQL for C++
*
* ~SQLExpressions.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLExpression.h>
#include <cybergarage/sql/node/SQLExpressions.h>

uSQL::SQLExpressions::~SQLExpressions() 
{
    for (SQLExpressions::iterator expr=begin(); expr != end(); expr++) {
        delete (*expr);
    }
}
