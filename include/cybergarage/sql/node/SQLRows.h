/******************************************************************
*
* uSQL for C++
*
* SQLRows.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLROWS_H
#define CG_USQL_SQLROWS_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLRows : public SQLNode {

public:

	SQLRows() {
    	setType(ROWS);
    }

    std::string &toString(std::string &buf) {
    	buf = "";
        return buf;
    }
};

}

#endif
