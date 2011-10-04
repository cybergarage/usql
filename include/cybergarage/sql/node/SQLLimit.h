/******************************************************************
*
* uSQL for C++
*
* SQLLimit.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLLIMIT_H
#define CG_USQL_SQLLIMIT_H

#include <sstream>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLLimit : public SQLNode {

private:

	int offset;
    int count;
    
public:

	SQLLimit() {
    	setType(LIMIT);
        setOffset(0);
        setCount(-1);
    }
    
	void setOffset(int value) {
    	this->offset = value;
    }
    
	int getOffset() {
    	return this->offset;
    }

	void setCount(int value) {
    	this->count = value;
    }
    
	int getCount() {
    	return this->count;
    }
    
    std::string &toString(std::string &buf) {
		std::ostringstream oss;
		oss << "LIMIT " << this->offset;
        if (0 < this->count)
        	oss << ", " << this->count;
		buf = oss.str();
        return buf;
    }
};

}

#endif
