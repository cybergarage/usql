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

uSQL::SQLNode::SQLNode()
{
	setParentNode(NULL);
}

void uSQL::SQLNode::outputAll(std::ostream &os)
{
	if (hasParentNode())
    	os << " ";
    
    output(os);
    
    int numChildren = numChildNodes();
    for (int n=0; n<numChildren; n++) {
    	uSQL::SQLNode *childNode = getChildNode(n);
        childNode->outputAll(os);
    }
}

std::string &uSQL::SQLNode::toString(std::string &buf)
{
	std::ostringstream oss;
    outputAll(oss);
    buf = oss.str();
    return buf;
}

std::ostream& operator<< (std::ostream &os, const uSQL::SQLNode &node)
{
	//node.outputAll(os);
	return os;
}
