/******************************************************************
*
* uSQL for C++
*
* SQLOperator.cpp
*
* Copyright (C) Satoshi Konno 2011
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include<sstream>

#include <cybergarage/sql/node/SQLOperator.h>

const int uSQL::SQLOperator::UNKNOWN = 0;
const int uSQL::SQLOperator::SEQ = 1;
const int uSQL::SQLOperator::DEQ = 2;
const int uSQL::SQLOperator::LT = 3;
const int uSQL::SQLOperator::GT = 4;
const int uSQL::SQLOperator::LE = 5;
const int uSQL::SQLOperator::GE = 6;
const int uSQL::SQLOperator::NOTEQ = 7;
const int uSQL::SQLOperator::AND = 8;
const int uSQL::SQLOperator::OR = 9;

std::string &uSQL::SQLOperator::toString(std::string &buf) 
{
	uSQL::SQLExpression *exprLeft = getLeftExpression();
	uSQL::SQLExpression *exprRight = getRightExpression();

	std::ostringstream oss;
	std::string exprBuf;
            
    if (exprLeft)
    	oss << exprLeft->toString(exprBuf);
        
    switch (getValue()) {
  	case SEQ:
    	oss << "=";
    	break;
  	case DEQ:
    	oss << "==";
    	break;
  	case NOTEQ:
    	oss << "!=";
    	break;
  	case LT:
    	oss << "<";
    	break;
  	case LE:
    	oss << "<=";
    	break;
  	case GT:
    	oss << ">";
    	break;
  	case GE:
    	oss << ">=";
    	break;
  	case AND:
    	oss << "&";
    	break;
  	case OR:
    	oss << "|";
    	break;
    default:
    	oss << "?";
    	break;
	}
    
    if (exprRight)
    	oss << exprRight->toString(exprBuf);
        
    buf = oss.str();
    
    return buf;
}
