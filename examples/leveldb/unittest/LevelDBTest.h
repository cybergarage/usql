/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_LEVELDBTEST_H
#define CG_USQL_LEVELDBTEST_H

#include "LevelDBProxy.h"
        
namespace uSQL {

class LevelDBTest : public LevelDBProxy {
    
private:
    
public:

	LevelDBTest();
    ~LevelDBTest();

	bool execSQLStatement(const std::string &sqlString, SQLProxyResult &result);
};

}

#endif
