/******************************************************************
*
* uSQL for C++
*
* GQLParser.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <antlr3.h>
#include <cybergarage/sql/GQLParser.h>
#include <cybergarage/sql/parser/antlr/GQLLexer.h>
#include <cybergarage/sql/parser/antlr/GQLParser.h>

uSQL::GQLParser::GQLParser()
{
}

bool uSQL::GQLParser::parse(const std::string &queryString)
{
    pANTLR3_INPUT_STREAM input  = antlr3NewAsciiStringCopyStream(
    			(pANTLR3_UINT8)queryString.c_str(), 
                (ANTLR3_UINT32)queryString.length(),
                (pANTLR3_UINT8)"");
    
    pGQLLexer lexer = GQLLexerNew(input);
    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
    pGQLParser parser = GQLParserNew(tokens);

    parser->statement(parser, this);

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
