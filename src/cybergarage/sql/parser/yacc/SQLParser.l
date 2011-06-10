/******************************************************************
*
* C declarations
*
******************************************************************/

%{
#include "SQLParser.tab.h"

#define input   yyinput
#define output  yyoutput

%}

/******************************************************************
*
* Bison declarations
*
******************************************************************/

/******************************************************************
*
* Grammar rules
*
******************************************************************/

%%

-?[0-9]+                                        { yylval.integerValue = atoi(yytext); return INTEGER_VALUE;}
-?[0-9]*\.?[0-9]*([eE][+-]?[0-9]+)?             { yylval.floatValue = (float)atof(yytext); return FLOAT_VALUE;}
0x[0-9A-Fa-f]+                                  { sscanf(yytext, "0x%x", &yylval.integerValue); return INTEGER_VALUE; }
\"[^\"]*\"                                      { yytext[yyleng-1] = '\0'; yylval.stringValue = yytext+1;  return STRING_VALUE; }

%%

/******************************************************************
*
* Additional C codes
*
******************************************************************/



