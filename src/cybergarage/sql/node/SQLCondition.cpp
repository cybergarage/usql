/******************************************************************
*
* uSQL for C++
*
* SQLCondition.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLCondition.h>

const int uSQL::SQLCondition::UNKOWN = -1;
const int uSQL::SQLCondition::EQ = 0;
const int uSQL::SQLCondition::LT = 1;
const int uSQL::SQLCondition::LE = 2;
const int uSQL::SQLCondition::GT = 3;
const int uSQL::SQLCondition::GE = 4;
const int uSQL::SQLCondition::NOTEQ = 5;

static const char *CgSQLConditionStrings[] = {
"=",
"<",
"<=",
">",
">=",
"!=",
};

#define CgSQLConditionStringSize (sizeof(CgSQLConditionStrings)/sizeof(CgSQLConditionStrings[0]))

static const char *CgSQLStatementValueToString(int n)
{
	if (n < 0 || (CgSQLConditionStringSize - 1) < n)
    	return "?";
	return CgSQLConditionStrings[n];
}

static int CgSQLStatementStringToValue(const std::string &value)
{
	for (int n=0; n<CgSQLConditionStringSize; n++) {
    	if (value.compare(CgSQLConditionStrings[n]) == 0)
        	return n;
    }
    return uSQL::SQLCondition::UNKOWN;
}

void uSQL::SQLCondition::setOperation(const std::string &value)
{
	setOperation(CgSQLStatementStringToValue(value));
}

std::string &uSQL::SQLCondition::toString(std::string &buf) 
{
	buf = this->name;
    buf.append(" ");
    buf.append(CgSQLStatementValueToString(getOperation()));
    buf.append(" ");
	buf.append(this->value);
    return buf;
}
    

