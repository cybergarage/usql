/******************************************************************
*
* uSQL for C++
*
* SQLStatement.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLSTATEMENT_H
#define CG_USQL_SQLSTATEMENT_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLStatement : public SQLNode {

public:
	
    SQLStatement();
    
    std::string &toString(std::string &buf);
};

}

#endif
