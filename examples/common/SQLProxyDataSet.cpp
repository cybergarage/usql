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
#include "SQLProxyDataSet.h"

using namespace std;
using namespace boost;
using namespace uSQL;

#define USQL_DICTIONARY_SERIALIZE_MAP_SEP "\t"
#define USQL_DICTIONARY_SERIALIZE_VALUE_SEP "\r"

uSQL::SQLProxyDataSet::SQLProxyDataSet()
{
}

uSQL::SQLProxyDataSet::~SQLProxyDataSet()
{
}

bool uSQL::SQLProxyDataSet::parse(const std::string &aString)
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
        set(keyName, keyValue);
    }
    return true;
}

void uSQL::SQLProxyDataSet::set(const std::string &keyName, const std::string &keyValue) 
{
    insert(std::pair<std::string, std::string>(keyName, keyValue));
}
    
const std::string &uSQL::SQLProxyDataSet::get(std::string &keyName) 
{
    static std::string nullValue;
    SQLProxyDataSet::iterator dict = find(keyName);
    if (dict != end())
        return nullValue;
    return (*dict).second;
}
    
std::string &uSQL::SQLProxyDataSet::toString(std::string &buf)
{
    buf = "";
    for (SQLProxyDataSet::iterator dict = begin(); dict != end(); dict++) {
        buf.append((*dict).first);
        buf.append(USQL_DICTIONARY_SERIALIZE_MAP_SEP);
        buf.append((*dict).second);
        buf.append(USQL_DICTIONARY_SERIALIZE_VALUE_SEP);
    }
    
    return buf;
}

