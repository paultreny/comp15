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

using namespace std;

const int TREE_WIDTH = 26;
struct trie_node
{
  char letter;
  struct trie_node *next[TREE_WIDTH];

  inline trie_node(char kee = -1, trie_node *kids[] = NULL)
  {
    this->letter = kee;
  }
  
  inline trie_node* createRoot()
  {
    return (new trie_node(-1));
  }
  
  inline void add(const string & word)
  {
    int len = word.size();
    
    
    
  }
  
};






struct pTrieNode
{
  char key;
  struct pTrieNode *next_sib, *child_list;
  inline pTrieNode(char c_key = '\0', pTrieNode *next = NULL, pTrieNode *children = NULL)
  {
    this->key = c_key;
    this->next_sib = next;
    this->child_list = children;
  }
};

// CREATE NEW TRIE
pTrieNode * pTrieCreate()
{
  pTrieNode *root = new pTrieNode (NULL, NULL, NULL);
  return (root);
}

// ADD STRING TO TRIE
bool pTrieAdd( pTrieNode* &root, std::string keys)
{
  int len = keys.size();
  pTrieNode * level = root;
  for (int i = 0; i < len; ++i)
  {
    pTrieNode *found = NULL;
    pTrieNode *curr;
    for (curr = level; curr !=NULL; curr = curr->next_sib )
    {
      // if node on this current level matchest the current char}
      if (curr->key = keys[i])
      {
        found = curr;
        break;
      }
    }
    
    // no nodes at this level or none with next char in key
    // add new node with current char as next sibling
    if (!found)
    { 
      curr = new pTrieNode(keys[i]);
      found = curr;
    }
    level = found->child_list;
  }
  
  return true;
}


// RETURN TRUE IF KEY EXISTS
bool pTrieIsMember(pTrieNode* &root, std::string keys) // returns true if key in trie
{
  int len = keys.size();
  pTrieNode * level = root;
  for (int i = 0; i < len; ++i)
  {
    pTrieNode *found = NULL;
    pTrieNode *curr;
    for (curr = level; curr !=NULL; curr = curr->next_sib)
    {
      // if node on this current level matchest the current char}
      if (curr->key = keys[i])
      {
        found = curr;
        if (i == len)
        {
          return true;
        }
        break;
      }
    }
    
    // no nodes at this level or none with next char in key
    // add new node with current char as next sibling
    if (!found && i==len)
    { 
      return 0;
    }
    
    level = found->child_list;
  }
  return 1;
}

#endif // pTrie_H end









