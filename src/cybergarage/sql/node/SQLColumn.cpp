/******************************************************************
*
* uSQL for C++
*
* SQLColumn.cpp
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/SQLStatement.h>
#include <cybergarage/sql/node/SQLValue.h>

std::string &uSQL::SQLColumn::toString(std::string &buf) 
{
    std::ostringstream oss;
    
    bool isUnQL = false;
    if ((getRootNode()->isStatementNode())) {
        uSQL::SQLStatement * stmtNode = (uSQL::SQLStatement *)getRootNode();
        isUnQL = stmtNode->isUnQL();
    }
    
    uSQL::SQLNodeList *expressions = getChildNodes();
	std::size_t expressionsCount = expressions->size();

	bool hasDictionaryValues = false;
    for (int n=0; n<expressionsCount; n++) {
        SQLNode *sqlNode = expressions->getNode(n);
	    if (sqlNode->isSQLExpressionNode() == false)
        	continue;
        uSQL::SQLExpression *exprNode = (uSQL::SQLExpression *)sqlNode;
    	if (exprNode->isDictionary() == true) {
        	hasDictionaryValues = true;
            break;
        }
    }
    
    if (isUnQL) {
        if (1 < expressionsCount)
            oss << (hasDictionaryValues ? "{" : "[");
        else {
            if (hasDictionaryValues == true)
                oss << "{";
        }
    } else {
        oss << "(";
    }
        
    std::string childNodeStr;
    oss << childNodesToString(childNodeStr, ",");
    
    
    if (isUnQL) {
        if (1 < expressionsCount)
            oss << (hasDictionaryValues ? "}" : "]");
        else {
            if (hasDictionaryValues == true)
                oss << "}";
        }
    } else {
        oss << ")";
    }
    
    buf = oss.str();
    
	return buf;
}
