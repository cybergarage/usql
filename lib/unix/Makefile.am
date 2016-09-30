##################################################################
#
# uSQL for C++
#
# Copyright (C) Satoshi Konno 2012
#
# This is licensed under BSD-style license, see file COPYING.
#
##################################################################

lib_LIBRARIES = libusql++.a

AM_CFLAGS = -I$(top_builddir)/include -I$(top_builddir)/src

usqlcc_sources = \
	../../src/usql/GQLParser.cpp \
	../../src/usql/node/SQLColumns.cpp \
	../../src/usql/node/SQLCommand.cpp \
	../../src/usql/node/SQLDictionary.cpp \
	../../src/usql/node/SQLExpression.cpp \
	../../src/usql/node/SQLOperator.cpp \
	../../src/usql/node/SQLOrder.cpp \
	../../src/usql/node/SQLSet.cpp \
	../../src/usql/node/SQLValues.cpp \
	../../src/usql/parser/antlr/SQLLexerFunc.cpp \
	../../src/usql/parser/antlr/SQLParserFunc.cpp \
	../../src/usql/SQL92Parser.cpp \
	../../src/usql/SQLError.cpp \
	../../src/usql/SQLNode.cpp \
	../../src/usql/SQLNodeList.cpp \
	../../src/usql/SQLParser.cpp \
	../../src/usql/SQLStatement.cpp \
	../../src/usql/SQLStatementList.cpp \
	../../src/usql/UnQLParser.cpp

libusql___a_SOURCES = \
    $(usqlcc_sources)
