/******************************************************************
*
* uSQL for C++
*
* SQLOrder.h
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLORDER_H
#define CG_USQL_SQLORDER_H

#include <string>
#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLOrder : public SQLExpression {

public:

    static const int UNKOWN;
    static const int ASC;
    static const int DESC;

private:

    int order;
    
public:

	SQLOrder() {
    	setType(ORDER);
    }

	void setOrder(int type);    
	void setOrder(const std::string &order);
    
	int getOrder() {
    	return this->order;
    }

    std::string &toString(std::string &buf);
};

}

#endif
