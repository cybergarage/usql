/******************************************************************
*
* uSQL for C++
*
* SQLCollection.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCOLLECTION_H
#define CG_USQL_SQLCOLLECTION_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLCollection : public SQLNode {

    std::string name;
    
public:

	SQLCollection() {
    	setType(COLLECTION);
    }

	void setName(const std::string &name) {
    	this->name = name;
    }
    
    const char *getName() {
    	return this->name.c_str();
    }
    
    std::string &toString(std::string &buf) {
    	buf = this->name;
        return buf;
    }
};

}

#endif
