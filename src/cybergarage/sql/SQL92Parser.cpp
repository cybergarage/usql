/******************************************************************
*
* uSQL for C++
*
* SQL92Parser.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <antlr3.h>
#include <cybergarage/sql/SQL92Parser.h>
#include <cybergarage/sql/parser/antlr/SQL92Lexer.h>
#include <cybergarage/sql/parser/antlr/SQL92Parser.h>

uSQL::SQL92Parser::SQL92Parser()
{
}

bool uSQL::SQL92Parser::parse(const std::string &queryString)
{
    //input  = antlr3AsciiFileStreamNew          ((pANTLR3_UINT8)argv[1]);
    pANTLR3_INPUT_STREAM input  = antlr3NewAsciiStringCopyStream(
    			(pANTLR3_UINT8)queryString.c_str(), 
                (ANTLR3_UINT32)queryString.length(),
                (pANTLR3_UINT8)"");
    
    pSQL92Lexer lex    = SQL92LexerNew(input);
    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    pSQL92Parser parser = SQL92ParserNew(tokens);

    parser->statement(parser);

    // Must manually clean up
    //
    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);
    
	return true;
}
