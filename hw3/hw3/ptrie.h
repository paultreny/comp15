//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  ptrie.h
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//

#ifndef PTRIE_H
#define PTRIE_H

#include <cstddef>
#include <limits>
#include <iostream>
#include <cassert>
#include <algorithm>
#include <numeric>
#include <queue>
#include <string>
#include <cstdlib>


struct pTrieNode
{
  char key;
  struct pTrieNode *next_sib, *child_list;
  struct pTrieNode *parent;
  inline pTrieNode(pTrieNode *parent_node = NULL, char c_key = '\0', pTrieNode *next = NULL, pTrieNode *children = NULL)
  {
    this->parent = parent_node;
    this->key = c_key;
    this->next_sib = next;
    this->child_list = children;
  }
};
/*
typedef struct pTrieCDT
{
  pTrieNode *root;
} pTrieCDT;
*/
//typedef struct pTrieCDT *pTrieADT;

// ADD STRING TO TRIE
bool pTrieAdd( pTrieNode &trie, std::string keys)
{
  pTrieNode * level = trie.parent;
  int i=0;
  for (;;)
  {
    pTrieNode *found = NULL;
    pTrieNode *curr;
    level->key = keys[i];
    
    for (curr = level; curr !=NULL; curr = curr->next_sib )
    {
      // if node on this current level matchest the current char
      if (keys[i] == curr->key)
      {
        found = curr;
        break;
      }
    }
    // no nodes at this level or none with next char in key
    if (!found) 
    {
      level->key = keys[i];
      
      //level->child_list = new pTrieNode(keys[i]);

//      level->next_sib = new pTrieNode(keys[i]);
      found = level->next_sib;    
    }
    if (keys[i] == '\0')
    {
      return 1;
    }
    
    level = found->child_list;
    ++i; 
  }
  return false;
}

// CREATE NEW TRIE
pTrieNode * pTrieCreate()
{
  pTrieNode* trie = new pTrieNode(NULL, '\0', NULL, NULL);
  return (trie);
}

// RETURN TRUE IF KEY EXISTS
bool pTrieIsMember(const pTrieNode &trie, std::string keys) // returns true if key in trie
{
  pTrieNode *level = trie.parent; // start at top level
  int i = 0; // start at beginning of key
  
  for(;;)
  {
    pTrieNode *found = NULL;
    pTrieNode *curr;
    
    for( curr = level; curr != NULL; curr = curr->next_sib )
    {
      // want a node at this level to match the current char in key
      if (curr->key == keys[i] )
      {
        found = curr;
        break;
      }
    }
    
    // if no nodes this level or none with next char in key, then not present
    if ( !found )
      return 0;
    
    // if we matched the end of key, it is in trie, ie, is a stopword
    if (keys[i] == '\0')
      return 1;
    
    // goto next level
    level = found->child_list;
    
    // advance in string key
    ++i;
  }
}

#endif // pTrie_H end









