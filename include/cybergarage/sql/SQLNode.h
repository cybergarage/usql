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

    static const int COMMAND;
    static const int FROM;
    static const int TABLE;
    
protected:
    
    int type;

	SQLNode *parent;
	SQLNodeList children;
        
public:

	SQLNode();

    void setType(int type) {
        this->type = type;
    }
    
    int getType() {
        return this->type;
    }

    void setParentNode(SQLNode *node) {
        this->parent = node;
    }
    
    SQLNode *getParentNode() {
        return this->parent;
    }

	bool hasParentNode() {
    	return (getParentNode() != NULL) ? true : false;
    }
    
    void addChildNode(SQLNode *node) {
        node->setParentNode(this);
    	children.addNode(node);
    }
	    
    void addChildNodes(SQLNodeList *nodeList) {
		for (SQLNodeList::iterator node = nodeList->begin(); node != nodeList->end(); node++)
        	addChildNode(*node);
    }
    
    int numChildNodes()
    {
    	return (int)children.size();
    }

    SQLNode *getChildNode(int index)
    {
    	return children.getNode(index);
    }
    
	virtual void output(std::ostream &os) = 0;
	void outputAll(std::ostream &os);
    
    std::string &toString(std::string &buf);
    
    friend std::ostream & operator << (std::ostream &os, const SQLNode & node);

};

}

#endif
