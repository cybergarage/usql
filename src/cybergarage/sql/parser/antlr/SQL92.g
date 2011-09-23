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
    #include <cybergarage/sql/SQLParser.h>
}

@parser::includes
{
    #include <cybergarage/sql/SQLParser.h>
}

/*------------------------------------------------------------------
 * PARSER RULES
 *------------------------------------------------------------------*/

statement
	: select_statement
	;	

select_statement
	: SELECT
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

ID  :	('a'..'z'|'A'..'Z'|'_') ('a'..'z'|'A'..'Z'|'0'..'9'|'_')*
	;

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


ADD	
	: A D D 
	;

ALL
	: A L L
	;
	
ALLOCATE
	: A L L O C A T E
	;
	
ALTER
	: A L T E R
	;
	
AND
	: A N D
	;
	
ANY
	: A N Y
	;
	
ARE	
	: A R E
	;

AS
	: A S
	;

ASC
	: A S C
	;
	
ASSERTION
	: A S S E R T I O N
	;
	
AT
	: A T
	;
	
AUTHORIZATION
	: A U T H O R I Z A T I O N
	;
	
AVG
	: A V G
	;
	
BEGIN
	: B E G I N
	;
	
BETWEEN
	: B E T W E E N
	;
	
BIGINT
	: B I G I N T
	;
	
BIT
	: B I T
	;
	
BOOLEAN
	: B O O L E A N
	;
	
BOTH
	: B O T H
	;
BY
	: B Y
    ;
    
CALL
	: C A L L
    ;
    
CASCADE
	: C A S C A D E
    ;
    
CASCADED
	: C A S C A D E D
    ;
    
CASE
	: C A S E
    ;
    
CAST
	: C A S T
    ;

/*
CHAR
	: C H A R
    ;
 */
       
CHARACTER
	: C H A R A C T E R
    ;

/*    
CHECK
CLOSE
COALESCE
COLLATE
COLLATION
COLUMN
COMMIT
CONNECT
CONNECTION
CONSTRAINT
CONSTRAINTS
CONTINUE
CONVERT
CORRESPONDING
CREATE
CURRENT
CURRENT_DATE
CURRENT_TIME
CURRENT_TIMESTAMP
CURRENT_USER
CURSOR
DEALLOCATE
DEC
DECIMAL
DECLARE
DEFAULT
DEFERRABLE
DEFERRED
DELETE
DESC
DESCRIBE
DIAGNOSTICS
DISCONNECT
DISTINCT
DOUBLE
DROP
ELSE
END
END-EXEC
ESCAPE
EXCEPT
EXCEPTION
EXEC
EXECUTE
EXISTS
EXPLAIN
EXTERNAL
FALSE
FETCH
FIRST
FLOAT
FOR
FOREIGN
FOUND
*/

FROM
	: F R O M
	;
/*	
FULL
FUNCTION
GET
GETCURRENTCONNECTION
GLOBAL
GO
GOTO
GRANT
GROUP
HAVING
HOUR
IDENTITY
IMMEDIATE
IN
INDICATOR
INITIALLY
INNER
INOUT
INPUT
INSENSITIVE
INSERT
INT
INTEGER
INTERSECT
INTO
IS
ISOLATION
JOIN
KEY
LAST
LEFT
LIKE
LOWER
LTRIM
MATCH
MAX
MIN
MINUTE
NATIONAL
NATURAL
NCHAR
NVARCHAR
NEXT
NO
NOT
NULL
NULLIF
NUMERIC
OF
ON
ONLY
OPEN
OPTION
OR
ORDER
OUTER
OUTPUT
OVERLAPS
PAD
PARTIAL
PREPARE
PRESERVE
PRIMARY
PRIOR
PRIVILEGES
PROCEDURE
PUBLIC
READ
REAL
REFERENCES
RELATIVE
RESTRICT
REVOKE
RIGHT
ROLLBACK
ROWS
RTRIM
SCHEMA
SCROLL
SECOND
*/
SELECT
	: S E L E C T
	;
/*	
SESSION_USER
SET
SMALLINT
SOME
SPACE
SQL
SQLCODE
SQLERROR
SQLSTATE
SUBSTR
SUBSTRING
SUM
SYSTEM_USER
TABLE
TEMPORARY
TIMEZONE_HOUR
TIMEZONE_MINUTE
TO
TRANSACTION
TRANSLATE
TRANSLATION
TRIM
TRUE
UNION
UNIQUE
UNKNOWN
UPDATE
UPPER
USER
USING
VALUES
VARCHAR
VARYING
VIEW
WHENEVER
*/

WHERE
	: W H E R E
	;
/*	
WITH
WORK
WRITE
XML
XMLEXISTS
XMLPARSE
XMLQUERY
XMLSERIALIZE
YEAR
*/