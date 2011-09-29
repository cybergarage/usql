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
#include <cybergarage/sql/SQLNodes.h>

namespace uSQL {

class SQLParser {

private:

    std::vector<SQLStatement *> statements;
    
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

};

}

#endif
