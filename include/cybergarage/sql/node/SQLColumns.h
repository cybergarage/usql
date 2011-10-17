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

#ifndef CG_USQL_SQLCOLUMNS_H
#define CG_USQL_SQLCOLUMNS_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLColumns : public SQLNode {

public:

	SQLColumns() {
    	setType(COLUMNS);
    }

    std::string &toString(std::string &buf) {
    	buf = "";
        return buf;
    }
};

}

#endif
