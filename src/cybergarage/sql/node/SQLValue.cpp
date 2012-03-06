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

std::string &uSQL::SQLValue::toString(std::string &buf) 
{
    bool isUnQL = false;
    if ((getRootNode()->isStatementNode())) {
        uSQL::SQLStatement *stmtNode = (uSQL::SQLStatement *)getRootNode();
        isUnQL = stmtNode->isUnQL();
    }
    
    std::string columnString;
    std::ostringstream oss;
    oss << (isUnQL ? "VALUE" : "VALUES") << " " << toExpressionString(columnString);
    buf = oss.str();
    return buf;
}
