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
#include "MySQLProxy.h"

using namespace std;
using namespace uSQL;

const char * prompt(EditLine *e);
void usage();
void OutputSQLError(const std::string &errMsg);

const char * prompt(EditLine *e) 
{
  return "sqlproxy> ";
}

void usage()
{
  cout << "Usage: sqlproxy [OPTIONS] FILE" << endl;
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
  string serverName;
  string dbName;
  string userName;
  string password;
  
  int ch;
  while ((ch = getopt(argc, argv, "d:s:u:p:")) != -1) {
    switch (ch) {
    case 'd':
      {
        dbName = optarg;
      }
      break;
    case 's':
      {
        serverName = optarg;
      }
      break;
    case 'u':
      {
        userName = optarg;
      }
      break;
    case 'p':
      {
        password = optarg;
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

  if (serverName.length() <= 0)
    serverName = "localhost";

  cout << "Server   : " << serverName << endl;
  cout << "User   : " << userName << endl;
  cout << "Database : " << dbName << endl;

  MySQLProxy *sqlProxy = new MySQLProxy();
  if (sqlProxy->connect(serverName, userName, password, dbName) == false) {
    cout << "Could not open " << serverName << ":" << dbName << endl;
    exit(EXIT_FAILURE);
  }
  
          
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
      if (sqlProxy->query(*stmt, sqlResult) == true) {
        if (sqlResult.hasMessage())
          cout << sqlResult.getExecMessage() << endl;
        SQLProxyDataSet *resultSet = sqlResult.getResultSet();
        if (0 < resultSet->size()) {
          for (map<string, string>::iterator data = resultSet->begin(); data != resultSet->end(); data++) {
            string key = data->first;
            string value = data->second;
            cout << "[" << key << "]" << " = " << value << endl;
          }
        }
        cout << "Done" << (sqlResult.isCashed() ? "(Cashed)" : "") << "." << endl;
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
  
  delete sqlProxy;
  
  return EXIT_SUCCESS;
}
