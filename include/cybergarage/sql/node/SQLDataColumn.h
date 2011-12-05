/******************************************************************
*
* uSQL for C++
*
* SQLDataColumn.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDATASOURCE_H
#define CG_USQL_SQLDATASOURCE_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLDataColumn : public SQLExpression {

public:

	SQLDataSource() {
    	setType(DATACOLUMN);
    }

};

}

#endif
