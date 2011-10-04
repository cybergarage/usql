/******************************************************************
*
* uSQL for C++
*
* SQLOrder.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLORDER_H
#define CG_USQL_SQLORDER_H

#include <string>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLOrder : public SQLNode {

public:

    static const int UNKOWN;
    static const int ASC;
    static const int DESC;

private:

	std::string name;
    int order;
    
public:

	SQLOrder() {
    	setType(ORDER);
    }

	void setName(const std::string &name) {
    	this->name = name;
    }
    
    const char *getName() {
    	return this->name.c_str();
    }

	void setOrder(int type) {
    	this->order = order;
    }
    
	void setOrder(const std::string &order);
    
	int getOrder() {
    	return this->order;
    }

    std::string &toString(std::string &buf);
};

}

#endif
