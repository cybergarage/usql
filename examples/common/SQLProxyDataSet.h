/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_PROXYDATASET_H
#define CG_USQL_PROXYDATASET_H

#include <map>
#include <string>
#include <vector>

namespace uSQL {

class SQLProxyDataSet : public std::map<std::string, std::string> {

private:

  std::string dictionaryString;
  std::vector<std::string> allKeys;
  
public:

  SQLProxyDataSet();
  virtual ~SQLProxyDataSet();

  bool parse(const std::string &aString);
  
  bool hasData();
  
  void set(const std::string &keyName, const std::string &keyValue);
  
  std::vector<std::string> &getAllKeys();
  const std::string &getValue(const std::string &keyName);
  bool isValue(const std::string &keyName, const std::string &value);
  
  std::string &toString(std::string &buf);
  
  const std::string &toString() {
    return toString(this->dictionaryString);
  }
};

}

#endif
