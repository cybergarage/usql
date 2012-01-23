/******************************************************************
*
* uSQL for C++
*
* SQLFunction.h
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLFUNCTION_H
#define CG_USQL_SQLFUNCTION_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLFunction : public SQLExpression {

public:

	SQLFunction() {
    	setType(FUNCTION);
    }
    
    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
    	std::string childNodeStr;
    	oss << getValue() << "(" << childNodesToString(childNodeStr, ",") << ")";
    	buf = oss.str();
		return buf;
    }
};


}

#endif
