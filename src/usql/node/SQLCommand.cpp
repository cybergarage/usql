/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <usql/node/SQLCommand.h>

const int uSQL::SQLCommand::UNKOWN = -1;
const int uSQL::SQLCommand::SELECT = 0;
const int uSQL::SQLCommand::UPDATE = 1;
const int uSQL::SQLCommand::INSERT = 2;
const int uSQL::SQLCommand::DELETE = 3;
const int uSQL::SQLCommand::CREATE = 4;
const int uSQL::SQLCommand::DROP = 5;
const int uSQL::SQLCommand::CREATE_INDEX = 6;
const int uSQL::SQLCommand::DROP_INDEX = 7;

void uSQL::SQLCommand::setCommandType(int commandType) 
{
    this->commandType = commandType;
    
    std::string commandValue = "";
    
    switch (this->commandType) {
	case SELECT:
		commandValue = "SELECT";
    	break;
	case UPDATE:
		commandValue = "UPDATE";
    	break;
	case INSERT:
		commandValue = "INSERT INTO";
    	break;
	case DELETE:
		commandValue = "DELETE FROM";
    	break;
	case CREATE:
		commandValue = "CREATE COLLECTION";
    	break;
	case DROP:
		commandValue = "DROP COLLECTION";
    	break;
	case CREATE_INDEX:
		commandValue = "CREATE INDEX";
    	break;
	case DROP_INDEX:
		commandValue = "DROP INDEX";
    	break;
	}
    
    setValue(commandValue);
}
