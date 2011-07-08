//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  main.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <cctype>
#include "Dictionary.h"
#include "SearchTreeNode.h"
#include <queue>
#include <stack>
#include <list>

using namespace std;

int main (int argc, const char * argv[])
{
  // STEP: create and read-in words to Dictionary
  Dictionary * dict = new Dictionary("/Users/paulreny/GitHub/comp15/hw2/hw2/words");
  cerr << "Dictionary read in successfully!" << endl;

  // STEP: Ask user for word1, word2, read from cin
  string word_1;
  string word_2;
  bool legalwords = false;
  do{
    cout << "Please enter two words, separated by a space,\nThen press enter: ";
    cin >> word_1 >> word_2;
    // STEP: check if same length and legal words
    if (word_1.size() == word_2.size() &&
        dict->lookup(word_1) &&
        dict->lookup(word_2))
    legalwords = true;
    else cerr << "Invalid words!!!" << endl;
    } while (legalwords == false);
    
  // STEP: create search_nodes (new empty data structure) stack or queue, will do both
  queue<SearchTreeNode*> * search_nodes = new queue<SearchTreeNode*>;
  //stack<SearchTreeNode*> * search_nodes = new stack<SearchTreeNode*>;
  
  // STEP: create explored_words (empty list) storing all words we encounter in our search
  //list<SearchTreeNode*> * explored_words = new list<SearchTreeNode*>;
  
  // STEP: create a new search tree node 'root' with word1 and an empty parent path
  SearchTreeNode* root = new SearchTreeNode(word_1, NULL);
  
  // STEP: push 'root' onto search_nodes (stack or queue initially consists of just one search node
  search_nodes->push(root);
  
  // STEP: num_expanded = 0
  size_t num_expanded = 0;
  
  // STEP: WHILE search_nodes is not empty:
  while (!search_nodes->empty())
  {
      // STEP: current_node = search_nodes.remove() (pop next search node off the stack or queue
    SearchTreeNode* current_node = search_nodes->front();
    search_nodes->pop();
    // "expand" the current search node
    
      // ++num_expanded;
    ++num_expanded;
    
    // FOR (each word 'word' of current_node's word):
    for (size_t position = 0; position < current_node->word.size(); position++)
      {
      for (char letter='a'; letter <= 'z'; letter++)
        {
        size_t currentsize = current_node->word.size(); 
        string successor = current_node->word.substr(0,position)
                         + letter
                         + current_node->word.substr(position+1, currentsize);
        if (dict->lookup(successor))
          cout << successor << endl;
        }
      }
    
    // IF 'word' == word2
    
    // Print Solution (current_node's path plus word2
          // Print number of search nodes expanded
          
          // ELSE if 'word' is legal (in dictionary) && 'word' is not in explored_words:
          // Create a new search node 'w_node' with word 'word'
          // Set 'w_node's' path to current_node's path plus current_node
          // Insert 'word' into explored_words
          // Push 'w_node' onto search_nodes
  }
  
  // Make a print function?
  
  // STRING OPERATIONS
  // size()
  // operator[]
  // c_str()
  // substr()
  
  
  // insert code here...
  cout << "End" << endl;
  return EXIT_SUCCESS;
}
