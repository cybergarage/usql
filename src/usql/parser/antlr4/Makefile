.PHONY: antlr clean

all: antlr

antlr:
	antlr4 -package uSQL::ANTLR4 -Dlanguage=Cpp SQL92.g4

clean:
	rm -f *.cpp *.h *.interp *.tokens
