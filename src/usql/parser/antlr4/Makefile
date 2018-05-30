.PHONY: antlr clean

all: antlr

antlr: SQL.g4
	antlr4 -Dlanguage=Cpp SQL.g4

clean:
	rm -f *.cpp *.h *.interp *.tokens
