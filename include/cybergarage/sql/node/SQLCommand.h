/******************************************************************
*
* uSQL for C++
*
* SQLCommand.h
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#ifndef CG_USQL_SQLCOMMAND_H
#define CG_USQL_SQLCOMMAND_H

#include <cybergarage/sql/SQLNode.h>

namespace uSQL {

class SQLCommand : public SQLNode {

public:

    static const int UNKOWN;
    static const int SELECT;
    static const int UPDATE;
    static const int INSERT;
    static const int DELETE;

private:

    int commandType;
    
public:

	SQLCommand() {
    	setType(COMMAND);
    }

    void setCommandType(int commandType) {
        this->commandType = commandType;
    }

    int getCommandType() {
        return this->commandType;
    }
};

class SQLSelect : public SQLCommand {

public:

	SQLSelect() {
    	setCommandType(SELECT);
    }

    std::string &toString(std::string &buf) {
    	buf = "SELECT";
        return buf;
    }
};

}

#endif
