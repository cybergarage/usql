#include <antlr3.h>
#include <cybergarage/sql/GQLParser.h>
#include <cybergarage/sql/parser/antlr/GQLLexer.h>
#include <cybergarage/sql/parser/antlr/GQLParser.h>

//using namespace uSQL;

uSQL::GQLParser::GQLParser()
{
}

bool uSQL::GQLParser::parse(const std::string &queryString)
{
    //input  = antlr3AsciiFileStreamNew          ((pANTLR3_UINT8)argv[1]);
    pANTLR3_INPUT_STREAM input  = antlr3NewAsciiStringCopyStream(
    			(pANTLR3_UINT8)queryString.c_str(), 
                (ANTLR3_UINT32)queryString.length(),
                (pANTLR3_UINT8)"");
    
    pGQLLexer lex    = GQLLexerNew(input);
    pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lex));
    pGQLParser parser = GQLParserNew(tokens);

    parser->statement(parser, this);

    // Must manually clean up
    //
    parser->free(parser);
    tokens->free(tokens);
    lex->free(lex);
    input->close(input);
    
	return true;
}
