//
//  main.cpp
//  hw2
//
//  Created by Paul Reny on 7/7/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <iostream>
#include "Dictionary.h"

using namespace std;

int main (int argc, const char * argv[])
{
  // STEP: Ask user for word1, word2, read from cin
  
  // STEP: check (using dictionary->lookup) if legal words, of same length
  
  // STEP: create search_nodes (new empty data structure) stack or queue, will do both
  
  // STEP: create explored_words (empty list) storing all words we encounter in our search
  
  // STEP: create a new search tree node 'root' with word1 and an empty parent path
  
  // STEP: push 'root' onto search_nodes (stack or queue initially consists of just one search node
  
  // STEP: num_expanded = 0
  
  // STEP: WHILE search_nodes is not empty:
      // STEP: current_node = search_nodes.remove() (pop next search node off the stack or queue
      // "expand" the current search node
      // ++num_expanded;
      // FOR (each word 'word' of current_node's word):
          // IF 'word' == word2
          // Print Solution (current_node's path plus word2
          // Print number of search nodes expanded
          
          // ELSE if 'word' is legal (in dictionary) && 'word' is not in explored_words:
          // Create a new search node 'w_node' with word 'word'
          // Set 'w_node's' path to current_node's path plus current_node
          // Insert 'word' into explored_words
          // Push 'w_node' onto search_nodes
  
      //  
  
  // Make a print function?
  
  // STRING OPERATIONS
  // size()
  // operator[]
  // c_str()
  // substr()
  
  
  // insert code here...
  std::cout << "Hello, World!\n";
  return 0;
}

