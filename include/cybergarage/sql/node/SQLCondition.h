/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCONDITION_H
#define CG_USQL_SQLCONDITION_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLCondition : public SQLExpression {

public:

	SQLCondition() {
    	setType(CONDITION);
    }
    
    virtual std::string &toString(std::string &buf) = 0;
 };

class SQLWhere : public SQLCondition {

public:

	SQLWhere() {
    	setType(WHERE);
    }
    
    std::string &toString(std::string &buf) {
    	std::string exprString;
		std::ostringstream oss;
        oss << "WHERE " << SQLExpression::toString(exprString) ;
		buf = oss.str();
        return buf;
    }
};

class SQLHaving : public SQLExpression {

public:

	SQLHaving() {
    	setType(HAVING);
	}

    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << "HAVING " << childNodesToString(childNodeStr);
    	buf = oss.str();
		return buf;
	}
    
};

}

#endif
