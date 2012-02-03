/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLERROR_H
#define CG_USQL_SQLERROR_H

#include <string>

namespace uSQL {

class SQLError {

private:
    
    std::string    message;

public:
	
    SQLError();
    ~SQLError();

    void setMessage(const std::string &message) {
        this->message = message;
    }
    
    std::string &getMessage() {
        return this->message;
    }

};

}

#endif
