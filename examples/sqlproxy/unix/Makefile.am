noinst_PROGRAMS = sqlproxy sqlproxyunittest

INCLUDES = -I$(top_srcdir)/include -I../ -I../../common

sqlproxy_core_sources = \
	../../common/MD5.cpp \
	../../common/SQLProxy.cpp \
	../../common/SQLProxyDataSet.cpp \
	../../common/SQLProxyResult.cpp

sqlproxy_SOURCES = \
	$(sqlproxy_core_sources) \
	../main.cpp

sqlproxy_LDADD = ../../../lib/unix/libusql++.a -lantlr3c -lcrypto -ledit

sqlproxyunittest_SOURCES = \
	$(sqlproxy_core_sources) \
	../../common/unittest/MD5Test.cpp \
	../../common/unittest/SQLProxyTest.cpp \
	../unittest/SQLProxyTestMain.cpp

sqlproxyunittest_LDADD = $(sqlproxy_LDADD) -lboost_unit_test_framework -lboost_system



