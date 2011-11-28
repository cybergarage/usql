/******************************************************************
*
* uSQL for C++
*
* SQLDataSource.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDATASOURCE_H
#define CG_USQL_SQLDATASOURCE_H

#include <string>
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
