/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLSET_H
#define CG_USQL_SQLSET_H

#include <cybergarage/sql/node/SQLDataSet.h>
#include <cybergarage/sql/node/SQLDictionary.h>

namespace uSQL {

class SQLSet : public SQLDataSet {

public:

	SQLSet() {
    	setType(SET);
    }
    
    int getDictionaryCount() {
        return getChildCount();
    }
    
    SQLNodeList *getDictionaries() {
        return getChildNodes();
    }
    
    SQLDictionary *getDictionary(int index) {
        return (SQLDictionary *)getChildNode(index);
    }
    
    std::string &toString(std::string &buf);
};

}

#endif
