/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDB_H
#define CG_USQL_SQLDB_H

#include <string>
#include <cybergarage/sql/UnQLParser.h>
#include "Dictionary.h"

namespace uSQL {

class SQLProxy {
    
private:
    
    std::string errorString;
    
public:

	SQLProxy();
    virtual ~SQLProxy();

    bool getKey(SQLStatement *stmt, std::string &key, SQLError &error);
    bool getInsertDictionary(SQLStatement *stmt, Dictionary &dictionary, SQLError &error);
    bool getUpdateDictionary(SQLStatement *stmt, Dictionary &dictionary, SQLError &error);
    
    const char *getErrorMessage() {
        return errorString.c_str();
    }
};

}

#endif
