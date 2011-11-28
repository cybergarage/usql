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
const int uSQL::SQLOperator::EQ = 1;
const int uSQL::SQLOperator::LT = 2;
const int uSQL::SQLOperator::GT = 3;
const int uSQL::SQLOperator::LE = 4;
const int uSQL::SQLOperator::GE = 5;
const int uSQL::SQLOperator::NOTEQ = 6;
const int uSQL::SQLOperator::AND = 7;
const int uSQL::SQLOperator::OR = 8;

std::string &uSQL::SQLOperator::toString(std::string &buf) 
{
	uSQL::SQLExpression *exprLeft = getLeftExpression();
	uSQL::SQLExpression *exprRight = getRightExpression();

	std::ostringstream oss;
	std::string exprBuf;
            
    if (exprLeft)
    	oss << exprLeft->toString(exprBuf);
        
    switch (getValue()) {
  	case EQ:
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
