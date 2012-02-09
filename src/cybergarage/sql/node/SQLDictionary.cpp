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
    if (this->value)
        delete this->value;
}

std::string &uSQL::SQLDictionary::toString(std::string &buf) 
{
    std::string valueString;
    std::ostringstream oss;
    oss << name << " = " << value->toString(valueString);
    buf = oss.str();
    return buf;
}
