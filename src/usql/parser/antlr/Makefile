all: SQLParserFunc.cpp

SQLParserFunc.cpp : SQL.g
	java -classpath ./lib/antlr-3.4-complete.jar org.antlr.Tool $<
	mv SQLLexer.c SQLLexerFunc.cpp
	mv SQLParser.c SQLParserFunc.cpp
	rm -rf output
	rm SQL.tokens

clean:
	rm -f *.cpp *.h
