/******************************************************************
*
* uSQL for C++
*
* SQLOrders.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLORDERS_H
#define CG_USQL_SQLORDERS_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLOrders : public SQLNode {

public:

	SQLOrders() {
    	setType(ORDERS);
    }

    std::string &toString(std::string &buf) {
    	buf = "ORDER BY";
        return buf;
    }
};

}

#endif
