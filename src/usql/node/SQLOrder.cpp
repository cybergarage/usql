/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <usql/node/SQLOrder.h>

const int uSQL::SQLOrder::UNKOWN = -1;
const int uSQL::SQLOrder::ASC = 0;
const int uSQL::SQLOrder::DESC = 1;

static const char *CgSQLOrderStrings[] = {
"ASC",
"DESC",
};

#define CgSQLOrderStringSize (sizeof(CgSQLOrderStrings)/sizeof(CgSQLOrderStrings[0]))

static const char *CgSQLOrderValueToString(int n)
{
	if (n < 0 || (CgSQLOrderStringSize - 1) < n)
    	return "?";
	return CgSQLOrderStrings[n];
}

static int CgSQLOrderStringToValue(const std::string value)
{
	for (int n=0; n<CgSQLOrderStringSize; n++) {
    	if (value.compare(CgSQLOrderStrings[n]) == 0)
        	return n;
    }
    return uSQL::SQLOrder::UNKOWN;
}

void uSQL::SQLOrder::setOrder(int type) 
{
    this->order = type;
}

void uSQL::SQLOrder::setOrder(const std::string &order)
{
	setOrder(CgSQLOrderStringToValue(order));
}

std::string &uSQL::SQLOrder::toString(std::string &buf) 
{
	std::ostringstream oss;
	oss << getValue() << " " << CgSQLOrderValueToString(getOrder());
	buf = oss.str();
	return buf;
}
