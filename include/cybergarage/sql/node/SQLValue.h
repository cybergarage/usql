/******************************************************************
*
* uSQL for C++
*
* SQLValue.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLVALUE_H
#define CG_USQL_SQLVALUE_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLValue : public SQLExpression {

public:

	SQLValue() {
    	setType(VALUE);
    }

	SQLValue(SQLExpression *exprNode) {
    	setType(VALUE);
        setValue(exprNode->getValue());
    }
    
    std::string &toString(std::string &buf) {
		std::ostringstream oss;
        oss << "VALUE " << getValue();
		buf = oss.str();
        return buf;
    }
};

}

#endif
