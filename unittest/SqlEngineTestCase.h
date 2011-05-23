#ifndef CPP_UNIT_SQLENGINETESTCASE_H
#define CPP_UNIT_SQLENGINETESTCASE_H

#include <cppunit/extensions/HelperMacros.h>

class SqlEngineTestCase : public CPPUNIT_NS::TestFixture
{
  CPPUNIT_TEST_SUITE( SqlEngineTestCase );

  /*
  CPPUNIT_TEST( testDictionary );
  CPPUNIT_TEST( testURI );
  CPPUNIT_TEST( testNetworkInterface );
  CPPUNIT_TEST( testHttpServer );
  CPPUNIT_TEST( testDevice );
  CPPUNIT_TEST( testControlPoint );
  */
  CPPUNIT_TEST_SUITE_END();

public:

	void setUp();
	void tearDown();

protected:

	void testParser();
	void testQuery();
	/*
	void testURI();
	void testNetworkInterface();
	void testHttpServer();
	void testDevice();
	void testControlPoint();
	void testSubscription();
	void testStateVariable();
	*/
};

#endif
