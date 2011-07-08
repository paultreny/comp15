//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  SearchTreeNode.h
//
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef SEARCHTREENODE_H
#define SEARCHTREENODE_H 0 

#include <string>

using namespace std;

class SearchTreeNode
{ 
public:
  string word; // the word currently considered
  SearchTreeNode *parent; // pointer to the search tree node that expanded to create this node (NULL for the search tree's root)

  // DEFAULT CONSTRUCTOR (With default value for word, and default NULL for parent
  SearchTreeNode (string w = string(), SearchTreeNode* p = NULL){ word = w; parent = p;};
  ~SearchTreeNode() { parent = NULL; delete parent; };
};
#endif
