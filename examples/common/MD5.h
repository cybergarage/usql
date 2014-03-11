/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_MD5_H
#define CG_USQL_MD5_H

#include <map>
#include <string>

namespace uSQL {

class MD5 {
  
public:

  static std::string &hash(const std::string &string, std::string &buf);
  
};

}

#endif
