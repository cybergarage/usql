noinst_PROGRAMS = sqlproxy sqlproxyunittest

INCLUDES = -I$(top_srcdir)/include -I../ -I../../common

sqlproxy_core_sources = \
	../../common/MD5.cpp \
	../../common/SQLProxy.cpp \
	../../common/SQLProxyDataSet.cpp \
	../../common/SQLProxyResult.cpp \
	../MySQLProxy.cpp \
	../MemcachedProxy.cpp

sqlproxy_SOURCES = \
	$(sqlproxy_core_sources) \
	../main.cpp

sqlproxy_LDADD = ../../../lib/unix/libusql++.a -lcrypto -ledit -lmysqlclient -lmemcached

sqlproxyunittest_SOURCES = \
	$(sqlproxy_core_sources) \
	../../common/unittest/MD5Test.cpp \
	../../common/unittest/SQLProxyTest.cpp \
	../unittest/SQLProxyTestMain.cpp

sqlproxyunittest_LDADD = $(sqlproxy_LDADD) -lboost_unit_test_framework -lboost_system -lmysqlclient -lmemcached



