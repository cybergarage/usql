/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLWHERE_H
#define CG_USQL_SQLWHERE_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLWhere : public SQLExpression {

public:

	SQLWhere() {
    	setType(WHERE);
    }
    
    SQLExpression *getExpressionNode(int index) {
        return (SQLExpression *)getChildNode(index);
    }
    
    std::string &toString(std::string &buf) {
    	std::string exprString;
		std::ostringstream oss;
        oss << "WHERE " << SQLExpression::toString(exprString) ;
		buf = oss.str();
        return buf;
    }
};

}

#endif
