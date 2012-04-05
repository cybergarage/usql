/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLDictionary.h>

uSQL::SQLDictionary::~SQLDictionary()
{
}

std::string &uSQL::SQLDictionary::toString(std::string &buf) 
{
    std::ostringstream oss;
    
    oss << name;

    SQLNode *parentNode = getParentNode();
    oss << ((isUnQLNode() && (parentNode->isColumnsNode() || parentNode->isValuesNode())) ? ":" : " = ");

    std::string valueString;
    oss << SQLExpression::toString(valueString);
    
    buf = oss.str();
    
    return buf;
}
