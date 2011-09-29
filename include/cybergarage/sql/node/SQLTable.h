/******************************************************************
*
* uSQL for C++
*
* SQLTable.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLTABLE_H
#define CG_USQL_SQLTABLE_H

#include <string>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLTable : public SQLNode {

private:

	std::string name;
    
public:

	SQLTable() {
    	setType(TABLE);
    }

	void setName(const char *name) {
    	this->name = name;
    }
    
    const char *getName() {
    	return this->name.c_str();
    }

    std::string &toString(std::string &buf)
    {
    	buf = name;
        return buf;
    }
};

}

#endif
