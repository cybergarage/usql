/******************************************************************
*
* uSQL for C++
*
* SQLCollection.h
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCOLLECTION_H
#define CG_USQL_SQLCOLLECTION_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLCollection : public SQLNode {

public:

	SQLCollection() {
    	setType(COLLECTION);
    }
};

}

#endif
