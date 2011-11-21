/******************************************************************
*
* uSQL for C++
*
* SQLExpression.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <cybergarage/sql/node/SQLExpression.h>

std::string &uSQL::SQLExpression::toString(std::string &buf) 
{
	std::size_t expressionsCount = expressions.size();
    
    if (expressionsCount <= 0) {
    	buf = "";
    	return buf;
    }
        
	bool hasDictionary = false;
    for (SQLExpressions::iterator expr=expressions.begin(); expr != expressions.end(); expr++) {
    	if ((*expr)->isDictionary() == true) {
        	hasDictionary = true;
            break;
        }
    }

	std::ostringstream oss;
	oss << "OFFSET " << this->value;
        
	if (hasDictionary) {
    	oss << "{";
	    for (SQLExpressions::iterator expr=expressions.begin(); expr != expressions.end(); expr++) {
    		if (expr != expressions.begin())
		    	oss << ",";
            oss << (*expr)->getName() << ": " << (*expr)->getValue();
    	}
    	oss << "}";
    }
    else {
    	oss << "[";
	    for (SQLExpressions::iterator expr=expressions.begin(); expr != expressions.end(); expr++) {
    		if (expr != expressions.begin())
		    	oss << ",";
            oss << (*expr)->getValue();
    	}
    	oss << "]";
    }
    
    buf = oss.str();
    return buf;
}
