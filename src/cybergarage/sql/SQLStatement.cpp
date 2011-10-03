/******************************************************************
*
* uSQL for C++
*
* SQLStatement.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <sstream>
#include <cybergarage/sql/SQLStatement.h>

uSQL::SQLStatement::SQLStatement()
{
}

static void CgSQLStatementToString(std::ostringstream &oss, uSQL::SQLNode *node)
{
    std::string nodeStr;
    node->toString(nodeStr);
    
    if (0 < nodeStr.length()) {
	    oss << nodeStr;
	    oss << " ";
    }
    
    int numChildren = node->numChildNodes();
    for (int n=0; n<numChildren; n++)
    	CgSQLStatementToString(oss, node->getChildNode(n));
}

std::string &uSQL::SQLStatement::toString(std::string &buf)
{
    std::ostringstream oss;
    
    int numChildren = numChildNodes();
    for (int n=0; n<numChildren; n++)
    	CgSQLStatementToString(oss, getChildNode(n));
    
    buf = oss.str();
    
    return buf;
}
