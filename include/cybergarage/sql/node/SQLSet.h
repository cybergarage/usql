/******************************************************************
*
* uSQL for C++
*
* SQLSet.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLSET_H
#define CG_USQL_SQLSET_H

#include <cybergarage/sql/node/SQLColumn.h>

namespace uSQL {

class SQLSet : public SQLColumn {

public:

	SQLSet() {
    	setType(SET);
    }
    
    std::string &toString(std::string &buf) {
	    std::string columnString;
	    std::ostringstream oss;
	    oss << "SET " << SQLColumn::toString(columnString);
	    buf = oss.str();
		return buf;
    }
};

}

#endif
