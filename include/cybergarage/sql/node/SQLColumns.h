/******************************************************************
*
* uSQL for C++
*
* SQLColumn.h
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

class SQLColumn : public SQLNode {

public:

	SQLColumn() {
    	setType(COLUMNS);
    }

    std::string &toString(std::string &buf) {
    	buf = "";
        return buf;
    }
};

}

#endif
