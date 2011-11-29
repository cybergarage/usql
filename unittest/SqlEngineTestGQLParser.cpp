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

#include <cybergarage/sql/GQLParser.h>

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserGQLTest)
{
	vector<string> gqlStrings;
 
    /*   
    gqlStrings.push_back("SELECT * FROM SAMPLE1");
    gqlStrings.push_back("SELECT * FROM SAMPLE2 WHERE A = B");
    gqlStrings.push_back("SELECT * FROM SAMPLE3 LIMIT 10");
	*/
    
	vector<string>::iterator gqlString = gqlStrings.begin();
	while(gqlString != gqlStrings.end()) {
    	
        cout << "I : " << *gqlString << endl;
        
        GQLParser gqlParser;
	    BOOST_CHECK(gqlParser.parse(*gqlString));
        
	    string parseResult;
	    gqlParser.getStatement()->toString(parseResult);
	    boost::trim(parseResult);
        
        cout << "O : " << parseResult << endl;
        
	    BOOST_CHECK(parseResult.compare(*gqlString) == 0);
        
		gqlString++;
	}
}