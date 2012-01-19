//
//  main.cpp
//  leveldb
//
//  Created by  on 11/10/13.
//  Copyright (c) 2011 __MyCompanyName__. All rights reserved.
//

#include <stdlib.h>
#include <unistd.h>
#include <histedit.h>
#include <leveldb/db.h>

#include <cybergarage/sql/UnQLParser.h>

using namespace std;
using namespace uSQL;

const char * prompt(EditLine *e);
void testfunction();
void usage();
void ExecSQLStatement(SQLStatement *stmt);
void OutputSQLError(const char *errMsg);

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

void usage()
{
    cout << "Usage: leveldb [OPTIONS] FILE" << endl;
    cout << "Miscellaneous:" << endl;
    cout << "-h\tproduce this help message:" << endl;
}

void OutputSQLError(const char *errMsg) 
{
    cout << "SQL Error : "<< errMsg << " !!" << endl;
}

void ExecSQLStatement(SQLStatement *stmt) 
{
    SQLCommand *sqlCmd = stmt->getCommandNode();
    if (!sqlCmd) {
        OutputSQLError("COMMAND section was not found");
        return;
    }
    
    if (!sqlCmd->isSelect() && !sqlCmd->isInsert() && !sqlCmd->isUpdate() && !sqlCmd->isDelete()) {
        OutputSQLError("Invalid command");
        return;
    }

    SQLFrom *sqlFrom = stmt->getFromNode();
    if (!sqlFrom) {
        OutputSQLError("FROM section was not found");
        return;
    }
    
    SQLNodeList *sqlDataSources = sqlFrom->getChildNodes();
    if (sqlDataSources->size() < 1) {
        OutputSQLError("Data souce was not found");
        return;
    }
    
    SQLNode *dataSource = sqlDataSources->at(0);
    string tablenName = dataSource->getValue();
    
    SQLWhere *sqlWhere = stmt->getWhereNode();
    if (!sqlWhere) {
        OutputSQLError("WHERE section was not found");
        return;
    }
    
    cout << "Done." << endl;
}

int main(int argc, char *argv[]) 
{
    string dbFilename;
    
    int ch;
    while ((ch = getopt(argc, argv, "hf:")) != -1) {
        switch (ch) {
        case 'h':
            {
                usage();
                exit(EXIT_SUCCESS);
            }
            break;
        case 'f':
            {
                dbFilename = optarg;
            }
            break;
        case '?':
        default:
            {
                usage();
                exit(EXIT_SUCCESS);
            }
        }
     }
     
    //argc -= optind;
    //argv += optind;
    
    if (argc <= 0) {
        cout << "leveldb: missing operand after `leveldb'" << endl;
        cout << "Try `leveldb --help' for more information." << endl;
        //exit(EXIT_FAILURE);
    }
    
    dbFilename = "/tmp/testdb";
    
    leveldb::DB* db;
    leveldb::Options options;
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, dbFilename, &db);    
    status.ok();
    
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

        UnQLParser unqlParser;
        if (unqlParser.parse(line) == false) {
            printf("Parser Error :  %s\n", line);
            continue;
        }
        
        SQLStatementList *stmtList = unqlParser.getStatements();
        for (SQLStatementList::iterator stmt = stmtList->begin(); stmt != stmtList->end(); stmt++) {
            ExecSQLStatement(*stmt);
        }
	}

	/* Clean up our memory */
	history_end(myhistory);
	el_end(el);
	
	
	return EXIT_SUCCESS;
}