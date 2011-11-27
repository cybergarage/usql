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
const int uSQL::SQLNode::DATASOURCE = 3;
const int uSQL::SQLNode::COLUMN = 4;
const int uSQL::SQLNode::FUNCTION = 5;
const int uSQL::SQLNode::CONDITION = 6;
const int uSQL::SQLNode::WHERE = 7;
const int uSQL::SQLNode::ORDER = 8;
const int uSQL::SQLNode::ORDERS = 9;
const int uSQL::SQLNode::LIMIT = 10;
const int uSQL::SQLNode::OFFSET = 11;
const int uSQL::SQLNode::COLLECTION = 12;
const int uSQL::SQLNode::EXPRESSION = 13;
const int uSQL::SQLNode::VALUE = 14;
const int uSQL::SQLNode::VALUES = 15;
const int uSQL::SQLNode::DICTIONARY = 16;
const int uSQL::SQLNode::OPTION = 17;
const int uSQL::SQLNode::OPERATOR = 18;

uSQL::SQLNode::SQLNode()
{
	setParentNode(NULL);
}

uSQL::SQLNode::~SQLNode()
{
    for (SQLNodeList::iterator node = children.begin(); node != children.end(); node++)
        delete *node;
}

std::string &uSQL::SQLNode::toString(std::string &buf)
{
    std::ostringstream oss;

    std::string nodeStr;
    toString(nodeStr);
    
    if (0 < nodeStr.length()) {
	    oss << nodeStr;
	    oss << " ";
    }
    
    uSQL::SQLNodeList *childNodes = getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++) {
        std::string childNodeStr;
        uSQL::SQLNode *childNode = childNodes->getNode(n);
        childNode->toString(childNodeStr);
        if (0 < childNodeStr.length()) {
            oss << childNodeStr;
            oss << " ";
        }
    }
    
    buf = oss.str();
    
    return buf;
}
