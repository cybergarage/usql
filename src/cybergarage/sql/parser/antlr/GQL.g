/******************************************************************
*
* uSQL for C++
*
* GQL.g
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

grammar GQL;

options
{
    language = C;
}

@lexer::includes
{
    #include <cybergarage/sql/SQLParser.h>
}

@parser::includes
{
    #include <cybergarage/sql/SQLParser.h>
}
  
/*------------------------------------------------------------------
 * PARSER RULES
 *------------------------------------------------------------------*/

statement [uSQL::SQLParser *sqlParser]
	@init {
		uSQL::SQLStatement *stmt = new uSQL::SQLStatement();
		sqlParser->addStatement(stmt);
		sqlParser->pushNode(stmt);
	}
	@after {
		sqlParser->popNode();
	}
	: select_statement
	;	

select_statement
	@init {
		uSQL::SQLCommand *cmd = new uSQL::SQLCommand();
		cmd->setCommandType(uSQL::SQLCommand:SELECT);
		sqlParser->pushNode(cmd);
	}
	@after {
		sqlParser->popNode();
	}
	: SELECT ASTERISK FROM table_name (where_section)? (sort_section)? {
	  }
	;

table_name
	: ID
	;

where_section 
	: WHERE condition_list
	;
	
condition_list
	: condition (AND condition)*
	;

condition
	: property condition_operator value
	| property IN value
	| ANCESTOR  IS
	;

condition_operator
	: EQ
	| OP_LT
	| LE
	| GT
	| GE
	| NOTEQ
	;

sort_section
	: ORDER BY property sort_specification_list
	;
	
sort_specification_list
	: sort_specification (AND sort_specification)*
	;
	
sort_specification
	: property ordering_specification
	;

ordering_specification
	: ASC
	| DESC
	;

property
	: ID 
	;

value
	: ID
	;
			
/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/

/*
NUMBER	    : (DIGIT)+
            ;

WHITESPACE  : ( '\t' | ' ' | '\r' | '\n'| '\u000C' )+
              {
                 $channel = HIDDEN;
              }
            ;
*/
/*
INT :	'0'..'9'+
	;

FLOAT
	:   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
	|   '.' ('0'..'9')+ EXPONENT?
	|   ('0'..'9')+ EXPONENT
	;
*/

COMMENT
	:   '//' ~('\n'|'\r')* '\r'? '\n' {$channel=HIDDEN;}
	|   '/*' ( options {greedy=false;} : . )* '*/' {$channel=HIDDEN;}
	;

/*
WS  :   ( ' '
		| '\t'
		| '\r'
		| '\n'
		) {$channel=HIDDEN;}
	;

STRING
	:  '\'' ( ESC_SEQ | ~('\\'|'\'') )* '\''
	;

CHAR:  '\'' ( ESC_SEQ | ~('\''|'\\') ) '\''
	;

fragment
EXPONENT : ('e'|'E') ('+'|'-')? ('0'..'9')+ ;

fragment
HEX_DIGIT : ('0'..'9'|'a'..'f'|'A'..'F') ;

fragment
ESC_SEQ
	:   '\\' ('b'|'t'|'n'|'f'|'r'|'\"'|'\''|'\\')
	|   UNICODE_ESC
	|   OCTAL_ESC
	;

fragment
OCTAL_ESC
	:   '\\' ('0'..'3') ('0'..'7') ('0'..'7')
	|   '\\' ('0'..'7') ('0'..'7')
	|   '\\' ('0'..'7')
	;

fragment
UNICODE_ESC
	:   '\\' 'u' HEX_DIGIT HEX_DIGIT HEX_DIGIT HEX_DIGIT
	;

fragment
DIGIT	    : '0'..'9'
            ;
*/

fragment
ASTERISK
	: '*'
	;
	
fragment
EQ
	: '='
	;

fragment
OP_LT
	: '<'
	;
	
fragment
LE
	: '<='
	;
	
fragment
GT
	: '>'
	;

fragment
GE	
	: '>='
	;
	
fragment
NOTEQ
	: '!='
	;

fragment 
A	: 'A'
	| 'a'
	;

fragment 
B	: 'B'
	| 'b'
	;

fragment 
C	: 'C'
	| 'c'
	;

fragment 
D	: 'D'
	| 'd'
	;

fragment 
E	: 'E'
	| 'e'
	;

fragment 
F	: 'F'
	| 'f'
	;

fragment 
G	: 'G'
	| 'g'
	;

fragment 
H	: 'H'
	| 'h'
	;

fragment 
I	: 'I'
	| 'i'
	;

fragment 
J	: 'J'
	| 'j'
	;

fragment 
K	: 'K'
	| 'k'
	;

fragment 
L	: 'L'
	| 'l'
	;

fragment 
M	: 'M'
	| 'm'
	;

fragment 
N	: 'N'
	| 'n'
	;

fragment 
O	: 'O'
	| 'o'
	;

fragment 
P	: 'P'
	| 'p'
	;

fragment 
Q	: 'Q'
	| 'q'
	;

fragment 
R	: 'R'
	| 'r'
	;

fragment 
S	: 'S'
	| 's'
	;

fragment 
T	: 'T'
	| 't'
	;

fragment 
U	: 'U'
	| 'u'
	;

fragment 
V	: 'V'
	| 'v'
	;

fragment 
W	: 'W'
	| 'w'
	;

fragment 
X	: 'X'
	| 'x'
	;

fragment 
Y	: 'Y'
	| 'y'
	;

fragment 
Z	: 'Z'
	| 'z'
	;

ANCESTOR
	: A N C E S T O R
	;
AND
	: A N D
	;

ASC
	: A S C
	;
	
BY
	: B Y
	;

DESC
	: D E S C
	;
	
FROM
	: F R O M
	;

IN
	: I N
	;

IS
	: I S
	;

LIMIT
	: L I M I T
	;
	
OFFSET
	: O F F S E T
	;

ORDER
	: O R D E R
	;
	
SELECT
	: S E L E C T
	;

WHERE
	: W H E R E
	;
	
ID  
	: ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
	;

