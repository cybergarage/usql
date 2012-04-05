/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCOLUMNS_H
#define CG_USQL_SQLCOLUMNS_H

#include <string>
#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLColumns : public SQLExpression {

public:

	SQLColumns() {
    	setType(COLUMNS);
    }

    std::string &toString(std::string &buf);
};

}

#endif
