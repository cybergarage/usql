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

std::string &uSQL::SQLStatement::toString(std::string &buf)
{
    std::ostringstream oss;
    
    uSQL::SQLNodeList *childNodes = getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++) {
        uSQL::SQLNode *childNode = childNodes->getNode(n);
        std::string childNodeStr;
        childNode->toString(childNodeStr);
        if (0 < childNodeStr.length()) {
            oss << childNodeStr;
            oss << " ";
        }
    }
    
    buf = oss.str();
    
    return buf;
}

#if defined(DEBUG)

static void CgSQLStatementPrintTree(std::ostringstream &oss, uSQL::SQLNode *node, int indent)
{
    for (int n=0; n<indent; n++)
        oss << "| ";
    std::string buf;
    oss << "|-- " << node->toString(buf) << " ("<< node->getType() << ")" << std::endl;
    
    uSQL::SQLNodeList *childNodes = node->getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++)
    	CgSQLStatementPrintTree(oss, childNodes->getNode(n), (indent+1));
}

std::string &uSQL::SQLStatement::toTreeString(std::string &buf)
{
    std::ostringstream oss;
    
    uSQL::SQLNodeList *childNodes = getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++)
    	CgSQLStatementPrintTree(oss, childNodes->getNode(n), 0);

    buf = oss.str();
    
    return buf;
}

#endif
