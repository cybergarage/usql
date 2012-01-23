/******************************************************************
*
* uSQL for C++
*
* SQLOption.h
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLOPTION_H
#define CG_USQL_SQLOPTION_H

#include <cybergarage/sql/node/SQLExpression.h>

namespace uSQL {

class SQLOption : public SQLExpression {

public:

	SQLOption() {
    	setType(OPTION);
    }
    
    std::string &toString(std::string &buf) {
    	std::string exprString;
		std::ostringstream oss;
        oss << "OPTION " << SQLExpression::toString(exprString) ;
		buf = oss.str();
        return buf;
    }
};

}

#endif
