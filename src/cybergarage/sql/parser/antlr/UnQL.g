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
		// SELECT
		uSQL::SQLSelect *sqlSelect = new uSQL::SQLSelect();
		sqlStmt->addChildNode(sqlSelect);

		ss = NULL;
		ls = NULL;
		os = NULL;
	}
	: select_core[sqlStmt] (ss=sorting_section)? (ls=limit_section)? (os=offset_section)? 
	{
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

select_core [uSQL::SQLStatement *sqlStmt]
	@init {
		uSQL::SQLColumn *sqlColumn = new uSQL::SQLColumn();
		fromSection = NULL;
		whereSection = NULL;
	}
	: SELECT (DISTINCT | ALL)? (expression[sqlColumn])? (AS name)? 
	  (fromSection = from_section)? 
	  (whereSection = where_section)? /*
	  (GROUP BY expression (',' expression)* (HAVING expression)?)?  */ {
	  
		// VALUE 
		if (sqlColumn->hasExpressions())
			sqlStmt->addChildNode(sqlColumn);
		else 
			delete sqlColumn;
			
		// FROM
		if (fromSection)		
			sqlStmt->addChildNode(fromSection);
			
		// WHERE
		if (whereSection)		
			sqlStmt->addChildNode(whereSection);
	  }
	;

from_section returns [uSQL::SQLFrom *sqlFrom]
	@init {
		sqlFrom = new uSQL::SQLFrom();
	}
	: (FROM table_name[sqlFrom]) (COMMA table_name[sqlFrom])*
	;

table_name [uSQL::SQLFrom *sqlFrom]
	: dataSource = data_source {
		sqlFrom->addChildNode(dataSource);
	  }
	;

data_source returns [uSQL::SQLDataSource *sqlDataSource]
	: (collection_name) {
		sqlDataSource = new uSQL::SQLDataSource();
		sqlDataSource->setValue(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
	  }
	;

where_section returns [uSQL::SQLWhere *sqlWhere]
	@init {
		sqlWhere = new uSQL::SQLWhere();
	}
	: WHERE expression[sqlWhere]
	;

sorting_section returns [uSQL::SQLOrderBy *sqlOrders]
	@init {
		sqlOrders = new uSQL::SQLOrderBy();
	}
	: ORDER BY sorting_list[sqlOrders]
	;
	
sorting_list [uSQL::SQLOrderBy *sqlOrders]
	: sorting_item[sqlOrders] (AND sorting_item[sqlOrders])*
	;
	
sorting_item [uSQL::SQLOrderBy *sqlOrders]
	: property (sorting_specification)? {
		uSQL::SQLOrder *sqlOrder = new uSQL::SQLOrder();
		sqlOrder->setValue(CG_ANTLR3_STRING_2_UTF8($property.text));
		if (sorting_specification)
			sqlOrder->setOrder(CG_ANTLR3_STRING_2_UTF8($sorting_specification.text));
		sqlOrders->addChildNode(sqlOrder);
	  }
	;

sorting_specification
	: ASC
	| DESC
	;

limit_section returns [uSQL::SQLLimit *sqlLimit]
	@init {
		sqlLimit = new uSQL::SQLLimit();
		offsetExpr = NULL;
	}
	: LIMIT (offsetExpr=expression_atom COMMA)? countExpr=expression_atom {
		if (offsetExpr)
			sqlLimit->addChildNode(offsetExpr);
		sqlLimit->addChildNode(countExpr);
	  }
	;

offset_section returns [uSQL::SQLOffset *sqlOffset]
	@init {
		sqlOffset = new uSQL::SQLOffset();
	}
	: offsetExpr=expression_atom {
		sqlOffset->addChildNode(offsetExpr);
	  }
	;

	
/******************************************************************
*
* CREATE
*
******************************************************************/

create_collection_stmt [uSQL::SQLStatement *sqlStmt]
	@init {	
		uSQL::SQLOption *sqlOpt = new uSQL::SQLOption();
	}
	: CREATE COLLECTION collection_name (OPTIONS expression[sqlOpt])? {
		// CREATE
		uSQL::SQLCreate *sqlCmd = new uSQL::SQLCreate();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		uSQL::SQLCollection *sqlCollection = new uSQL::SQLCollection();
		sqlCollection->setValue(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
		sqlCmd->addChildNode(sqlCollection);

		// Option 
		if (sqlOpt->hasExpressions())
			sqlCmd->addChildNode(sqlOpt);
		else 
			delete sqlOpt;
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
		sqlCollection->setValue(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
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
		uSQL::SQLValue *sqlValue = new uSQL::SQLValue();
		isAsync = false;
	}
	: (isAsync=sync_operator)? INSERT INTO collection_name VALUE expression[sqlValue]
	{
		// INSERT
		uSQL::SQLInsert *sqlCmd = new uSQL::SQLInsert();
		sqlCmd->setAsyncEnabled(isAsync);
		sqlStmt->addChildNode(sqlCmd);

		// Collection
		uSQL::SQLCollection *sqlCollection = new uSQL::SQLCollection();
		sqlCollection->setValue(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
		sqlCmd->addChildNode(sqlCollection);
		
		// Value
		sqlCmd->addChildNode(sqlValue);
	}
	;

/******************************************************************
*
* Expression
*
******************************************************************/

expression [uSQL::SQLExpression *parentSqlExpr]
 	: sqlExpr=expression_atom {
		parentSqlExpr->addExpression(sqlExpr);
	  }
	| '{' (dictionary_literal[parentSqlExpr]) (COMMA dictionary_literal[parentSqlExpr])* '}'
	| '[' array_literal[parentSqlExpr] (COMMA array_literal[parentSqlExpr] )* ']'
	| sqlFunc=function_name '(' array_literal[sqlFunc] (COMMA array_literal[sqlFunc] )* ')' {
		parentSqlExpr->addExpression(sqlFunc);
	  }
	| exprLeft=expression_atom binOper=binary_operator exprRight=expression_atom {
		parentSqlExpr->addExpression(binOper);
		binOper->addExpression(exprLeft);
		binOper->addExpression(exprRight);
	  }
	;

expression_atom returns [uSQL::SQLExpression *sqlExpr]
	@init {
		sqlExpr = new uSQL::SQLExpression();
	}
 	: property {
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($property.text));
	  }
	| integer_literal {
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
	;

property
	: ID 
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

dictionary_literal [uSQL::SQLExpression *parentSqlExpr]
	: name ':' sqlExpr=expression_atom {
		sqlExpr->setName(CG_ANTLR3_STRING_2_UTF8($name.text));
		parentSqlExpr->addExpression(sqlExpr);
	  }
	;

array_literal [uSQL::SQLExpression *parentSqlExpr]
	: sqlExpr=expression_atom {
		parentSqlExpr->addExpression(sqlExpr);
	  }
	;

function_name returns [uSQL::SQLFunction *sqlFunc]
	@init {
		sqlFunc = new uSQL::SQLFunction();
	}
	: ID {
		sqlFunc->setValue(CG_ANTLR3_STRING_2_UTF8($ID.text));
	  }
	;

function_literal [uSQL::SQLExpression *parentSqlExpr]
	@init {
		uSQL::SQLExpression *valueParentExpr = new uSQL::SQLExpression();
	}
	@after {
		delete valueParentExpr;
	}
	: expression[valueParentExpr] {
 		uSQL::SQLExpression *valueExpr = valueParentExpr->getExpression(0);
		uSQL::SQLExpression *sqlExpr = new uSQL::SQLExpression();
		sqlExpr->setValue(valueExpr ? valueExpr->getValue() : "");
		parentSqlExpr->addExpression(sqlExpr);
	  }
	;

binary_operator returns [uSQL::SQLOperator *sqlOper]
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
	| AND {
		sqlOper->setValue(7/*uSQL::SQLOperator::AND*/);
	  }
	| OR {
		sqlOper->setValue(8/*uSQL::SQLOperator::OR*/);
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

condition_operator
	: EQ
	| OP_LT
	| LE
	| GT
	| GE
	| NOTEQ
	;

value 	
	: ID	
	;

name
	: ID
	;

collection_name
	: ID
	| string_literal
	;

/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/


ASTERISK
	: '*'
	;
	
EQ
	: '='
	| '=='
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

AND
	: A N D
	| '&'
	;

OR
	: O R
	| '|'
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

EACH
	: E A C H
	;
		
EXCEPT
	: E X C E P T
	;

FLATTEN
	: F L A T T E N
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

WS  :   ( ' '
        | '\t'
        | '\r'
        | '\n'
        ) {$channel=HIDDEN;}
    ;
	
ID  
	//: ('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
	: ('a'..'z'|'A'..'Z'|'_'|'/')('a'..'z'|'A'..'Z'|'_'|'-'|'/'|'.'|'0'..'9')*
    	;

NUMBER 
	: '0'..'9'+
	;

FLOAT
	:   ('0'..'9')+ '.' ('0'..'9')* EXPONENT?
	|   '.' ('0'..'9')+ EXPONENT?
	|   ('0'..'9')+ EXPONENT
	;

STRING
	:  '"' ( EscapeSequence | ~('\\'| '"') )* '"' 
	;

fragment
EscapeSequence
	:   '\\' ('\"'|'\''|'\\')
	;

/*
NAME
   :   ('a'..'z'|'A'..'Z'|'_')('a'..'z'|'A'..'Z'|'_'|'-'|'0'..'9')*
   ;
*/

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
