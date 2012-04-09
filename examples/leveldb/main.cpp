/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <histedit.h>
#include <leveldb/db.h>

#include <usql/SQL92Parser.h>
#include "LevelDBProxy.h"

using namespace std;
using namespace uSQL;

const char * prompt(EditLine *e);
void usage();
void OutputSQLError(const std::string &errMsg);

const char * prompt(EditLine *e) 
{
	return "leveldb> ";
}

void usage()
{
    cout << "Usage: leveldb [OPTIONS] FILE" << endl;
    cout << "Miscellaneous:" << endl;
    cout << "-h\tproduce this help message:" << endl;
}

void OutputSQLError(const std::string &errMsg) 
{
    cout << "SQL Error : "<< errMsg << " !!" << endl;
}

int main(int argc, char *argv[]) 
{
    string pgName;
    string dbFilename;
    
    int ch;
    while ((ch = getopt(argc, argv, "hf:")) != -1) {
        switch (ch) {
        case 'f':
            {
                dbFilename = optarg;
            }
            break;
        case '?':
        case 'h':
        default:
            {
                usage();
                exit(EXIT_SUCCESS);
            }
        }
     }
    
    pgName = argv[0];
    argc -= optind;
    argv += optind;

#if !defined(DEBUG)    
    if (argc <= 0) {
        cout << "leveldb: missing operand after `leveldb'" << endl;
        cout << "Try `leveldb --help' for more information." << endl;
        exit(EXIT_FAILURE);
    }
    else
        dbFilename = argv[0];
#endif
    
    if (dbFilename.length() <= 0)
        dbFilename = "/tmp/testdb";

    LevelDBProxy levelDb;
    if (levelDb.open(dbFilename) == false) {
        cout << "Could not open " << dbFilename << endl;
        exit(EXIT_FAILURE);
    }
    
    cout << "Filename : " << dbFilename << endl;
                    
	/* Initialize the EditLine */
	EditLine *el = el_init(pgName.c_str(), stdin, stdout, stderr);
	el_set(el, EL_PROMPT, &prompt);
	el_set(el, EL_EDITOR, "vi");
	
	/* Initialize the history */
	HistEvent ev;
	History *inputHistory = history_init();
	history(inputHistory, &ev, H_SETSIZE, 1024);
	el_set(el, EL_HIST, history, inputHistory);
	
	int keepreading = 1;
	while (keepreading) {
        int readCount = 0;
		const char *inputLine = el_gets(el, &readCount);
		if (readCount <= 0)
            continue;
            
        history(inputHistory, &ev, H_ENTER, inputLine);

        SQL92Parser sqlParser;
        if (sqlParser.parse(inputLine) == false) {
            SQLError *sqlError = sqlParser.getError();
            cout << "Parser Error :  " << inputLine;
            cout << "  Line = " << sqlError->getLine() << ", Offset = " << sqlError->getOffset() << endl;
            continue;
        }
        
        SQLStatementList *stmtList = sqlParser.getStatements();
        for (SQLStatementList::iterator stmt = stmtList->begin(); stmt != stmtList->end(); stmt++) {
            SQLProxyResult sqlResult;
            if (levelDb.query(*stmt, sqlResult) == true) {
                if (sqlResult.hasMessage())
                    cout << sqlResult.getExecMessage() << endl;
                SQLProxyDataSet *resultSet = sqlResult.getResultSet();
                for (map<string, string>::iterator data = resultSet->begin(); data != resultSet->end(); data++) {
                    string key = data->first;
                    string value = data->second;
                    cout << "[" << key << "]" << " = " << value << endl;
                }
                cout << "Done." << endl;
                cout << endl;
            }
            else {
                OutputSQLError(sqlResult.getErrorMessage());
                continue;
            }
        }
	}
    
	history_end(inputHistory);
	el_end(el);
		
	return EXIT_SUCCESS;
}