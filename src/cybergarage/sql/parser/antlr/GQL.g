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
	#include <string.h>
	#include <cybergarage/sql/SQLParser.h>
    
	#define CG_ANTLR3_STRING_2_UTF8(str) ((const char *)str->chars)
	#define CG_ANTLR3_STRING_2_INT(str) (str->chars ? atoi((const char *)str->chars) : 0)
}
  
/*------------------------------------------------------------------
 * PARSER RULES
 *------------------------------------------------------------------*/

statement [uSQL::SQLParser *sqlParser]
	@init {
		uSQL::SQLStatement *stmt = new uSQL::SQLStatement();
		sqlParser->addStatement(stmt);
	}
	: select_statement[stmt]
	;	

select_statement [uSQL::SQLStatement *sqlStmt]
	@init {
		tl = NULL;
		ws = NULL;
		ss = NULL;
		ls = NULL;
		os = NULL;
	}
	: SELECT ASTERISK FROM tl=table_list (ws=where_section)? (ss=sort_section)? (ls=limit_section)? (os=offset_section)? 
	{
		// SELECT
		uSQL::SQLSelect *sqlCmd = new uSQL::SQLSelect();
		sqlStmt->addChildNode(sqlCmd);

		// ASTERISK
		/*
		uSQL::SQLColumns *sqlColumns = new uSQL::SQLColumns();
		sqlStmt->addChildNode(sqlColumns);
		uSQL::SQLColumn *sqlColumn = new uSQL::SQLColumn();
		sqlColumn->setName("*");
		sqlColumns->addChildNode(sqlColumn);
		*/
		
		// TABLE		
		sqlStmt->addChildNode(tl);
		
		// WHERE		
		if (ws)
			sqlStmt->addChildNode(ws);
			
		// ORDER BY		
		if (ss)
			sqlStmt->addChildNode(ss);
			
		// LIMIT		
		if (ls)
			sqlStmt->addChildNode(ls);

		// OFFSET		
		if (os)
			sqlStmt->addChildNode(os);

	}
	;

table_name [uSQL::SQLFrom *sqlFrom]
	: ID {
		uSQL::SQLDataSource *sqlTable = new uSQL::SQLDataSource();
		sqlTable->setValue(CG_ANTLR3_STRING_2_UTF8($ID.text));
		sqlFrom->addChildNode(sqlTable);
	  }
	;

table_list returns [uSQL::SQLFrom *sqlFrom]
	@init {
		sqlFrom = new uSQL::SQLFrom();
	}
	: (table_name[sqlFrom]) (COMMA table_name[sqlFrom])*
	;

where_section returns [uSQL::SQLWhere *sqlWhere]
	@init {
		sqlWhere = new uSQL::SQLWhere();
	}
	: WHERE condition_list[sqlWhere]
	;
	
condition_list [uSQL::SQLWhere *sqlWhere]
	: condition[sqlWhere] (AND condition[sqlWhere])*
	;

condition [uSQL::SQLWhere *sqlWhere]
	: exprLeft=expression_atom binOper=condition_operator exprRight=expression_atom {
		sqlWhere->addExpression(binOper);
		binOper->addExpression(exprLeft);
		binOper->addExpression(exprRight);
	  }
	| property IN value
	| ANCESTOR  IS
	;

expression_atom returns [uSQL::SQLExpression *sqlExpr]
	@init {
		sqlExpr = new uSQL::SQLExpression();
	}
 	: property {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($property.text));
	  }
	| value {
			sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($value.text));
	  }
	;

condition_operator returns [uSQL::SQLOperator *sqlOper]
	@init {
		sqlOper = new uSQL::SQLOperator();
	}
	: EQ {
		sqlOper->setValue(1/*uSQL::SQLOperator::EQ*/);
	  }
	| OP_LT {
		sqlOper->setValue(2/*uSQL::SQLOperator::LT*/);
	  }
	| LE {
		sqlOper->setValue(3/*uSQL::SQLOperator::GT*/);
	  }
	| GT {
		sqlOper->setValue(4/*uSQL::SQLOperator::LE*/);
	  }
	| GE {
		sqlOper->setValue(5/*uSQL::SQLOperator::GE*/);
	  }
	| NOTEQ {
		sqlOper->setValue(6/*uSQL::SQLOperator::NOTEQ*/);
	  }
	;

sort_section returns [uSQL::SQLOrderBy *sqlOrders]
	@init {
		sqlOrders = new uSQL::SQLOrderBy();
	}
	: ORDER BY sort_specification_list[sqlOrders]
	;
	
sort_specification_list [uSQL::SQLOrderBy *sqlOrders]
	: sort_specification[sqlOrders] (AND sort_specification[sqlOrders])*
	;
	
sort_specification [uSQL::SQLOrderBy *sqlOrders]
	: property (ordering_specification)? {
		uSQL::SQLOrder *sqlOrder = new uSQL::SQLOrder();
		sqlOrder->setValue(CG_ANTLR3_STRING_2_UTF8($property.text));
		if (ordering_specification)
			sqlOrder->setOrder(CG_ANTLR3_STRING_2_UTF8($ordering_specification.text));
		sqlOrders->addChildNode(sqlOrder);
	  }
	;

ordering_specification
	: ASC
	| DESC
	;

limit_section returns [uSQL::SQLLimit *sqlLimit]
	@init {
		sqlLimit = new uSQL::SQLLimit();
	}
	: LIMIT (limit_offset[sqlLimit])? NUMBER {
		sqlLimit->setCount(CG_ANTLR3_STRING_2_INT($NUMBER.text));
	  }
	;

limit_offset [uSQL::SQLLimit *sqlLimit]
	: COMMA NUMBER {
		sqlLimit->setOffset(CG_ANTLR3_STRING_2_INT($NUMBER.text));
	}
	;

offset_section returns [uSQL::SQLOffset *sqlOffset]
	@init {
		sqlOffset = new uSQL::SQLOffset();
	}
	: OFFSET NUMBER {
		sqlOffset->setValue(CG_ANTLR3_STRING_2_INT($NUMBER.text));
	  }
	;


/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/

property
	: ID 
	;

value
	: STRING
	;

NUMBER	    : (DIGIT)+
            ;
/*
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

WS  :   ( ' '
		| '\t'
		| '\r'
		| '\n'
		) {$channel=HIDDEN;}
	;

STRING
	:  '"' ( EscapeSequence | ~('\\'| '"') )* '"' 
	;

fragment
EscapeSequence
	:   '\\' ('\"'|'\''|'\\')
	;

fragment
DIGIT	    : '0'..'9'
            ;

ASTERISK
	: '*'
	;
	
EQ
	: '='
	;

OP_LT
	: '<'
	;
	
LE
	: '<='
	;
	
GT
	: '>'
	;

GE	
	: '>='
	;
	
NOTEQ
	: '!='
	;

COMMA
	: ','
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

