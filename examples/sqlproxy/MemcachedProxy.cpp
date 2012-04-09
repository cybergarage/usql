/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "MemcachedProxy.h"

using namespace std;
using namespace uSQL;

uSQL::MemcachedProxy::MemcachedProxy()
{
    setExpiration(0);
}

uSQL::MemcachedProxy::~MemcachedProxy()
{
    close();
}

bool uSQL::MemcachedProxy::connect(const std::string &host)
{
    string config;
    
    config.append("--SERVER=");
    config.append(host);
    
    this->memcd = memcached(config.c_str(), strlen(config.c_str()));
    if (!this->memcd)
        return false;
        
    return true;
}

bool uSQL::MemcachedProxy::close()
{
    if (this->memcd) {
        memcached_free(this->memcd);
        this->memcd = NULL;
    }
    
    return true;
}

bool uSQL::MemcachedProxy::set(SQLStatement *stmt, SQLProxyDataSet *valuesDict, SQLError &error) 
{
    string hashKey;
    if (getKey(stmt, hashKey, error) == false)
        return false;

    string valueDictString = valuesDict->toString();
    uint32_t memcdFlags= 0;
    memcached_return memcdRet = memcached_set(this->memcd, hashKey.c_str(), hashKey.length(), valueDictString.c_str(), valueDictString.length(), getExpiration(), memcdFlags);        
    
    return memcached_success(memcdRet);
}

bool uSQL::MemcachedProxy::get(SQLStatement *stmt, SQLProxyResult &result) 
{
    string hashKey;
    if (getKey(stmt, hashKey, result) == false)
        return false;

    size_t valueLen;
    uint32_t memcdFlags= 0;
    memcached_return memcdRet;
    char *valuesString = memcached_get(this->memcd, hashKey.c_str(), hashKey.length(), &valueLen, &memcdFlags, &memcdRet);
    if (!valuesString)
        return false;

    SQLProxyDataSet *values = result.getResultSet();
    if (values->parse(valuesString) == false) {
        result.setErrorMessage("Stored data was corrupted");
        return false;
    }
    
    free(valuesString);
    
    return true;
}

bool uSQL::MemcachedProxy::remove(SQLStatement *stmt, SQLProxyResult &result) 
{
    string hashKey;
    if (getKey(stmt, hashKey, result) == false)
        return false;

    memcached_return memcdRet = memcached_delete(this->memcd, hashKey.c_str(), hashKey.length(), getExpiration());        
    
    return memcached_success(memcdRet);
}
