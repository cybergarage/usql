/******************************************************************
*
* uSQL for C++
*
* SQLValue.h
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLVALUE_H
#define CG_USQL_SQLVALUE_H

#include <cybergarage/sql/node/SQLColumn.h>

namespace uSQL {

class SQLValue : public SQLColumn {

public:

	SQLValue() {
    	setType(VALUE);
    }
    
    std::string &toString(std::string &buf);
};

}

#endif
