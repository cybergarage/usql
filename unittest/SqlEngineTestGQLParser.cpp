#include <string>
#include <boost/test/unit_test.hpp>
#include <cybergarage/sql/GQLParser.h>
#include <boost/algorithm/string.hpp>

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserTest)
{
	GQLParser gqlParser;

    //string sql = "SELECT * FROM SAMPLE";
    string sql = "SELECT * FROM SAMPLE WHERE A = B";
    
    BOOST_CHECK(gqlParser.parse(sql));
    
    string parseResult;
    gqlParser.getStatement()->toString(parseResult);
    boost::trim(parseResult);
 
    BOOST_CHECK(sql.compare(parseResult) == 0);
       
    cout << parseResult << endl;
}