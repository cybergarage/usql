/******************************************************************
*
* uSQL for C++
*
* SQLNode.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLNODE_H
#define CG_USQL_SQLNODE_H

#include <vector>
#include <iostream>
#include <sstream>

namespace uSQL {

class SQLNode;

class SQLNodeList : public std::vector<SQLNode *> {

public:

	SQLNodeList()
    {
    }

    void addNode(SQLNode *node) {
    	push_back(node);
    }

    SQLNode *getNode(int index) {
    	return at(index);
    }
};

class SQLNode {

public:

    static const int COLLECTION;
    static const int CONDITION;
    static const int COLUMN;
    static const int COLUMNS;
    static const int COMMAND;
    static const int DATACOLUMN;
    static const int DATASOURCE;
    static const int DICTIONARY;
    static const int EXPRESSION;
    static const int FROM;
    static const int FUNCTION;
    static const int GROUPBY;
    static const int HAVING;
    static const int INDEX;
    static const int LIMIT;
    static const int OFFSET;
    static const int OPERATOR;
    static const int OPTION;
    static const int ORDER;
    static const int ORDERBY;
    static const int SET;
    static const int TRANSACTION;
    static const int WHERE;
    static const int VALUE;
    static const int VALUES;
    
private:
    
    int type;

	SQLNode *parent;
	SQLNodeList children;

	std::string value;

public:

	SQLNode();

    virtual ~SQLNode();
    
    void setType(int type) {
        this->type = type;
    }
    
    int getType() {
        return this->type;
    }
    
    bool isSQLExpressionNode();
    
	void setValue(const std::string &value) {
    	this->value = value;
    }
    
    const std::string &getValue() {
    	return this->value;
    }

   	void setParentNode(SQLNode *node) {
        this->parent = node;
    }
    
    SQLNode *getParentNode() {
        return this->parent;
    }

    void addChildNode(SQLNode *node) {
        node->setParentNode(this);
    	children.addNode(node);
    }
	    
    void addChildNodes(SQLNodeList *nodeList) {
		for (SQLNodeList::iterator node = nodeList->begin(); node != nodeList->end(); node++)
        	addChildNode(*node);
    }

    bool hasChildNodes()
    {
    	return (0 < children.size()) ? true : false;
    }
    
    SQLNodeList *getChildNodes()
    {
    	return &children;
    }
    
    virtual std::string &toString(std::string &buf);
    
protected:

	std::string &childNodesToString(std::string &buf, std::string delim = " ");
};

}

#endif
