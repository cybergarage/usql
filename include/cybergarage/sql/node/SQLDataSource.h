/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDATASOURCE_H
#define CG_USQL_SQLDATASOURCE_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLDataSource : public SQLNode {

public:

	SQLDataSource() {
    	setType(DATASOURCE);
    }
};

}

#endif
