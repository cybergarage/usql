/******************************************************************
*
* uSQL for C++
*
* SQLOperator.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLOPERATOR_H
#define CG_USQL_SQLOPERATOR_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLOperator : public SQLExpression {

public:

	SQLOperator() {
    	setType(OPERATOR);
    }
    
    std::string &toString(std::string &buf) {
        return buf;
    }
};

}

#endif
