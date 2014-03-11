/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <string.h>
#include <libmemcached/memcached.h>

#include "MemcachedProxy.h"

using namespace std;
using namespace uSQL;

uSQL::MemcachedProxy::MemcachedProxy()
{
  this->memcd = memcached_create(NULL);
  setExpiration(0);
}

uSQL::MemcachedProxy::~MemcachedProxy()
{
  memcached_free(this->memcd);
}

bool uSQL::MemcachedProxy::connect(const std::string &host)
{
  memcached_server_st *memcdServer = memcached_servers_parse(host.c_str());
  if (memcached_server_push(this->memcd, memcdServer) != MEMCACHED_SUCCESS)
    return false;
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
  
  return (memcdRet == MEMCACHED_SUCCESS) ? true : false;
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
  
  return (memcdRet == MEMCACHED_SUCCESS) ? true : false;
}
