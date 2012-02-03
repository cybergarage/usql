/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <boost/tokenizer.hpp>
#include "Dictionary.h"

using namespace std;
using namespace boost;
using namespace uSQL;

#define USQL_DICTIONARY_SERIALIZE_MAP_SEP "\t"
#define USQL_DICTIONARY_SERIALIZE_VALUE_SEP "\r"

uSQL::Dictionary::Dictionary()
{
}

uSQL::Dictionary::~Dictionary()
{
}

bool uSQL::Dictionary::parse(const std::string &aString)
{
    char_separator<char> valueSep(USQL_DICTIONARY_SERIALIZE_VALUE_SEP);
    tokenizer< char_separator<char> > values(aString, valueSep);
    for (tokenizer< char_separator<char> >::iterator value = values.begin(); value != values.end(); value++) {
        char_separator<char> mapSep(USQL_DICTIONARY_SERIALIZE_MAP_SEP);
        tokenizer< char_separator<char> > maps(*value, mapSep);
        tokenizer< char_separator<char> >::iterator map = maps.begin();
        if (map == maps.end())
            continue;
        string keyName = *map;
        map++;
        if (map == maps.end())
            continue;
        string keyValue = *map;
        insert(pair<string, string>(keyName, keyValue));
    }
    return true;
}
    
std::string &uSQL::Dictionary::toString(std::string &buf)
{
    buf = "";
    for (Dictionary::iterator dict = begin(); dict != end(); dict++) {
        buf.append((*dict).first);
        buf.append(USQL_DICTIONARY_SERIALIZE_MAP_SEP);
        buf.append((*dict).second);
        buf.append(USQL_DICTIONARY_SERIALIZE_VALUE_SEP);
    }
    
    return buf;
}
