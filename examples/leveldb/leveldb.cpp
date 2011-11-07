//
//  main.cpp
//  leveldb
//
//  Created by  on 11/10/13.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <histedit.h>
#include <leveldb/db.h>

#include <cybergarage/sql/UnQLParser.h>

using namespace std;
using namespace uSQL;

const char * prompt(EditLine *e);
void testfunction();

const char * prompt(EditLine *e) 
{
	return "leveldb> ";
}

void testfunction()
{
  leveldb::DB* db;
  leveldb::Options options;
  options.create_if_missing = true;
  leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);
//  assert(status.ok());
}

int main(int argc, char *argv[]) {
	
    UnQLParser unqlParser;

	/* This holds all the state for our line editor */
	EditLine *el;
	
	/* This holds the info for our history */
	History *myhistory;
	
	/* Temp variables */
	int count;
	const char *line;
	int keepreading = 1;
	HistEvent ev;
	
	/* Initialize the EditLine state to use our prompt function and
	 emacs style editing. */
    
	el = el_init(argv[0], stdin, stdout, stderr);
	el_set(el, EL_PROMPT, &prompt);
	el_set(el, EL_EDITOR, "emacs");
	
	/* Initialize the history */
	myhistory = history_init();
	if (myhistory == 0) {
		fprintf(stderr, "history could not be initialized\n");
		return 1;
	}
	
	/* Set the size of the history */
	history(myhistory, &ev, H_SETSIZE, 800);
	
	/* This sets up the call back functions for history functionality */
	el_set(el, EL_HIST, history, myhistory);
	
	while (keepreading) {
		/* count is the number of characters read.
		 line is a const char* of our command line with the tailing \n */
		line = el_gets(el, &count);
		
		/* In order to use our history we have to explicitly add commands
		 to the history */
		if (count <= 0)
            continue;
            
        history(myhistory, &ev, H_ENTER, line);
        printf("You typed \"%s\"\n", line);

        UnQLParser unqlParser;
        unqlParser.parse(line);
        
        /*
	    string parseResult;
	    unqlParser.getStatement()->toString(parseResult);
	    boost::trim(parseResult);
        */
	}

	/* Clean up our memory */
	history_end(myhistory);
	el_end(el);
	
	
	return 0;
}