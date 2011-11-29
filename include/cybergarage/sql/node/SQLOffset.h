/******************************************************************
*
* uSQL for C++
*
* SQLOffset.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLOFFSET_H
#define CG_USQL_SQLOFFSET_H

#include <sstream>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLOffset : public SQLNode {

public:

	SQLOffset() {
    	setType(OFFSET);
    }
    
    std::string &toString(std::string &buf) {
	    std::ostringstream oss;
	    std::string childNodeStr;
	    oss << "OFFSET " << childNodesToString(childNodeStr);
    	buf = oss.str();
		return buf;
    }
};

}

#endif
