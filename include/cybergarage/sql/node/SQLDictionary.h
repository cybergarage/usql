/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDICTIONARY_H
#define CG_USQL_SQLDICTIONARY_H

#include <cybergarage/sql/SQLNode.h>
#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLDictionary : public SQLExpression {

private:
    
    std::string name;
    
public:

	SQLDictionary() {
    	setType(DICTIONARY);
    }

	~SQLDictionary();
        
	void setName(const std::string &name) {
    	this->name = name;
    }
    
    const std::string &getName() {
    	return this->name;
    }

	void setValue(SQLExpression *value) {
        clearExpressions();
        addExpression(value);
    }
    
    SQLExpression *getValue() {
        return getExpression(0);
    }
    
    std::string &toString(std::string &buf);
};

}

#endif
