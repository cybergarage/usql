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

#include <usql/SQL92Parser.h>

using namespace std;
using namespace uSQL;

const char * prompt(EditLine *e) 
{
	return "usql> ";
}

int main(int argc, char *argv[]) 
{
    string pgName;
    string dbFilename;
    
    pgName =argv[0];
    
	/* Initialize the EditLine */
	EditLine *el = el_init(pgName.c_str(), stdin, stdout, stderr);
	el_set(el, EL_PROMPT, &prompt);
	el_set(el, EL_EDITOR, "vi");
	
	/* Initialize the history */
	HistEvent ev;
	History *inputHistory = history_init();
	history(inputHistory, &ev, H_SETSIZE, 1024);
	el_set(el, EL_HIST, history, inputHistory);
	
	while (true) {
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
            string stmtString;
            string stmtTreeString;
            (*stmt)->toString(stmtString);
            (*stmt)->toTreeString(stmtTreeString);
            cout << stmtString << endl;
            cout << stmtTreeString << endl;;
        }
	}
    
	history_end(inputHistory);
	el_end(el);
		
	return EXIT_SUCCESS;
}