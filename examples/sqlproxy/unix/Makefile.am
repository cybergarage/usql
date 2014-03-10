if UNITTESTS
noinst_PROGRAMS = sqlproxy sqlproxyunittest
else
noinst_PROGRAMS = sqlproxy
endif

AM_CPPFLAGS = -I$(top_srcdir)/include -I../ -I../../common

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

sqlproxy_LDADD = ../../../lib/unix/libusql++.a

if UNITTESTS
sqlproxyunittest_SOURCES = \
	$(sqlproxy_core_sources) \
	../../common/unittest/MD5Test.cpp \
	../../common/unittest/SQLProxyTest.cpp \
	../unittest/SQLProxyTestMain.cpp

sqlproxyunittest_LDADD = $(sqlproxy_LDADD)
endif
