/******************************************************************
*
* uSQL for C++
*
* SQLStatement.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLSTATEMENT_H
#define CG_USQL_SQLSTATEMENT_H

#include <cybergarage/sql/SQLNode.h>
#include <cybergarage/sql/SQLNodes.h>

namespace uSQL {

class SQLStatement;

class SQLStatementList : public std::vector<SQLStatement *> {

public:

	SQLStatementList()
    {
    }

    void addStatement(SQLStatement *stmt) {
    	push_back(stmt);
    }

    SQLStatement *getStatement(int index) {
    	return at(index);
    }
};

class SQLStatement : public SQLNode {

public:
	
    SQLStatement();

    SQLCommand *getCommandNode() {
        return (SQLCommand *)getChildNodeByType(SQLNode::COMMAND);
    }
    
    std::string &toString(std::string &buf);

#if defined(DEBUG)
    
    std::string &toTreeString(std::string &buf);    
    
#endif
};

}

#endif
