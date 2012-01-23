/******************************************************************
*
* uSQL for C++
*
* SQLCommand.h
*
* Copyright (C) Satoshi Konno 2012
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
    static const int CREATE_INDEX;
    static const int DROP_INDEX;

private:

    int commandType;
	bool asyncFlag;
        
public:

	SQLCommand() {
    	setType(COMMAND);
        setAsyncEnabled(false);
    }

    void setCommandType(int commandType);

    int getCommandType() {
        return this->commandType;
    }

    bool isCommandType(int type) {
        return (this->commandType == type) ? true : false;
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
    
    bool isSelect() {
        return isCommandType(SELECT);
    }

    bool isUpdate() {
        return isCommandType(UPDATE);
    }

    bool isInsert() {
        return isCommandType(INSERT);
    }

    bool isDelete() {
        return isCommandType(DELETE);
    }
    
    bool isCreate() {
        return isCommandType(CREATE);
    }

    bool isDrop() {
        return isCommandType(DROP);
    }
    
    bool isCreateIndex() {
        return isCommandType(CREATE_INDEX);
    }
    
    bool isDropIndex() {
        return isCommandType(DROP_INDEX);
    }
};

class SQLSelect : public SQLCommand {

public:

	SQLSelect() {
    	setCommandType(SELECT);
    }
};

class SQLUpdate : public SQLCommand {

public:

	SQLUpdate() {
    	setCommandType(UPDATE);
    }

};

class SQLInsert : public SQLCommand {

public:

	SQLInsert() {
    	setCommandType(INSERT);
    }
};

class SQLDelete : public SQLCommand {

public:

	SQLDelete() {
    	setCommandType(DELETE);
    }
};

class SQLCreate : public SQLCommand {

public:

	SQLCreate() {
    	setCommandType(CREATE);
    }
};

class SQLDrop : public SQLCommand {

public:

	SQLDrop() {
    	setCommandType(DROP);
    }
};

class SQLCreateIndex : public SQLCommand {

public:

	SQLCreateIndex() {
    	setCommandType(CREATE_INDEX);
    }
};

class SQLDropIndex : public SQLCommand {

public:

	SQLDropIndex() {
    	setCommandType(DROP_INDEX);
    }
};

}

#endif
