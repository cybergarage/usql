/******************************************************************
*
* uSQL for C++
*
* SQLHaving.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLHAVING_H
#define CG_USQL_SQLHAVING_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

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
