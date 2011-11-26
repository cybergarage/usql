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
    
    uSQL::SQLNodeList *childNodes = node->getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++)
    	CgSQLStatementToString(oss, childNodes->getNode(n));
}

std::string &uSQL::SQLStatement::toString(std::string &buf)
{
    std::ostringstream oss;
    
    uSQL::SQLNodeList *childNodes = getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++)
    	CgSQLStatementToString(oss, childNodes->getNode(n));
    
    buf = oss.str();
    
    return buf;
}
