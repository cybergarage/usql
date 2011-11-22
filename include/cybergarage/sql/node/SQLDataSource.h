/******************************************************************
*
* uSQL for C++
*
* SQLDataSource.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDATASOURCE_H
#define CG_USQL_SQLDATASOURCE_H

#include <string>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLDataSource : public SQLNode {

private:

	std::string name;
    
public:

	SQLDataSource() {
    	setType(DATASOURCE);
    }

	void setName(const std::string &name) {
    	this->name = name;
    }
    
    const char *getName() {
    	return this->name.c_str();
    }

    std::string &toString(std::string &buf) {
    	buf = name;
        return buf;
    }
};

}

#endif
