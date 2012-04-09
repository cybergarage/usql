/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_MEMCACHEDPROXY_H
#define CG_USQL_MEMCACHEDPROXY_H

#include <string>
#include <libmemcached/memcached.h>

#include "SQLProxy.h"

namespace uSQL {

class MemcachedProxy : public SQLProxy {

    memcached_st *memcd;
    time_t mmcdExpiration;
        
public:
    
	MemcachedProxy();
    virtual ~MemcachedProxy();
    
    void setExpiration(time_t value) {
        this->mmcdExpiration = value;
    }
    
    time_t getExpiration() {
        return this->mmcdExpiration;
    }
    
    bool connect(const std::string &host);
    bool close();
    
public:

    bool set(SQLStatement *stmt, SQLProxyDataSet *valuesDict, SQLError &error);
    bool get(SQLStatement *stmt, SQLProxyResult &result);
    bool remove(SQLStatement *stmt, SQLProxyResult &result);
};

}

#endif
