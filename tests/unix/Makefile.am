##################################################################
#
# uSQL for C++
#
# Copyright (C) Satoshi Konno 2015
#
# This is licensed under BSD-style license, see file COPYING.
#
##################################################################

TESTS = usqltest

check_PROGRAMS = usqltest

AM_CPPFLAGS = -I$(top_srcdir)/include -I$(top_srcdir)/src -I../
	..//SqlEngineTestCase.h \
	..//SqlEngineTestCaseReader.h \
	..//SqlEngineTestParser.h \
	..//SqlEngineTestStatements.h

usqltest_SOURCES = \
	..//SqlEngineTestBase.cpp \
	..//SqlEngineTestCase.cpp \
	..//SqlEngineTestCaseReader.cpp \
	..//SqlEngineTestExpression.cpp \
	..//SqlEngineTestGQLParser.cpp \
	..//SqlEngineTestMain.cpp \
	..//SqlEngineTestSQL92Parser.cpp \
	..//SqlEngineTestUnQLParser.cpp

usqltest_LDADD = ../../lib/unix/libusql++.a -lboost_unit_test_framework
