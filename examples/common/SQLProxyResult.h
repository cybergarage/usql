/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLRESULT_H
#define CG_USQL_SQLDB_H

#include <cybergarage/sql/SQLError.h>

namespace uSQL {

class SQLProxyResult : public SQLError {
    
private:
    
    std::string execMessage;
    
public:

	SQLProxyResult();
    virtual ~SQLProxyResult();

    void setExecMessage(const std::string &message) {
        this->execMessage = message;
    }
    
    const std::string &getExecMessage() {
        return execMessage;
    }

    bool hasMessage() {
        return (0 < execMessage.length());
    }
    
    void setErrorMessage(const std::string &message) {
        setMessage(message);
    }
    
    const std::string &getErrorMessage() {
        return getMessage();
    }

};

}

#endif
