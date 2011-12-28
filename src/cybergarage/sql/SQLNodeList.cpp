/******************************************************************
*
* uSQL for C++
*
* SQLNodeList.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include<sstream>

#include <cybergarage/sql/SQLNode.h>

void uSQL::SQLNodeList::sort()
{
	std::string buf; 
    int n=0;
    std::size_t l = size();
    if (l <= 1)
    	return;
    for (uSQL::SQLNodeList::iterator node = begin(); node != end(); node++) {
    	std::cout << "SORT[" << (++n) << "] : " << (*node)->toString(buf) << std::endl;
    }
}
