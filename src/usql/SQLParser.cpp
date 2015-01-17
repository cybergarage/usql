/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include <strstream>

#include <antlr3.h>
#include <usql/platform.h>
#include <usql/SQLParser.h>
#include <usql/parser/antlr/SQLLexer.h>
#include <usql/parser/antlr/SQLParser.h>

void uSQLDisplayRecognitionError (pANTLR3_BASE_RECOGNIZER recognizer, pANTLR3_UINT8 * tokenNames)
{
  pANTLR3_PARSER parser = (pANTLR3_PARSER)(recognizer->super);
  pSQLParser sqlParser = (pSQLParser)parser->super;
  uSQL::SQLParser *uSqlParser = (uSQL::SQLParser *)sqlParser->uSqlParser;
  uSQL::SQLError *uSqlError = uSqlParser->getError();
  
  uSqlError->setCode(recognizer->state->exception->type);
  uSqlError->setLine(recognizer->state->exception->line);
  uSqlError->setOffset(recognizer->state->exception->charPositionInLine + 1);
  
  std::strstream errorMessage;
  std::string message = (const char *)(recognizer->state->exception->message);
  errorMessage << "Parser Error (" << uSqlError->getLine() << ") : " << message << " at offset " << uSqlError->getOffset();
  uSqlError->setMessage(errorMessage.str());
}

uSQL::SQLParser::SQLParser()
{
}

uSQL::SQLParser::~SQLParser()
{
  clear();
}

void uSQL::SQLParser::setStatementType(int type)
{
  for (std::vector<SQLStatement *>::iterator stmt = statements.begin(); stmt != statements.end(); stmt++)
    (*stmt)->setStatementType(type);
}

void uSQL::SQLParser::clear()
{
  for (std::vector<SQLStatement *>::iterator stmt = statements.begin(); stmt != statements.end(); stmt++)
    delete *stmt;
  this->statements.clear();
  this->error.clear();
}

bool uSQL::SQLParser::parse(const std::string &queryString)
{
  clear();

#if defined(USQL_USE_ANTLR3_STRINGSTREAMNEW)
  pANTLR3_INPUT_STREAM input  = antlr3StringStreamNew(
        (pANTLR3_UINT8)queryString.c_str(), 
        ANTLR3_ENC_UTF8,
        (ANTLR3_UINT32)queryString.length(),
        (pANTLR3_UINT8)"");
#else  
  pANTLR3_INPUT_STREAM input  = antlr3NewAsciiStringInPlaceStream(
        (pANTLR3_UINT8)queryString.c_str(), 
        (ANTLR3_UINT32)queryString.length(),
        (pANTLR3_UINT8)"");
#endif
  
  pSQLLexer lexer = SQLLexerNew(input);
  
  pANTLR3_COMMON_TOKEN_STREAM tokens = antlr3CommonTokenStreamSourceNew(ANTLR3_SIZE_HINT, TOKENSOURCE(lexer));
  pSQLParser parser = SQLParserNew(tokens);
  parser->uSqlParser = this;
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
