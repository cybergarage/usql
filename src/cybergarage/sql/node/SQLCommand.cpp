/******************************************************************
*
* uSQL for C++
*
* SQLCommand.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLCommand.h>

const int uSQL::SQLCommand::UNKOWN = -1;
const int uSQL::SQLCommand::SELECT = 1;
const int uSQL::SQLCommand::UPDATE = 2;
const int uSQL::SQLCommand::INSERT = 3;
const int uSQL::SQLCommand::DELETE = 4;

uSQL::SQLCommand::SQLCommand()
{
    
}
