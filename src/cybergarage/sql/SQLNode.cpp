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
const int uSQL::SQLNode::COLUMN = 4;
const int uSQL::SQLNode::COLUMNS = 5;
const int uSQL::SQLNode::CONDITION = 6;
const int uSQL::SQLNode::WHERE = 7;
const int uSQL::SQLNode::ORDER = 8;
const int uSQL::SQLNode::ORDERS = 9;
const int uSQL::SQLNode::LIMIT = 10;
const int uSQL::SQLNode::OFFSET = 11;
const int uSQL::SQLNode::COLLECTION = 12;
const int uSQL::SQLNode::EXPRESSION = 13;
const int uSQL::SQLNode::VALUE = 14;

uSQL::SQLNode::SQLNode()
{
	setParentNode(NULL);
}

uSQL::SQLNode::~SQLNode()
{
    for (SQLNodeList::iterator node = children.begin(); node != children.end(); node++)
        delete *node;
}

