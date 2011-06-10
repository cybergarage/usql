all: SQLParser.tab.cpp SQLParser.yy.cpp

SQLParser.tab.cpp: SQLParser.y
	bison -dv SQLParser.y -o $@
	rm SQLParser.output

SQLParser.yy.cpp: SQLParser.l SQLParser.tab.cpp
	flex -o $@ -I SQLParser.l

clean:
	rm -f *.cpp *.hpp *.output

