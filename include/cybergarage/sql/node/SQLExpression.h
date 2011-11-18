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
#include <cybergarage/sql/node/SQLExpressions.h>

namespace uSQL {

class SQLExpression : public SQLNode {

	std::string value;
    
    SQLExpressions expressions;
    
public:

	SQLExpression() {
    	setType(EXPRESSION);
    }
    
	~SQLExpression() {
    	setType(EXPRESSION);
    }
    
	void setValue(const std::string &value) {
    	this->value = value;
    }
    
    const char *getValue() {
    	return this->value.c_str();
    }
    
    void addExpression(SQLExpression *expr) {
        expressions.addExpression(expr);
    }
    
    SQLExpressions *getExpressions() {
        return &expressions;
    }
    
    std::string &toString(std::string &buf) {
    	buf = this->value;
        return buf;
    }


};

}

#endif
