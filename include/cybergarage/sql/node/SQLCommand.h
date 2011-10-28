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
    static const int CREATE;
    static const int DROP;

private:

    int commandType;
	bool asyncFlag;
        
public:

	SQLCommand() {
    	setType(COMMAND);
        setAsyncEnabled(false);
    }

    void setCommandType(int commandType) {
        this->commandType = commandType;
    }

    int getCommandType() {
        return this->commandType;
    }

    void setAsyncEnabled(bool asyncFlag) {
        this->asyncFlag = asyncFlag;
    }

    bool isAsync() {
        return this->asyncFlag;
    }

    bool isSync() {
        return !this->asyncFlag;
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

class SQLUpdate : public SQLCommand {

public:

	SQLUpdate() {
    	setCommandType(UPDATE);
    }

    std::string &toString(std::string &buf) {
    	buf = "UPDATE";
        return buf;
    }
};

class SQLInsert : public SQLCommand {

public:

	SQLInsert() {
    	setCommandType(INSERT);
    }

    std::string &toString(std::string &buf) {
    	buf = "INSERT INTO";
        return buf;
    }
};

class SQLDelete : public SQLCommand {

public:

	SQLDelete() {
    	setCommandType(DELETE);
    }

    std::string &toString(std::string &buf) {
    	buf = "DELETE";
        return buf;
    }
};

class SQLCreate : public SQLCommand {

public:

	SQLCreate() {
    	setCommandType(CREATE);
    }

    std::string &toString(std::string &buf) {
    	buf = "CREATE COLLECTION";
        return buf;
    }
};

class SQLDrop : public SQLCommand {

public:

	SQLDrop() {
    	setCommandType(DROP);
    }

    std::string &toString(std::string &buf) {
    	buf = "DROP COLLECTION";
        return buf;
    }
};

}

#endif
