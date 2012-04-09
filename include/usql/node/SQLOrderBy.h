/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLORDERBY_H
#define CG_USQL_SQLORDERBY_H

#include <usql/SQLNode.h>

namespace uSQL {

class SQLOrderBy : public SQLNode {

public:

	SQLOrderBy() {
    	setType(ORDERBY);
	}

    const char *getTypeName() {
        return "SQLOrderBy";
    }
    
    
    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << "ORDER BY " << childNodesToString(childNodeStr, ",");
    	buf = oss.str();
		return buf;
	}
    
};

}

#endif
