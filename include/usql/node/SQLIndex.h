/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLINDEX_H
#define CG_USQL_SQLINDEX_H

#include <usql/SQLNode.h>

namespace uSQL {

class SQLIndex : public SQLNode {

public:

	SQLIndex() {
    	setType(INDEX);
    }

    const char *getTypeName() {
        return "SQLIndex";
    }
};

}
#endif
