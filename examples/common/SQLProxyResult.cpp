/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "SQLProxyResult.h"

using namespace std;
using namespace uSQL;

uSQL::SQLProxyResult::SQLProxyResult()
{
  clear();
}

uSQL::SQLProxyResult::~SQLProxyResult()
{
}

void uSQL::SQLProxyResult::clear()
{
  resultSet.clear();
  execMessage = "";
  setCashed(false);
}
