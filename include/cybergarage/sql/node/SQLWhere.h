/******************************************************************
*
* uSQL for C++
*
* SQLWhere.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLWHERE_H
#define CG_USQL_SQLWHERE_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLWhere : public SQLExpression {

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

}

#endif
