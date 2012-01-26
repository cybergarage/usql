/******************************************************************
*
* uSQL for C++
*
* SQLNode.cpp
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include<sstream>

#include <cybergarage/sql/SQLNode.h>
#include <cybergarage/sql/SQLStatement.h>
#include <cybergarage/sql/node/SQLExpression.h>
#include <cybergarage/sql/node/SQLOperator.h>

const int uSQL::SQLNode::COMMAND = 1;
const int uSQL::SQLNode::FROM = 2;
const int uSQL::SQLNode::DATASOURCE = 3;
const int uSQL::SQLNode::COLUMN = 4;
const int uSQL::SQLNode::FUNCTION = 5;
const int uSQL::SQLNode::CONDITION = 6;
const int uSQL::SQLNode::WHERE = 7;
const int uSQL::SQLNode::ORDER = 8;
const int uSQL::SQLNode::ORDERBY = 9;
const int uSQL::SQLNode::LIMIT = 10;
const int uSQL::SQLNode::OFFSET = 11;
const int uSQL::SQLNode::COLLECTION = 12;
const int uSQL::SQLNode::EXPRESSION = 13;
const int uSQL::SQLNode::VALUE = 14;
const int uSQL::SQLNode::VALUES = 15;
const int uSQL::SQLNode::DICTIONARY = 16;
const int uSQL::SQLNode::OPTION = 17;
const int uSQL::SQLNode::OPERATOR = 18;
const int uSQL::SQLNode::GROUPBY = 19;
const int uSQL::SQLNode::HAVING = 20;
const int uSQL::SQLNode::INDEX = 21;
const int uSQL::SQLNode::TRANSACTION = 22;
const int uSQL::SQLNode::DATACOLUMN = 24;
const int uSQL::SQLNode::SET = 25;
const int uSQL::SQLNode::STATEMENT = 26;

uSQL::SQLNode::SQLNode()
{
	setParentNode(NULL);
}

uSQL::SQLNode::~SQLNode()
{
    for (SQLNodeList::iterator node = children.begin(); node != children.end(); node++)
        delete *node;
}


bool uSQL::SQLNode::isStatementType(int type)
{
    if ((getRootNode()->isStatementNode())) {
        uSQL::SQLStatement * stmtNode = (uSQL::SQLStatement *)getRootNode();
        return stmtNode->isStatementType(type);
    }

    return uSQL::SQLStatement::UNKNOWN;
}

bool uSQL::SQLNode::isUnQLNode()
{
    return isStatementType(uSQL::SQLStatement::UNQL);
}

bool uSQL::SQLNode::isSQLExpressionNode() 
{
	return (dynamic_cast<uSQL::SQLExpression *>(this)) ? true : false;
}

bool uSQL::SQLNode::isOperatorNode() 
{
	return (dynamic_cast<uSQL::SQLOperator *>(this)) ? true : false;
}

bool uSQL::SQLNode::isStatementNode() 
{
	return (dynamic_cast<uSQL::SQLStatement *>(this)) ? true : false;
}

uSQL::SQLNode *uSQL::SQLNode::getChildNodeByType(int type)
{
    for (SQLNodeList::iterator node = children.begin(); node != children.end(); node++) {
        if ((*node)->isType(type))
            return (*node);
    }
    return NULL;
}

static std::string CgSQLNode2String(uSQL::SQLNode *sqlNode, std::string &buf)
{
    std::ostringstream oss;
    
    if (sqlNode->isSQLExpressionNode()) {
    	uSQL::SQLExpression *exprNode = (uSQL::SQLExpression *)sqlNode;
		const std::string name = exprNode->getName();
		if (0 < name.length()) {
		    oss << name;
		    oss << ":";
	    }
    }
    
	const std::string value = sqlNode->getValue();
	if (0 < value.length()) {
	    oss << value;
    }
    
    buf = oss.str();
    
    return buf;
}

static void CgSQLNodeStringAdd2OutputStream(std::string &nodeString, std::ostringstream &oss)
{
	if (nodeString.length() <= 0)
    	return;
        
    std::string ossStr = oss.str();
    if (0 < ossStr.length()) {
		char lastChar = ossStr.at((ossStr.length()-1));
    	if (lastChar != ' ')
	    	oss << " ";
    }
    
    oss << nodeString;
}

static void CgSQLNodeAdd2OutputStream(uSQL::SQLNode *sqlNode, std::ostringstream &oss)
{
    std::string nodeStr;
    CgSQLNode2String(sqlNode, nodeStr);
    CgSQLNodeStringAdd2OutputStream(nodeStr, oss);
}

std::string &uSQL::SQLNode::childNodesToString(std::string &buf, std::string delim)
{
    std::ostringstream oss;

    uSQL::SQLNodeList *childNodes = getChildNodes();
    std::size_t numChildren = childNodes->size();
    for (int n=0; n<numChildren; n++) {
        std::string childNodeStr;
        uSQL::SQLNode *childNode = childNodes->getNode(n);
        childNode->toString(childNodeStr);
        if (0 < childNodeStr.length()) {
            oss << childNodeStr;
            if (n < (numChildren-1))
            	oss << delim;
        }
    }
    
    buf = oss.str();
    
    return buf;
}

std::string &uSQL::SQLNode::toString(std::string &buf)
{
    std::ostringstream oss;

	CgSQLNodeAdd2OutputStream(this, oss);

	if (hasChildNodes() == true) {
	    std::string childNodeStr;
    	childNodesToString(childNodeStr);
    	CgSQLNodeStringAdd2OutputStream(childNodeStr, oss);
    }
    
    buf = oss.str();
    
    return buf;
}
