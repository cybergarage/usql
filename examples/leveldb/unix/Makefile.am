noinst_PROGRAMS = leveldb leveldbunittest

INCLUDES = -I$(top_srcdir)/include -I../ -I../../common

leveldb_core_sources = \
	../../common/MD5.cpp \
	../../common/SQLProxy.cpp \
	../../common/SQLProxyDataSet.cpp \
	../../common/SQLProxyResult.cpp \
	../LevelDBProxy.cpp

leveldb_SOURCES = \
	$(leveldb_core_sources) \
	../main.cpp

leveldb_LDADD = ../../../lib/unix/libusql++.a -lcrypto -ledit -lleveldb

leveldbunittest_SOURCES = \
	$(leveldb_core_sources) \
	../../common/unittest/MD5Test.cpp \
	../../common/unittest/SQLProxyTest.cpp \
	../unittest/LevelDBTestMain.cpp \
	../unittest/LevelDBTest.cpp \
	../unittest/LevelDBSQLTest.cpp \
	../unittest/LevelDBSQLKeyTest.cpp

leveldbunittest_LDADD = $(leveldb_LDADD) -lboost_unit_test_framework -lboost_system -lboost_filesystem



