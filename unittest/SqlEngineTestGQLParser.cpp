#include <string>
#include <boost/test/unit_test.hpp>
#include <cybergarage/sql/GQLParser.h>

using namespace std;
using namespace uSQL;

BOOST_AUTO_TEST_CASE(SQLParserTest)
{
	GQLParser gqlParser;
    
    BOOST_CHECK(gqlParser.parse("SELECT * FROM SAMPLE"));
    string buf;
    gqlParser.getStatement()->toString(buf);
    cout << buf << endl;
}