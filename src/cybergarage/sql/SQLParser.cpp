/******************************************************************
*
* uSQL for C++
*
* SQLParser.cpp
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <antlr3.h>
#include <cybergarage/sql/SQLParser.h>
#include <cybergarage/sql/parser/antlr/SQLLexer.h>
#include <cybergarage/sql/parser/antlr/SQLParser.h>

uSQL::SQLParser::SQLParser()
{
}

uSQL::SQLParser::~SQLParser()
{
    clear();
}

void uSQL::SQLParser::clear()
{
    for (std::vector<SQLStatement *>::iterator stmt = statements.begin(); stmt != statements.end(); stmt++)
        delete *stmt;
    statements.clear();
}

bool uSQL::SQLParser::parse(const std::string &queryString)
{
	clear();
    
    pANTLR3_INPUT_STREAM input  = antlr3StringStreamNew(
    			(pANTLR3_UINT8)queryString.c_str(), 
                ANTLR3_ENC_UTF8,
                (ANTLR3_UINT32)queryString.length(),
                (pANTLR3_UINT8)"");
    
    pSQLLexer lexer = SQLLexerNew(input);
    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
    pSQLParser parser = SQLParserNew(tokens);

    parser->statement_list(parser, this);
    
    bool parserResult = true;
    if (0 < parser->pParser->rec->state->errorCount) {
        parserResult = false;
    }

    parser->free(parser);
    tokens->free(tokens);
    lexer->free(lexer);
    input->close(input);
    
	return parserResult;
}
