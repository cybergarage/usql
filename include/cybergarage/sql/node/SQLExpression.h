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

	std::string name;
	std::string value;
    
public:

	SQLExpression() {
    	setType(EXPRESSION);
    }
    
	~SQLExpression() {
    	setType(EXPRESSION);
    }
    
    bool isDictionary()
    {
    /*
    	if (isFunction() == true)
        	return false;
    	if (isOperator() == true)
        	return false;
    */
    	return (0 < name.length()) ? true : false;
    }
    
    bool isFunction()
    {
    	return (getType() == FUNCTION) ? true : false;
    }

    bool isOperator()
    {
    	return (getType() == OPERATOR) ? true : false;
    }
    
	void setName(const std::string &value) {
    	this->name = value;
    }
    
    const char *getName() {
    	return this->name.c_str();
    }
    
	void setValue(const std::string &value) {
    	this->value = value;
    }
    
    const char *getValue() {
    	return this->value.c_str();
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
    
    std::string &toString(std::string &buf);

};

}

#endif
