/******************************************************************
*
* uSQL for C++
*
* SQLValules.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLVALUES_H
#define CG_USQL_SQLVALUES_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLValules : public SQLNode {

public:

	SQLValules() {
    	setType(VALUES);
    }
    
    std::string &toString(std::string &buf) {
    	buf = "";
        return buf;
    }
};

}

#endif
