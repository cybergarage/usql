/******************************************************************
*
* uSQL for C++
*
* SQLExpression.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLExpression.h>

const int uSQL::SQLExpression::UNKOWN = -1;
const int uSQL::SQLExpression::STRING = 1;
const int uSQL::SQLExpression::PROPERTY = 2;
const int uSQL::SQLExpression::INTEGER = 3;
const int uSQL::SQLExpression::REAL = 4;
const int uSQL::SQLExpression::BOOLEAN = 5;
const int uSQL::SQLExpression::OPERATOR = 6;
const int uSQL::SQLExpression::FUNCTION = 7;
const int uSQL::SQLExpression::SELECT = 8;
const int uSQL::SQLExpression::BLOB = 9;
const int uSQL::SQLExpression::NIL = 10;
const int uSQL::SQLExpression::CURRENT_TIME = 11;
const int uSQL::SQLExpression::CURRENT_DATE = 12;
const int uSQL::SQLExpression::CURRENT_TIMESTAMP = 13;
const int uSQL::SQLExpression::ASTERISK = 14;

void uSQL::SQLExpression::setLiteralType(int type)
{
    this->literalType = type;
    
    switch (this->literalType) {
    case NIL:
    	setValue("NULL");
        break;
	}
}

uSQL::SQLExpression *uSQL::SQLExpression::getExpression(int n) 
{
    uSQL::SQLNodeList *expressions = getExpressions();
    int expressionCnt = (int)expressions->size();
    if ((expressionCnt - 1) < n)
        return NULL;
    return (uSQL::SQLExpression *)expressions->at(n);
}

