all: SQL92Lexer.h

SQL92Lexer.h : SQL92.g
	java -classpath ./antlr-3.4-complete.jar org.antlr.Tool -verbose SQL92.g

clean:
	rm -f *.cpp *.h

