lib_LIBRARIES = libusql++.a

INCLUDES = -I$(top_builddir)/include -I$(top_builddir)/src/

########################################
# uSQL for C++
########################################

usqlcc_source = \
	../../src/usql/SQL92Parser.cpp \
	../../src/usql/SQLError.cpp \
	../../src/usql/SQLNode.cpp \
	../../src/usql/SQLNodeList.cpp \
	../../src/usql/SQLParser.cpp \
	../../src/usql/SQLStatement.cpp \
	../../src/usql/SQLStatementList.cpp \
	../../src/usql/UnQLParser.cpp \
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
	../../src/usql/parser/antlr/SQLParserFunc.cpp

libusql___a_SOURCES = \
        $(usqlcc_source)
