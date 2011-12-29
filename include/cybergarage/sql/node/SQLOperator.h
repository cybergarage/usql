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

    bool isSEQ() {
    	return (this->value == SEQ) ? true : false;
    }
    
    bool isDEQ() {
    	return (this->value == DEQ) ? true : false;
    }
    
    bool isLT() {
    	return (this->value == LT) ? true : false;
    }

    bool isLE() {
    	return (this->value == LE) ? true : false;
    }
    
    bool isGT() {
    	return (this->value == GT) ? true : false;
    }

    bool isGE() {
    	return (this->value == GE) ? true : false;
    }
    
    bool isNotEQ() {
    	return (this->value == NOTEQ) ? true : false;
    }
    
    bool isAnd() {
    	return (this->value == AND) ? true : false;
    }
    
    bool isOr() {
    	return (this->value == OR) ? true : false;
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
