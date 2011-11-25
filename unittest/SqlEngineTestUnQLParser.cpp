/******************************************************************
*
* uSQL for C++
*
* SQLEngineTestGQLParser.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <string>
#include <vector>

#include <boost/test/unit_test.hpp>
#include <boost/algorithm/string.hpp>

#include <cybergarage/sql/UnQLParser.h>

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserUnQLTest)
{
	vector<string> unqlStrings;
    
	unqlStrings.push_back("CREATE COLLECTION abc");
	unqlStrings.push_back("CREATE COLLECTION def");
    
    unqlStrings.push_back("INSERT INTO abc VALUE 1234");
    unqlStrings.push_back("INSERT INTO abc VALUE 3.141592653");
    unqlStrings.push_back("INSERT INTO abc VALUE \"This is a string\"");
    unqlStrings.push_back("INSERT INTO abc VALUE [\"this\",\"is\",\"an\",\"array\"]");
    unqlStrings.push_back("INSERT INTO abc VALUE {type:\"message\",content:\"This is an object\"}");
    
    unqlStrings.push_back("SELECT FROM abc");
    unqlStrings.push_back("SELECT a FROM abc");
    unqlStrings.push_back("SELECT MAX(a) FROM abc");
    unqlStrings.push_back("SELECT {x:abc.type,y:abc.content.x,z:abc.content.x} FROM abc");
    //unqlStrings.push_back("SELECT { x:abc.type, y:abc.content.x, z:abc.content.x+50 } FROM abc;");
    unqlStrings.push_back("SELECT FROM abc WHERE abc.type==\"message\"");

	vector<string>::iterator unqlString = unqlStrings.begin();
	while(unqlString != unqlStrings.end()) {
    	
        cout << "I : " << *unqlString << endl;
        
        UnQLParser unqlParser;
	    BOOST_CHECK(unqlParser.parse(*unqlString));
        
	    string parseResult;
	    unqlParser.getStatement()->toString(parseResult);
	    boost::trim(parseResult);
        
        cout << "O : " << parseResult << endl;
        
	    BOOST_CHECK(parseResult.compare(*unqlString) == 0);
        
		unqlString++;
	}
}