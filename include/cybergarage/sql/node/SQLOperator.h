/******************************************************************
*
* uSQL for C++
*
* SQLOperator.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLOPERATOR_H
#define CG_USQL_SQLOPERATOR_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLOperator : public SQLExpression {

    static const int UNKNOWN;
    static const int SEQ;
    static const int DEQ;
    static const int LT;
    static const int LE;
    static const int GT;
    static const int GE;
    static const int NOTEQ;
    static const int AND;
    static const int OR;

public:
	
    int value;

public:

	SQLOperator() {
    	setType(OPERATOR);
    }
    
    void setValue(int value) {
    	this->value = value;
    }

	int getValue() {
    	return this->value;
    }
    
    SQLExpression *getLeftExpression() {
    	return getExpression(0);
    }
        
    SQLExpression *getRightExpression() {
    	return getExpression(1);
    }

    std::string &toString(std::string &buf);
};

}

#endif
