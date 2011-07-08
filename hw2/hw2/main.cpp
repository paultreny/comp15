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
#include <algorithm>

using namespace std;

bool explored (list<string>*&, string&);

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
  list<string> * explored_words = new list<string>;
  explored_words->push_back(word_1);
  
  // STEP: create a new search tree node 'root' with word1 and an empty parent path
  SearchTreeNode* root = new SearchTreeNode(word_1, NULL);
  
  // STEP: push 'root' onto search_nodes (stack or queue initially consists of just one search node
  search_nodes->push(root);
  
  // STEP: num_expanded = 0
  size_t num_expanded = 0;
  size_t wordsize = word_1.size();
  
  // STEP: WHILE search_nodes is not empty:
  while (!search_nodes->empty())
  {
      // STEP: current_node = search_nodes.remove() (pop next search node off the stack or queue
    SearchTreeNode* current_node = search_nodes->front();
    search_nodes->pop();
    cout << "Popped " << current_node->word << endl;
    // "expand" the current search node
    
    // ++num_expanded;
    ++num_expanded;
    cout << "Num_expanded: " << num_expanded << endl;
    
    // FOR (each word 'word' of current_node's word):
    for (size_t position = 0; position < wordsize; position++)
    {
      for (char letter='a'; letter <= 'z'; letter++)
      {
        string successor = current_node->word.substr(0,position) 
        + letter
        + current_node->word.substr(position+1, wordsize);
       
        // IF successor == word_2
        if (successor == word_2)
        {
          // Print Solution (current_node's path plus word2
          cout << "Path Found!" << endl;
          cout << word_1 << endl;
          SearchTreeNode* tempNode = current_node;
          while (tempNode->parent)
          {
            cout << tempNode->word << endl;
            tempNode = tempNode->parent;
          }
          cout << word_2 << endl;
          // Print number of search nodes expanded
          cout << "Nodes Expanded: " << num_expanded << endl;
          return EXIT_SUCCESS;
        }
        
        //  IF successor is legal (in dictionary)
        if (dict->lookup(successor))
        {
          // IF successor is not in explored_words
          if (!explored(explored_words, current_node->word))
          {
            cout  << successor << " has not been explored..." << endl;

            // Create a newSearchNode containing successor, pointing to it's parent, current_node
            SearchTreeNode* newSearchNode = new SearchTreeNode (successor, current_node);
            // Push 'w_node' onto search_nodes
            search_nodes->push(newSearchNode);
            // Insert successor into explored_words
            explored_words->push_back(successor);
            cout << "Pushed " << successor << " onto search_nodes, it's parent is " << current_node->word << endl;
          }
          else
            cout << successor << " has already been explored." << endl;
        }
      }
      //      current_node = current_node->parent;
    }
              
  }
  
  // Make a print function?
  
  // STRING OPERATIONS
  // size()
  // operator[]
  // c_str()
  // substr()
  
  
  cout << "End" << endl;
  return EXIT_SUCCESS;
}

bool explored (list<string>*& exploredList, string& searchword)
{
  for (list<string>::iterator it = exploredList->begin();
       it != exploredList->end();
       it++)
    {
      cout << "*it " << *it << endl;
      if (*it == searchword)
        return true;
    }
  return false;
}

