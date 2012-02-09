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
    
    int            code;
    std::string    message;

public:
	
    SQLError();
    ~SQLError();

    void setCode(int code) {
        this->code = code;
    }
    
    int getCode() {
        return this->code;
    }
    
    void setMessage(const std::string &message) {
        this->message = message;
    }
    
    const std::string &getMessage() {
        return this->message;
    }

};

}

#endif
