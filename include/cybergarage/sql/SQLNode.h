/******************************************************************
*
* uSQL for C++
*
* SQLNode.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLNODE_H
#define CG_USQL_SQLNODE_H

namespace uSQL {

class SQLNode {

public:

    static const int COMMAND;
    
private:
    
    int type;
    
public:

	SQLNode();

    void setType(int type) {
        this->type = type;
    }
    
    int getType() {
        return this->type;
    }
};

}

#endif
