/******************************************************************
*
* uSQL for C++
*
* SQLGroupBy.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLGROUPBY_H
#define CG_USQL_SQLGROUPBY_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLGroupBy : public SQLExpression {

public:

	SQLGroupBy() {
    	setType(GROUPBY);
	}

    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << "GROUP BY " << childNodesToString(childNodeStr, ",");
    	buf = oss.str();
		return buf;
	}
    
};

}

#endif
