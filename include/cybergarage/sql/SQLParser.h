/******************************************************************
*
* uSQL for C++
*
* SQLParser.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLPARSER_H
#define CG_USQL_SQLPARSER_H

#include <string>
#include <vector>
#include <stack>

#include <cybergarage/sql/SQLStatement.h>
#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLParser {

private:

    std::vector<SQLStatement *> statements;
    std::stack<SQLNode *> parserStack;
    
public:

	SQLParser();

	virtual bool parse(const std::string &queryString) = 0;

    void addStatement(SQLStatement *stmt)
    {
        statements.push_back(stmt);
    }

    SQLStatement *getStatement()
    {
        if (statements.size() == 0)
            return NULL;
        return statements.at(0);
    }

    void pushNode(SQLNode *node)
    {
        parserStack.push(node);
    }

    void popNode()
    {
        parserStack.pop();
    }
    
    SQLNode *peekNode()
    {
        return parserStack.top();
    }



};

}

#endif
