/******************************************************************
*
* uSQL for C++
*
* SQLDictionary.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLDICTIONARY_H
#define CG_USQL_SQLDICTIONARY_H

#include <cybergarage/sql/node/SQLValue.h>

namespace uSQL {

class SQLDictionary : public SQLValue {

public:

	SQLDictionary() {
    	setType(DICTIONARY);
    }

    std::string &toString(std::string &buf) {
		std::ostringstream oss;
        oss << "VALUE " << getValue();
		buf = oss.str();
        return buf;
    }
};

}

#endif
