/******************************************************************
*
* uSQL for C++
*
* SQLExpressions.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLEXPRESSIONS_H
#define CG_USQL_SQLEXPRESSIONS_H

#include <vector>

namespace uSQL {

class SQLExpression;

class SQLExpressions : public std::vector<SQLExpression*> {

public:

	SQLExpressions() {
    }
    
	~SQLExpressions();
    
    void addExpression(SQLExpression *expr)
    {
        push_back(expr);
    }

    SQLExpression *getExpression(int index)
    {
        return at(index);
    }

};

}

#endif
