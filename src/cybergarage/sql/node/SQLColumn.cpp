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

std::string &uSQL::SQLColumn::toString(std::string &buf) 
{
    std::ostringstream oss;
    
    bool isUnQL = isUnQLNode();
    
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
    
    bool isAsterisk = false;
    if (1 == expressionsCount) {
        SQLNode *sqlNode = expressions->getNode(0);
	    if (sqlNode->isSQLExpressionNode() == true) {
            uSQL::SQLExpression *exprNode = (uSQL::SQLExpression *)sqlNode;
            isAsterisk = exprNode->isAsterisk();
        }
    }
    
    if (isUnQL) {
        if (1 < expressionsCount) {
            if (isAsterisk == false)
                oss << (hasDictionaryValues ? "{" : "[");
        }
        else {
            if (hasDictionaryValues == true)
                oss << "{";
        }
    } else {
        if (isAsterisk == false)
            oss << "(";
    }
        
    std::string childNodeStr;
    oss << childNodesToString(childNodeStr, ",");
    
    
    if (isUnQL) {
        if (1 < expressionsCount) {
            if (isAsterisk == false)
                oss << (hasDictionaryValues ? "}" : "]");
        }
        else {
            if (hasDictionaryValues == true)
                oss << "}";
        }
    } else {
        if (isAsterisk == false)
            oss << ")";
    }
    
    buf = oss.str();
    
	return buf;
}
