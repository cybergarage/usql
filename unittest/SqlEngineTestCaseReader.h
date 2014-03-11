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

#ifndef CG_USQL_TESTCASEREADER_H
#define CG_USQL_TESTCASEREADER_H

#include <string>

class SqlEngineTestCaseReader {

public:

  SqlEngineTestCaseReader();
  
  bool parseFile(const char *filename);
  
  const char *nextCase();
};

#endif
