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

#ifndef CG_USQL_SQLCOLUMN_H
#define CG_USQL_SQLCOLUMN_H

#include <string>
#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLColumn : public SQLExpression {

public:

	SQLColumn() {
    	setType(COLUMN);
    }

    std::string &toString(std::string &buf);
};

}

#endif
