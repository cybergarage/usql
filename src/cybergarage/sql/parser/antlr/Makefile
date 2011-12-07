all: SQLParser.cpp

SQLParser.cpp : SQL.g
	java -classpath ./lib/antlr-3.4-complete.jar org.antlr.Tool $<
	mv SQLLexer.c SQLLexer.cpp
	mv SQLParser.c SQLParser.cpp
	rm -rf output
	rm SQL.tokens

clean:
	rm -f *.cpp *.h
