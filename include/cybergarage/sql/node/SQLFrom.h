/******************************************************************
*
* uSQL for C++
*
* SQLFrom.h
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLFROM_H
#define CG_USQL_SQLFROM_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLFrom : public SQLNode {

public:

	SQLFrom() {
    	setType(FROM);
	}

    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << "FROM " << childNodesToString(childNodeStr, ",");
    	buf = oss.str();
		return buf;
	}
    
};

}

#endif
