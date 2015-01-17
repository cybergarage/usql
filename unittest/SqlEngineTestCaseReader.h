/******************************************************************
*
* uSQL for C++
*
* SqlEngineTestCaseReader.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef _USQL_TESTCASEREADER_H_
#define _USQL_TESTCASEREADER_H_

#include <string>

class SqlEngineTestCaseReader {

public:

  SqlEngineTestCaseReader();
  
  bool parseFile(const char *filename);
  
  const char *nextCase();
};

#endif
