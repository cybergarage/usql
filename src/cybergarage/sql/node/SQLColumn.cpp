/******************************************************************
*
* uSQL for C++
*
* SQLColumn.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLValue.h>

std::string &uSQL::SQLColumn::toString(std::string &buf) 
{
    std::ostringstream oss;
    
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
    
    if (1 < expressionsCount)
    	oss << (hasDictionaryValues ? "{" : "[");
	else {
    	if (hasDictionaryValues == true)
    		oss << "{";
    }
        
    std::string childNodeStr;
    oss << childNodesToString(childNodeStr, ",");
    
    if (1 < expressionsCount)
        oss << (hasDictionaryValues ? "}" : "]");
	else {
    	if (hasDictionaryValues == true)
			oss << "}";
    }
        
    buf = oss.str();
    
	return buf;
}
