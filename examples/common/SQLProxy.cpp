/******************************************************************
 *
 * uSQL for C++
 *
 * Copyright (C) Satoshi Konno 2012
 *
 * This is licensed under BSD-style license, see file COPYING.
 *
 ******************************************************************/

#include "SQLProxy.h"
#include "MD5.h"
#include "Dictionary.h"

using namespace std;
using namespace uSQL;

uSQL::SQLProxy::SQLProxy()
{
}

uSQL::SQLProxy::~SQLProxy()
{
}

bool uSQL::SQLProxy::getKey(SQLStatement *stmt, std::string &key, SQLError &error) 
{
    SQLFrom *sqlFrom = stmt->getFromNode();
    if (!sqlFrom) {
        error.setMessage("FROM section was not found");
        return false;
    }
    
    SQLNodeList *sqlDataSources = sqlFrom->getChildNodes();
    if (sqlDataSources->size() < 1) {
        error.setMessage("Data source was not found");
        return false;
    }
    if (1 < sqlDataSources->size()) {
        error.setMessage("Data source is more than one");
        return false;
    }
    
    SQLNode *dataSource = sqlDataSources->at(0);
    string tablenName = dataSource->getValue();
    
    SQLWhere *sqlWhere = stmt->getWhereNode();
    if (!sqlWhere) {
        error.setMessage("WHERE section was not found");
        return false;
    }
    
    string keyString;
    
    string tableName = dataSource->getValue();
    keyString = tableName;

    string whereString;
    sqlWhere->toString(whereString);
    keyString.append(whereString);
    
    MD5::hash(keyString, key);

    return true;
}

bool uSQL::SQLProxy::getInsertDictionary(SQLStatement *stmt, Dictionary &dictionary, SQLError &error)
{
    SQLColumn *sqlColumn = stmt->getColumnNode();
    if (!sqlColumn) {
        error.setMessage("Column section was not found");
        return false;
    }

    SQLValue *sqlValue = stmt->getValueNode();
    if (!sqlValue) {
        error.setMessage("VALUES section was not found");
        return false;
    }

    SQLNodeList *sqlColums = sqlColumn->getChildNodes();
    SQLNodeList *sqlValues = sqlValue->getChildNodes();
    
    if (sqlColums->size() != sqlValues->size()) {
        error.setMessage("List of values less than number of Columns");
        return false;
    }
    
    size_t columsCount = sqlColums->size();
    for (size_t n=0; n<columsCount; n++) {
        SQLNode *colum = sqlColums->getNode(n); 
        SQLNode *value = sqlValues->getNode(n);
        dictionary.set(colum->toString(), value->toString());
    }
    
    return true;
}

bool uSQL::SQLProxy::getUpdateDictionary(SQLStatement *stmt, Dictionary &dictionary, SQLError &error)
{
    SQLSet *sqlSet = stmt->getSetNode();
    if (!sqlSet) {
        error.setMessage("Set section was not found");
        return false;
    }

    int dictCount = sqlSet->getDictionaryCount();
    for (int n=0; n<dictCount; n++) {
        SQLDictionary *dict = sqlSet->getDictionary(n);
        string keyName = dict->getName();
        string keyValue;
        dict->getValue()->toString(keyValue);
        dictionary.set(keyName, keyValue);
    }
    
    return true;
}
