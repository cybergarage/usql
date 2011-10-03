/******************************************************************
*
* uSQL for C++
*
* SQLCondition.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCONDITION_H
#define CG_USQL_SQLCONDITION_H

#include <string>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLCondition : public SQLNode {

public:

    static const int UNKOWN;
    static const int EQ;
    static const int LT;
    static const int LE;
    static const int GT;
    static const int GE;
    static const int NOTEQ;

private:

	std::string name;
	std::string value;
    int	operation;
    
public:

	SQLCondition() {
    	setType(CONDITION);
        setOperation(UNKOWN);
    }

	void setName(const std::string &name) {
    	this->name = name;
    }
    
    const char *getName() {
    	return this->name.c_str();
    }

	void setOperation(int value) {
    	this->operation = value;
    }
    
	void setOperation(const std::string &value);
    
    int getOperation() {
    	return this->operation;
    }

	void setValue(const std::string &value) {
    	this->value = value;
    }
    
    const char *getValue() {
    	return this->value.c_str();
    }

    std::string &toString(std::string &buf);
};

}

#endif
