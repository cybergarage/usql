/******************************************************************
*
* uSQL for C++
*
* SQLNode.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include<sstream>

#include <cybergarage/sql/SQLNode.h>

const int uSQL::SQLNode::COMMAND = 1;
const int uSQL::SQLNode::FROM = 2;
const int uSQL::SQLNode::TABLE = 3;
const int uSQL::SQLNode::ROW = 4;
const int uSQL::SQLNode::ROWS = 5;
const int uSQL::SQLNode::CONDITION = 6;
const int uSQL::SQLNode::WHERE = 7;

uSQL::SQLNode::SQLNode()
{
	setParentNode(NULL);
}
