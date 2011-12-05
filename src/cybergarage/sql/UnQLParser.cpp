/******************************************************************
*
* uSQL for C++
*
* UnQLParser.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <antlr3.h>
#include <cybergarage/sql/UnQLParser.h>
#include <cybergarage/sql/parser/antlr/UnQLLexer.h>
#include <cybergarage/sql/parser/antlr/UnQLParser.h>

uSQL::UnQLParser::UnQLParser()
{
}

bool uSQL::UnQLParser::parse(const std::string &queryString)
{
    pANTLR3_INPUT_STREAM input  = antlr3NewAsciiStringCopyStream(
    			(pANTLR3_UINT8)queryString.c_str(), 
                (ANTLR3_UINT32)queryString.length(),
                (pANTLR3_UINT8)"");
    
    pUnQLLexer lexer = UnQLLexerNew(input);
    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
    pUnQLParser parser = UnQLParserNew(tokens);

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
