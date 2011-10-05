all: SQL92Parser.cpp GQLParser.cpp UnQLParser.cpp

SQL92Parser.cpp : SQL92.g
	java -classpath ./lib/antlr-3.4-complete.jar org.antlr.Tool $<
	mv SQL92Lexer.c SQL92Lexer.cpp
	mv SQL92Parser.c SQL92Parser.cpp

GQLParser.cpp : GQL.g
	java -classpath ./lib/antlr-3.4-complete.jar org.antlr.Tool $<
	mv GQLLexer.c GQLLexer.cpp
	mv GQLParser.c GQLParser.cpp

UnQLParser.cpp : UnQL.g
	java -classpath ./lib/antlr-3.4-complete.jar org.antlr.Tool $<
	mv UnQLLexer.c UnQLLexer.cpp
	mv UnQLParser.c UnQLParser.cpp

clean:
	rm -f *.cpp *.h
	rm -rf output
	rm SQL92.tokens
	rm GQL.tokens
	rm UnQL.tokens
