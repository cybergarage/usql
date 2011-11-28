/******************************************************************
*
* uSQL for C++
*
* SQLExpression.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLEXPRESSION_H
#define CG_USQL_SQLEXPRESSION_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLExpression : public SQLNode {

public:

	SQLExpression() {
    	setType(EXPRESSION);
    }
    
	~SQLExpression() {
    	setType(EXPRESSION);
    }
        
    bool isFunction()
    {
    	return (getType() == FUNCTION) ? true : false;
    }

    bool isOperator()
    {
    	return (getType() == OPERATOR) ? true : false;
    }
    
    void addExpression(SQLExpression *expr) {
        addChildNode(expr);
    }
    
    SQLNodeList *getExpressions() {
        return getChildNodes();
    }
    
    SQLExpression *getExpression(int n) {
        SQLNodeList *expressions = getExpressions();
    	if ((expressions->size() - 1) < n)
        	return NULL;
        return (SQLExpression *)expressions->at(n);
    }
    
    bool hasExpressions() {
        SQLNodeList *expressions = getExpressions();
        return (0 < expressions->size()) ? true : false;
    }
};

}

#endif
