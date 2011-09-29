/******************************************************************
*
* uSQL for C++
*
* SQLFrom.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLFROM_H
#define CG_USQL_SQLFROM_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLFrom : public SQLNode {

public:

	SQLFrom() {
    	setType(FROM);
    }

	void output(std::ostream &os)
    {
    	os << "FROM";
    }
};

}

#endif
