noinst_PROGRAMS = usqlcctestunit

AM_CPPFLAGS = -I$(top_srcdir)/include -I../

usqlcctestunit_SOURCES = \
	../SqlEngineTestBase.cpp \
	../SqlEngineTestCase.cpp \
	../SqlEngineTestCaseReader.cpp \
	../SqlEngineTestExpression.cpp \
	../SqlEngineTestGQLParser.cpp \
	../SqlEngineTestMain.cpp \
	../SqlEngineTestSQL92Parser.cpp \
	../SqlEngineTestUnQLParser.cpp

usqlcctestunit_LDADD = ../../lib/unix/libusql++.a -lboost_unit_test_framework
