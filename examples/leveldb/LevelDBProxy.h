/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_LEVELDB_H
#define CG_USQL_LEVELDB_H

#include <string>
#include <leveldb/db.h>
#include "SQLProxy.h"
#include "SQLProxyResult.h"

namespace uSQL {

class LevelDBProxy : public SQLProxy {
  
private:
  
  leveldb::DB* db;
  
private:
  
  bool getInsertStatementKey(SQLStatement *stmt, std::string &key, SQLError &error);
  bool getStatementKey(SQLStatement *stmt, std::string &key, SQLError &error);
  
  bool select(SQLStatement *stmt, SQLProxyResult &result);
  bool insert(SQLStatement *stmt, SQLError &error);
  bool update(SQLStatement *stmt, SQLError &error);
  bool remove(SQLStatement *stmt, SQLError &error);

public:

  LevelDBProxy();
  virtual ~LevelDBProxy();

  bool open(const std::string &filename);
  bool close();
  
  bool getKey(SQLStatement *stmt, std::string &key, SQLError &error);
  
public:

  bool connect(const std::string &host, const std::string &user, const std::string &passwd, const std::string &db) {
    return  true;
  }
  
  bool query(SQLStatement *stmt, SQLProxyResult &result);

};

}

#endif
