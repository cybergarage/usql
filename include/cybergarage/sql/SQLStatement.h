/******************************************************************
*
* uSQL for C++
*
* SQLStatement.h
*
* Copyright (C) Satoshi Konno 2012
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
    
    static const int UNKNOWN;
    static const int SQL92;
    static const int GQL;
    static const int UNQL;
    
private:
    
    int statementType;

public:
	
    SQLStatement();

    void setStatementType(int type) {
        statementType = type;
    }
    
    int getStatementType(int type) {
        return this->statementType;
    }
    
    bool isStatementType(int type) {
        return (this->statementType == type);
    }
    
    bool isSQL92() {
        return isStatementType(SQL92);
    }
    
    bool isGQL() {
        return isStatementType(GQL);
    }
    
    bool isUnQL() {
        return isStatementType(UNQL);
    }
    
    SQLCommand *getCommandNode() {
        return (SQLCommand *)getChildNodeByType(SQLNode::COMMAND);
    }

    SQLCollection *getCollectionNode() {
        return (SQLCollection *)getChildNodeByType(SQLNode::COLLECTION);
    }
    
    SQLColumn *getColumnNode() {
        return (SQLColumn *)getChildNodeByType(SQLNode::COLUMN);
    }

    SQLFrom *getFromNode() {
        return (SQLFrom *)getChildNodeByType(SQLNode::FROM);
    }

    SQLWhere *getWhereNode() {
        return (SQLWhere *)getChildNodeByType(SQLNode::WHERE);
    }

    SQLGroupBy *getGroupNode() {
        return (SQLGroupBy *)getChildNodeByType(SQLNode::GROUPBY);
    }

    SQLHaving *getHavingeNode() {
        return (SQLHaving *)getChildNodeByType(SQLNode::HAVING);
    }
    
    std::string &toString(std::string &buf);

#if defined(DEBUG)
    
    std::string &toTreeString(std::string &buf);    
    
#endif
};

}

#endif
