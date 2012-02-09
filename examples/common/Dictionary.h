/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_DICTIONARY_H
#define CG_USQL_DICTIONARY_H

#include <map>
#include <string>

namespace uSQL {

class Dictionary : public std::map<std::string, std::string> {

private:

    std::string dictionaryString;
    
public:

	Dictionary();
    virtual ~Dictionary();

	bool parse(const std::string &aString);
    
    void set(const std::string &keyName, const std::string &keyValue);
    const std::string &get(std::string &keyName);
    
    std::string &toString(std::string &buf);
    
    const std::string &toString() {
        return toString(this->dictionaryString);
    }
};

}

#endif
