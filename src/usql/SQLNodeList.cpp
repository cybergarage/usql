/******************************************************************
*
* uSQL for C++
*
* Copyright (C) Satoshi Konno 2012
*
* This is licensed under BSD-style license, see file COPYING.
*
******************************************************************/

#include<sstream>

#include <usql/SQLNode.h>
#include <usql/SQLNodes.h>

static int SQLNodeListGetIncompleteLogicalOperatorIndex(uSQL::SQLNodeList *nodeList)
{
  int expressionsCnt = (int)nodeList->size();
  
  // Find only 'AND' nodes.
  for (int n=0; n<expressionsCnt; n++) {
    uSQL::SQLNode *node = nodeList->at(n);
    if (node->isOperatorNode() == false)
      continue;
    uSQL::SQLOperator *operNode = (uSQL::SQLOperator *)node;
    if (operNode->isAnd() == false)
      continue;
    if (operNode->getExpressions()->size() <= 0)
      return n;
  }
  
  // Find other operator nodes such as 'OR'.
  for (int n=0; n<expressionsCnt; n++) {
    uSQL::SQLNode *node = nodeList->at(n);
    if (node->isOperatorNode() == false)
      continue;
    uSQL::SQLOperator *operNode = (uSQL::SQLOperator *)node;
    if (operNode->getExpressions()->size() <= 0)
      return n;
  }
  
  return -1;
}

static bool SQLNodeListAddAsChildNode(uSQL::SQLNodeList *nodeList, uSQL::SQLNode *parentNode, int childNodeIndex) 
{
  if (nodeList->size() < (childNodeIndex + 1))
    return false;
    
  uSQL::SQLNode *childNode = nodeList->at(childNodeIndex);
  parentNode->addChildNode(childNode);
  nodeList->erase(nodeList->begin() + childNodeIndex);
  
  return true;
}

uSQL::SQLNodeList::SQLNodeList()
{
}

uSQL::SQLNodeList::~SQLNodeList()
{
  clear();
}

void uSQL::SQLNodeList::sort()
{
  std::string buf; 
  std::size_t l = size();
  if (l <= 1)
    return;
  for (uSQL::SQLNodeList::iterator node = begin(); node != end(); node++) {
    //std::cout << "SORT[" << (++n) << "] : " << (*node)->toString(buf) << std::endl;
  }
  
  int logicalOperIndex = SQLNodeListGetIncompleteLogicalOperatorIndex(this);
  while (1 <= logicalOperIndex) {
    uSQL::SQLNode *logicalOperNode = at(logicalOperIndex);
    SQLNodeListAddAsChildNode(this, logicalOperNode, (logicalOperIndex - 1));
    SQLNodeListAddAsChildNode(this, logicalOperNode, (logicalOperIndex));
    logicalOperIndex = SQLNodeListGetIncompleteLogicalOperatorIndex(this);
  }
}

void uSQL::SQLNodeList::clear()
{
  /* FIXME
  uSQL::SQLNodeList::iterator node = begin();
  while (node != end()) {
    node = erase(node);
    delete (*node);
  }
  */
  std::vector<SQLNode *>::clear();
}
