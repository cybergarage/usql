/******************************************************************
*
* uSQL for C++
*
* UnQL.g
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

grammar UnQL;

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
 *
 * PARSER RULES
 *
 *------------------------------------------------------------------*/

statement [uSQL::SQLParser *sqlParser]
	@init {
		uSQL::SQLStatement *stmt = new uSQL::SQLStatement();
		sqlParser->addStatement(stmt);
	}
	: select_stmt[stmt]
	| create_collection_stmt[stmt]
	| drop_collection_stmt[stmt]
	| insert_stmt[stmt]
	;	

/******************************************************************
*
* SELECT
*
******************************************************************/

select_stmt [uSQL::SQLStatement *sqlStmt]
	@init {
		tl = NULL;
		ws = NULL;
		ss = NULL;
		ls = NULL;
		os = NULL;
	}
	: SELECT (compound_operator)? FROM tl=table_list (ws=where_section)? (ss=sort_section)? (ls=limit_section)? (os=offset_section)? 
	{
		// SELECT
		uSQL::SQLSelect *sqlCmd = new uSQL::SQLSelect();
		sqlStmt->addChildNode(sqlCmd);

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

select_core
	: SELECT (DISTINCT | ALL)? (expression)? (AS name)? 
	  (FROM)?
	  (WHERE expression)?
	  (GROUP BY expression (',' expression)* (OFFSET expression)? (HAVING expression)?)?
	;

/******************************************************************
*
* CREATE
*
******************************************************************/

create_collection_stmt [uSQL::SQLStatement *sqlStmt]
	@init {	
		expr = NULL;
	}
	: CREATE COLLECTION collection_name (OPTIONS expr=expression)?
	{
		// CREATE
		uSQL::SQLCreate *sqlCmd = new uSQL::SQLCreate();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		uSQL::SQLCollection *sqlCollection = new uSQL::SQLCollection();
		sqlCollection->setName(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
		sqlCmd->addChildNode(sqlCollection);

		// Expression 
		if (expr)
			sqlCmd->addChildNode(expr);
	}
	;

/******************************************************************
*
* DROP
*
******************************************************************/

drop_collection_stmt [uSQL::SQLStatement *sqlStmt]
	@init {	
	}
	: DROP COLLECTION collection_name
	{
		// CREATE
		uSQL::SQLDrop *sqlCmd = new uSQL::SQLDrop();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		uSQL::SQLCollection *sqlCollection = new uSQL::SQLCollection();
		sqlCollection->setName(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
		sqlCmd->addChildNode(sqlCollection);
	}
	;

/******************************************************************
*
* INSERT
*
******************************************************************/

insert_stmt [uSQL::SQLStatement *sqlStmt]
	@init {
		isAsync = false;
		expr = NULL;
	}
	: (isAsync=sync_operator)? INSERT INTO collection_name VALUE expr=expression
	{
		// INSERT
		uSQL::SQLInsert *sqlCmd = new uSQL::SQLInsert();
		sqlCmd->setAsyncEnabled(isAsync);
		sqlStmt->addChildNode(sqlCmd);

		// Collection
		uSQL::SQLCollection *sqlCollection = new uSQL::SQLCollection();
		sqlCollection->setName(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
		sqlCmd->addChildNode(sqlCollection);
		
		// Value
		uSQL::SQLValue *sqlValue = new uSQL::SQLValue(expr);
		sqlCmd->addChildNode(sqlValue);
	}
	;

/******************************************************************
*
* COMMON
*
******************************************************************/

sync_operator returns [bool isAync]
	: SYNC {
		isAync = false;
	  }
	| ASYNC {
		isAync = true;
	  }
	;

compound_operator
	: UNION (ALL)?
	| INTERSECT
	| EXCEPT
	;

table_name [uSQL::SQLFrom *sqlFrom]
	: STRING {
		uSQL::SQLTable *sqlTable = new uSQL::SQLTable();
		sqlTable->setName(CG_ANTLR3_STRING_2_UTF8($STRING.text));
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
	: property condition_operator value {
		uSQL::SQLCondition *sqlCond = new uSQL::SQLCondition();
		sqlCond->setName(CG_ANTLR3_STRING_2_UTF8($property.text));
		sqlCond->setOperation(CG_ANTLR3_STRING_2_UTF8($condition_operator.text));
		sqlCond->setValue(CG_ANTLR3_STRING_2_UTF8($value.text));
		sqlWhere->addChildNode(sqlCond);
	  }
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

sort_section returns [uSQL::SQLOrders *sqlOrders]
	@init {
		sqlOrders = new uSQL::SQLOrders();
	}
	: ORDER BY sort_specification_list[sqlOrders]
	;
	
sort_specification_list [uSQL::SQLOrders *sqlOrders]
	: sort_specification[sqlOrders] (AND sort_specification[sqlOrders])*
	;
	
sort_specification [uSQL::SQLOrders *sqlOrders]
	: property ordering_specification {
		uSQL::SQLOrder *sqlOrder = new uSQL::SQLOrder();
		sqlOrder->setName(CG_ANTLR3_STRING_2_UTF8($property.text));
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


value 	
	: STRING	
	;

name
	: STRING
	;

collection_name
	: ID
	;

expression returns [uSQL::SQLExpression *sqlExpr]
	@init {
		sqlExpr = new uSQL::SQLExpression();
	}
	/* : property */
	: integer_literal {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($integer_literal.text));
	  }
	| real_literal {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($real_literal.text));
	  }
	| string_literal {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($string_literal.text));
	  }
	| true_literal {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($true_literal.text));
	  }
	| false_literal {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($false_literal.text));
	  }
	| '{' (name ':' expression) (',' name ':' expression )* '}'
	| ']' expression (',' expression )* ']'
	;

property
	: STRING 
	;

integer_literal
	: NUMBER
	;

real_literal
	: FLOAT
	;

string_literal
	: STRING
	;

true_literal
	: 'true'
	;
	
false_literal
	: 'false'
	;
	

/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/


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

ALL
	: A L L
	;
	
ANCESTOR
	: A N C E S T O R
	;
AND
	: A N D
	;

AS
	: A S
	;

ASC
	: A S C
	;
	
ASYNC
	: A S Y N C
	;
	
BY
	: B Y
	;

CREATE
	: C R E A T E
	;

COLLECTION
	: C O L L E C T I O N
	;

DESC
	: D E S C
	;

DISTINCT
	: D I S T I N C T
	;

DROP
	: D R O P
	;
	
EXCEPT
	: E X C E P T
	;
	
FROM
	: F R O M
	;

GROUP
	: G R O U P
	;
		
HAVING
	: H A V I N G
	;
	
IN
	: I N
	;

INSERT
	: I N S E R T
	;

INTERSECT
	: I N T E R S E C T
	;

INTO
	: I N T O
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

OPTIONS
	: O P T I O N S
	;

ORDER
	: O R D E R
	;
	
SELECT
	: S E L E C T
	;

SYNC
	: S Y N C
	;

UNION
	: U N I O N
	;

WHERE
	: W H E R E
	;

VALUE
	: V A L U E
	;

/******************************************************************
*
* COMMON
*
******************************************************************/
	
ID  
	: ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
    	;

NUMBER 
	: '0'..'9'+
	;

FLOAT
	:   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
	|   '.' ('0'..'9')+ EXPONENT?
	|   ('0'..'9')+ EXPONENT
	;

/*
STRING
	: ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
//    : ( ESC_SEQ | ~('\\'|'\'') )*
//	: ('a'..'z'|'A'..'Z'|'0'..'9'|'_')+
//	:  ( ~('\\'|'\'') )*
//	:  '\'' ( ESC_SEQ | ~('\\'|'\'') )* '\''
	;
*/

STRING
    :  '"' ( ESC_SEQ | ~('\\'|'"') )* '"'
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