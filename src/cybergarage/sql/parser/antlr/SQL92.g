/******************************************************************
*
* uSQL for C++
*
* SQL92.g
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

grammar SQL92;

options
{
    language=C;
}

@lexer::header
{
/******************************************************************
*
* uSQL for C++
*
* SQL92Lexer for ANTLR
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/
}

@parser::header
{
/******************************************************************
*
* uSQL for C++
*
* SQL92Parser for ANTLR
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/
}

@lexer::includes
{
}

@parser::includes
{
    #include <cybergarage/sql/SQLParser.h>

	#define CG_ANTLR3_STRING_2_UTF8(str) ((const char *)str->chars)
	#define CG_ANTLR3_STRING_2_INT(str) (str->chars ? atoi((const char *)str->chars) : 0)
}

/*------------------------------------------------------------------
 *
 * PARSER RULES
 *
 *------------------------------------------------------------------*/

statement_list [uSQL::SQLParser *sqlParser]
	: statement[sqlParser] (SEMICOLON statement[sqlParser])*
	;	

statement [uSQL::SQLParser *sqlParser]
	@init {
		uSQL::SQLStatement *stmt = new uSQL::SQLStatement();
		sqlParser->addStatement(stmt);
	}
	: select_stmt[stmt]
	| create_collection_stmt[stmt]
	| drop_collection_stmt[stmt]
	| create_index_stmt[stmt]
	| drop_index_stmt[stmt]
	| insert_stmt[stmt]
	| update_stmt[stmt]
	| delete_stmt[stmt]
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

		sortingSection = NULL;
		limitSection = NULL;
		offsetSection = NULL;
	}
	: select_core[sqlStmt] (sortingSection=sorting_section)? (limitSection=limit_section)? (offsetSection=offset_section)? 
	{
		// ORDER BY		
		if (sortingSection)
			sqlStmt->addChildNode(sortingSection);
			
		// LIMIT		
		if (limitSection)
			sqlStmt->addChildNode(limitSection);

		// OFFSET
		if (offsetSection)
			sqlStmt->addChildNode(offsetSection);
	}
	;

select_core [uSQL::SQLStatement *sqlStmt]
	@init {
		uSQL::SQLColumn *sqlColumn = new uSQL::SQLColumn();
		fromSection = NULL;
		whereSection = NULL;
		groupSection = NULL;
		havingSection = NULL;
	}
	: SELECT (DISTINCT | ALL)? (expression[sqlColumn])? (AS name)? 
	  (fromSection = from_section)? 
	  (whereSection = where_section)?
	  (groupSection = grouping_section)? 
	  (havingSection = having_section)? 
	  {
	  
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

		// GROUP BY
		if (groupSection)		
			sqlStmt->addChildNode(groupSection);

		// HAVING
		if (havingSection)		
			sqlStmt->addChildNode(havingSection);
	  }
	;

result_column [uSQL::SQLColumn *sqlColumn]
	: ASTERISK {
	  }
	| expression_literal AS column_alias {
	  }
	;

column_alias
	: ID
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
	@init {
		sqlDataSource = new uSQL::SQLDataSource();
	}
	: collection_name {
		// Collection
		sqlDataSource->setValue(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
	  }
	;

grouping_section returns [uSQL::SQLGroupBy *sqlGroupBy]
	@init {
		sqlGroupBy = new uSQL::SQLGroupBy();
	}
	: GROUP BY expression[sqlGroupBy] (COMMA expression[sqlGroupBy])*
	;
	
having_section returns [uSQL::SQLHaving *sqlHaving]
	@init {
		sqlHaving = new uSQL::SQLHaving();
	}
	: HAVING expression[sqlHaving]
	;

sorting_section returns [uSQL::SQLOrderBy *sqlOrders]
	@init {
		sqlOrders = new uSQL::SQLOrderBy();
	}
	: ORDER BY sorting_item[sqlOrders] (COMMA sorting_item[sqlOrders])*
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
	: LIMIT (offsetExpr=expression_literal COMMA)? countExpr=expression_literal {
		if (offsetExpr)
			sqlLimit->addChildNode(offsetExpr);
		sqlLimit->addChildNode(countExpr);
	  }
	;

offset_section returns [uSQL::SQLOffset *sqlOffset]
	@init {
		sqlOffset = new uSQL::SQLOffset();
	}
	: offsetExpr=expression_literal {
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
	: CREATE COLLECTION collectionNode=collection_section (OPTIONS expression[sqlOpt])? {
		// CREATE
		uSQL::SQLCreate *sqlCmd = new uSQL::SQLCreate();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		sqlCmd->addChildNode(collectionNode);

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
	: DROP COLLECTION collectionNode=collection_section
	{
		// DROP
		uSQL::SQLDrop *sqlCmd = new uSQL::SQLDrop();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		sqlCmd->addChildNode(collectionNode);
	}
	;

/******************************************************************
*
* CREATE INDEX
*
******************************************************************/

create_index_stmt [uSQL::SQLStatement *sqlStmt]
	@init {	
	}
	: CREATE COLLECTION_INDEX indexNode=index_section
	{
		// DROP
		uSQL::SQLCreateIndex *sqlCmd = new uSQL::SQLCreateIndex();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		sqlCmd->addChildNode(indexNode);
	}
	;

/******************************************************************
*
* DROP INDEX
*
******************************************************************/

drop_index_stmt [uSQL::SQLStatement *sqlStmt]
	@init {	
	}
	: DROP COLLECTION_INDEX indexNode=index_section
	{
		// DROP
		uSQL::SQLDropIndex *sqlCmd = new uSQL::SQLDropIndex();
		sqlStmt->addChildNode(sqlCmd);
		
		// Collection
		sqlCmd->addChildNode(indexNode);
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
	: (isAsync=sync_operator)? INSERT INTO collectionNode=collection_section VALUE expression[sqlValue]
	{
		// INSERT
		uSQL::SQLInsert *sqlCmd = new uSQL::SQLInsert();
		sqlCmd->setAsyncEnabled(isAsync);
		sqlStmt->addChildNode(sqlCmd);

		// Collection
		sqlCmd->addChildNode(collectionNode);
		
		// Value
		sqlCmd->addChildNode(sqlValue);
	}
	;

/******************************************************************
*
* UPDATE
*
******************************************************************/

update_stmt [uSQL::SQLStatement *sqlStmt]
	@init {
		uSQL::SQLValue *sqlValue = new uSQL::SQLValue();
		isAsync = false;
		whereSection = NULL;
	}
	: (isAsync=sync_operator)? UPDATE INTO collectionNode=collection_section SET property_section[sqlValue] (property_section[sqlValue])* (whereSection = where_section)?

	{
		// INSERT
		uSQL::SQLUpdate *sqlCmd = new uSQL::SQLUpdate();
		sqlCmd->setAsyncEnabled(isAsync);
		sqlStmt->addChildNode(sqlCmd);

		// Collection
		sqlCmd->addChildNode(collectionNode);
		
		// Value
		sqlCmd->addChildNode(sqlValue);

		// WHERE
		if (whereSection)		
			sqlStmt->addChildNode(whereSection);
	}
	;

property_section [uSQL::SQLValue *sqlValue]
	@init {
		
	}
	: property '=' expr=expression_literal

	{
		expr->setName(CG_ANTLR3_STRING_2_UTF8($property.text));
		sqlValue->addChildNode(expr);
	}
	;

/******************************************************************
*
* DELETE
*
******************************************************************/

delete_stmt [uSQL::SQLStatement *sqlStmt]
	@init {
		isAsync = false;
		whereSection = NULL;
	}
	: (isAsync=sync_operator)? DELETE FROM collectionNode=collection_section (whereSection = where_section)?

	{
		// DELETE
		uSQL::SQLDelete *sqlCmd = new uSQL::SQLDelete();
		sqlCmd->setAsyncEnabled(isAsync);
		sqlStmt->addChildNode(sqlCmd);

		// Collection
		sqlCmd->addChildNode(collectionNode);
		
		// WHERE
		if (whereSection)		
			sqlStmt->addChildNode(whereSection);
	}
	;

/******************************************************************
*
* Expression
*
******************************************************************/

expression [uSQL::SQLExpression *parentSqlExpr]
 	: sqlExpr=expression_literal {
		parentSqlExpr->addExpression(sqlExpr);
	  }
	| '{' (dictionary_literal[parentSqlExpr]) (COMMA dictionary_literal[parentSqlExpr])* '}'
	| '[' array_literal[parentSqlExpr] (COMMA array_literal[parentSqlExpr] )* ']'
	| sqlFunc=function_name '(' array_literal[sqlFunc] (COMMA array_literal[sqlFunc] )* ')' {
		parentSqlExpr->addExpression(sqlFunc);
	  }
	| exprLeft=expression_literal binOper=binary_operator exprRight=expression_literal {
		parentSqlExpr->addExpression(binOper);
		binOper->addExpression(exprLeft);
		binOper->addExpression(exprRight);
	  }
	;

expression_literal returns [uSQL::SQLExpression *sqlExpr]
	@init {
		sqlExpr = new uSQL::SQLExpression();
	}
 	: expression_literal_value[sqlExpr]
 	;

expression_literal_value [uSQL::SQLExpression *sqlExpr]
 	: property_literal {
		sqlExpr->setLiteralType(uSQL::SQLExpression::PROPERTY);
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($property_literal.text));
	  }
	| integer_literal {
		sqlExpr->setLiteralType(uSQL::SQLExpression::INTEGER);
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($integer_literal.text));
	  }
	| real_literal {
		sqlExpr->setLiteralType(uSQL::SQLExpression::REAL);
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($real_literal.text));
	  }
	| string_literal {
		sqlExpr->setLiteralType(1/*uSQL::SQLExpression::STRING*/);
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($string_literal.text));
	  }
	| true_literal {
		sqlExpr->setLiteralType(uSQL::SQLExpression::BOOLEAN);
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($true_literal.text));
	  }
	| false_literal {
		sqlExpr->setLiteralType(uSQL::SQLExpression::BOOLEAN);
		sqlExpr->setValue(CG_ANTLR3_STRING_2_UTF8($false_literal.text));
	  }
	;

dictionary_literal [uSQL::SQLExpression *parentSqlExpr]
	: name ':' sqlExpr=expression_literal {
		sqlExpr->setName(CG_ANTLR3_STRING_2_UTF8($name.text));
		parentSqlExpr->addExpression(sqlExpr);
	  }
	;

array_literal [uSQL::SQLExpression *parentSqlExpr]
	: sqlExpr=expression_literal {
		parentSqlExpr->addExpression(sqlExpr);
	  }
	;

function_name returns [uSQL::SQLFunction *sqlFunc]
	@init {
		sqlFunc = new uSQL::SQLFunction();
		sqlFunc->setLiteralType(uSQL::SQLExpression::FUNCTION);
	}
	: ID {
		sqlFunc->setValue(CG_ANTLR3_STRING_2_UTF8($ID.text));
	  }
	;

binary_operator returns [uSQL::SQLOperator *sqlOper]
	@init {
		sqlOper = new uSQL::SQLOperator();
		sqlOper->setLiteralType(uSQL::SQLExpression::OPERATOR);
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

property_literal
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
	: T R U E
	;
	
false_literal
	: F A L S E
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

property
	: ID 
	;
	
value 	
	: ID	
	;

name
	: ID
	;

collection_section returns [uSQL::SQLCollection *sqlCollection]
	@init {
		sqlCollection = new uSQL::SQLCollection();
	}
	: collection_name {
		sqlCollection->setValue(CG_ANTLR3_STRING_2_UTF8($collection_name.text));
	  }
	;

collection_name
	: ID
	| string_literal
	;
	
index_section returns [uSQL::SQLIndex *sqlIndex]
	@init {
		sqlIndex = new uSQL::SQLIndex();
	}
	: index_name {
		sqlIndex->setValue(CG_ANTLR3_STRING_2_UTF8($index_name.text));
	  }
	;

index_name
	: ID
	| string_literal
	;

where_section returns [uSQL::SQLWhere *sqlWhere]
	@init {
		sqlWhere = new uSQL::SQLWhere();
	}
	: WHERE expression[sqlWhere]
	;

/*------------------------------------------------------------------
 * LEXER RULES
 *------------------------------------------------------------------*/

ASTERISK
	: '*'
	;

PERIOD
	: '.'
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

SEMICOLON
	: ';'
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

DELETE
	: D E L E T E
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

COLLECTION_INDEX
	: I N D E X
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

SET
	: S E T
	;

SYNC
	: S Y N C
	;

UNION
	: U N I O N
	;

UPDATE
	: U P D A T E
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
