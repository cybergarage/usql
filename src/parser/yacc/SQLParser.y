
/*
  <reserved word>    ::= 
         ABSOLUTE | ACTION | ADD | ALL | ALLOCATE | ALTER | AND | ANY | ARE 
     |     AS | ASC | ASSERTION | AT | AUTHORIZATION | AVG 
     |     BEGIN | BETWEEN | BIT | BIT_LENGTH | BOTH | BY 
     |     CASCADE | CASCADED | CASE | CAST | CATALOG | CHAR | CHARACTER | CHARACTER_LENGTH 
     |     CHAR_LENGTH | CHECK | CLOSE | COALESCE | COLLATE | COLLATION | COLUMN | COMMIT 
     |     CONNECT | CONNECTION | CONSTRAINT | CONSTRAINTS | CONTINUE | CONVERT | CORRESPONDING 
     |     CREATE | CROSS | CURRENT | CURRENT_DATE | CURRENT_TIME | CURRENT_TIMESTAMP | CURRENT_USER | CURSOR 
     |     DATE | DAY | DEALLOCATE | DEC | DECIMAL | DECLARE | DEFAULT 
     |     DEFERRABLE | DEFERRED | DELETE | DESC | DESCRIBE | DESCRIPTOR | DIAGNOSTICS 
     |     DISCONNECT | DISTINCT | DOMAIN | DOUBLE | DROP 
     |     ELSE | END | END -EXEC | ESCAPE | EXCEPT | EXCEPTION | EXEC | EXECUTE | EXISTS | EXTERNAL | EXTRACT 
     |     FALSE | FETCH | FIRST | FLOAT | FOR | FOREIGN | FOUND | FROM | FULL 
     |     GET | GLOBAL | GO | GOTO | GRANT | GROUP 
     |     HAVING | HOUR 
     |     IDENTITY | IMMEDIATE | IN | INDICATOR | INITIALLY | INNER | INPUT | INSENSITIVE 
     |     INSERT | INT | INTEGER | INTERSECT | INTERVAL | INTO | IS | ISOLATION 
     |     JOIN 
     |     KEY 
     |     LANGUAGE | LAST | LEADING | LEFT | LEVEL | LIKE | LOCAL | LOWER 
     |     MATCH | MAX | MIN | MINUTE | MODULE | MONTH 
     |     NAMES | NATIONAL | NATURAL | NCHAR | NEXT | NO | NOT | NULL | NULLIF | NUMERIC 
     |     OCTET_LENGTH | OF | ON | ONLY | OPEN | OPTION | OR | ORDER | OUTER | OUTPUT | OVERLAPS 
     |     PAD | PARTIAL | POSITION | PRECISION | PREPARE | PRESERVE | PRIMARY | PRIOR | PRIVILEGES | PROCEDURE | PUBLIC 
     |     READ | REAL | REFERENCES | RELATIVE | RESTRICT | REVOKE | RIGHT | ROLLBACK | ROWS 
     |     SCHEMA | SCROLL | SECOND | SECTION | SELECT | SESSION | SESSION_USER | SET 
     |     SIZE | SMALLINT | SOME | SPACE | SQL | SQLCODE | SQLERROR | SQLSTATE | SUBSTRING | SUM | SYSTEM_USER 
     |     TABLE | TEMPORARY | THEN | TIME | TIMESTAMP | TIMEZONE_HOUR | TIMEZONE_MINUTE 
     |     TO | TRAILING | TRANSACTION | TRANSLATE | TRANSLATION | TRIM | TRUE 
     |     UNION | UNIQUE | UNKNOWN | UPDATE | UPPER | USAGE | USER | USING 
     |     VALUE | VALUES | VARCHAR | VARYING | VIEW 
     |     WHEN | WHENEVER | WHERE | WITH | WORK | WRITE 
     |     YEAR 
     |     ZONE
*/

/******************************************************************
* Reserved Word
******************************************************************/

%token ABSOLUTE ACTION ADD ALL ALLOCATE ALTER AND ANY ARE 
%token AS ASC ASSERTION AT AUTHORIZATION AVG 
%token BEGIN BETWEEN BIT BIT_LENGTH BOTH BY 
%token CASCADE CASCADED CASE CAST CATALOG CHAR CHARACTER CHARACTER_LENGTH 
%token CHAR_LENGTH CHECK CLOSE COALESCE COLLATE COLLATION COLUMN COMMIT 
%token CONNECT CONNECTION CONSTRAINT CONSTRAINTS CONTINUE CONVERT CORRESPONDING 
%token CREATE CROSS CURRENT CURRENT_DATE CURRENT_TIME CURRENT_TIMESTAMP CURRENT_USER CURSOR 
%token DATE DAY DEALLOCATE DEC DECIMAL DECLARE DEFAULT 
%token DEFERRABLE DEFERRED DELETE DESC DESCRIBE DESCRIPTOR DIAGNOSTICS 
%token DISCONNECT DISTINCT DOMAIN DOUBLE DROP 
%token ELSE END END -EXEC ESCAPE EXCEPT EXCEPTION EXEC EXECUTE EXISTS EXTERNAL EXTRACT 
%token FALSE FETCH FIRST FLOAT FOR FOREIGN FOUND FROM FULL 
%token GET GLOBAL GO GOTO GRANT GROUP 
%token HAVING HOUR 
%token IDENTITY IMMEDIATE IN INDICATOR INITIALLY INNER INPUT INSENSITIVE 
%token INSERT INT INTEGER INTERSECT INTERVAL INTO IS ISOLATION 
%token JOIN 
%token KEY 
%token LANGUAGE LAST LEADING LEFT LEVEL LIKE LOCAL LOWER 
%token MATCH MAX MIN MINUTE MODULE MONTH 
%token NAMES NATIONAL NATURAL NCHAR NEXT NO NOT NULL NULLIF NUMERIC 
%token OCTET_LENGTH OF ON ONLY OPEN OPTION OR ORDER OUTER OUTPUT OVERLAPS 
%token PAD PARTIAL POSITION PRECISION PREPARE PRESERVE PRIMARY PRIOR PRIVILEGES PROCEDURE PUBLIC 
%token READ REAL REFERENCES RELATIVE RESTRICT REVOKE RIGHT ROLLBACK ROWS 
%token SCHEMA SCROLL SECOND SECTION SELECT SESSION SESSION_USER SET 
%token SIZE SMALLINT SOME SPACE SQL SQLCODE SQLERROR SQLSTATE SUBSTRING SUM SYSTEM_USER 
%token TABLE TEMPORARY THEN TIME TIMESTAMP TIMEZONE_HOUR TIMEZONE_MINUTE 
%token TO TRAILING TRANSACTION TRANSLATE TRANSLATION TRIM TRUE 
%token UNION UNIQUE UNKNOWN UPDATE UPPER USAGE USER USING 
%token VALUE VALUES VARCHAR VARYING VIEW 
%token WHEN WHENEVER WHERE WITH WORK WRITE 
%token YEAR 
%token ZONE

/******************************************************************
 SQL special character
******************************************************************/

Asterisk
	: '*'
	;

/******************************************************************
 Constraints
******************************************************************/

TableName
	: QualifiedName
	;
/*
	| <qualified local table name>
*/

/******************************************************************
 Data Types
******************************************************************/

QualifiedName
	: QualifiedIdentifier
	;
/*
	: [ <schema name> <period> ] <qualified identifier>
*/

/******************************************************************
 Literal Numbers, Strings, Dates and Times
******************************************************************/

Identifier
	: [ <introducer> <character set specification> ] <actual identifier>
	;
/*
	: [ <introducer> <character set specification> ] <actual identifier>
*/

/******************************************************************
 SQL Module
******************************************************************/

QualifiedIdentifier
	: Identifier
	;

/******************************************************************
 Queries
******************************************************************/

QuerySpecification
	: SELECT SetQuantifier SelectList TableExpression
	;

SetQuantifier
	: DISTINCT
	| ALL
	|
	;

SelectList
	: Asterisk
	| SelectSublists
	;

SelectSublists
	: SelectSublist
	| SelectSublists ',' SelectSublist
	;

SelectSublist
	: <derived column>
	| <qualifier> <period> Asterisk
	;

TableExpression
	: FromClause
	;
/*
	| [ <where clause> ]
	| [ <group by clause> ]
	| [ <having clause> ]
*/

FromClause
	: FROM TableReferences
	;

TableReferences
	: TableReference
	| TableReferences ',' TableReference
	;


TableReference
	: TableName
	;
/*
        | <table name> [ <correlation specification> ]
	| <derived table> <correlation specification>
	| <joined table>
*/
