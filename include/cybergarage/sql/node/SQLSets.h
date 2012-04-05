/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLSETS_H
#define CG_USQL_SQLSETS_H

#include <cybergarage/sql/node/SQLDataSet.h>
#include <cybergarage/sql/node/SQLSet.h>

namespace uSQL {

class SQLSets : public SQLDataSet {

public:

	SQLSets() {
    	setType(SETS);
    }
    
    int getSetCount() {
        return getChildCount();
    }
    
    SQLNodeList *getSets() {
        return getChildNodes();
    }
    
    SQLSet *getSet(int index) {
        return (SQLSet *)getChildNode(index);
    }
    
    std::string &toString(std::string &buf);
};

}

#endif
