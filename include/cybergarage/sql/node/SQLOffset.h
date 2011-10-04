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

private:

	int value;
    
public:

	SQLOffset() {
    	setType(OFFSET);
        setValue(0);
    }

	void setValue(int value) {
    	this->value = value;
    }
    
	int getValue() {
    	return this->value;
    }
    
    std::string &toString(std::string &buf) {
		std::ostringstream oss;
		oss << "OFFSET " << this->value;
		buf = oss.str();
        return buf;
    }
};

}

#endif
