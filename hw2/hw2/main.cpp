//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  main.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//


#include "Timer.h"
using namespace comp15;

#include <iostream>
#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <cctype>
#include "Dictionary.h"
#include "SearchTreeNode.h"
#include "AVLTree.h"
#include <queue>
#include <stack>
#include <list>
#include <algorithm>
using namespace std;

void queueStepByStep(Dictionary* dict, string& word_1, string& word_2);
void stackStepByStep(Dictionary* dict, string& word_1, string& word_2);
bool explored (AVLTree<string, string>*& AVLExplored, string& searchword);

int main ()
{
  cout << "Welcome to StepByStep" << endl;
  // STEP: create and read-in words to Dictionary
  Dictionary * dict = new Dictionary("/Users/paulreny/GitHub/comp15/hw2/hw2/words");
  cout << "Dictionary read successful!" << endl;

  // STEP: Ask user for word1, word2, read from cin
  string word_1;
  string word_2;
  bool legalwords = false;
  char qS = 'q';
  do{
    cout << "Please enter two words, separated by a space,\nThen press enter: ";
    cin >> word_1 >> word_2;
    // STEP: check if same length and legal words
    if (word_1.size() == word_2.size() &&
        dict->lookup(word_1) &&
        dict->lookup(word_2))
    legalwords = true;
    else cout << "Invalid word pair! Try again!" << endl;
    } while (legalwords == false);
  
  // STEP: choose Queue (q) or Stack (s)
  do {
    cout << "Queue (q) or Stack (s)? : ";
    cin >> qS;
    qS = tolower(qS);
    if (qS != 'q' && qS != 's')
      cout << "Invalid choice! Try again!" << endl;
  }while (qS != 'q' && qS != 's');
  
  if (qS == 'q')
    queueStepByStep(dict, word_1, word_2);
  if (qS == 's')
    stackStepByStep(dict, word_1, word_2);
  return EXIT_SUCCESS;
}


// QUEUE IMPLEMENTATION
void queueStepByStep(Dictionary* dict, string& word_1, string& word_2)
{
  Timer timer; // initiate timer
  
  // STEP: create search_nodes (new empty data structure) queue
  queue<SearchTreeNode*> * search_nodes = new queue<SearchTreeNode*>;
  
  // STEP: create a new search tree node root with word_1 and a NULL parent path
  //       & push root onto search_nodes, initially consists of just this one node
  SearchTreeNode* root = new SearchTreeNode(word_1, NULL);  
  search_nodes->push(root);
  
  // STEP: create explored_words (empty list) storing all words we encounter in our search
  AVLTree<string, string> * explored_words = new AVLTree<string, string>;
  explored_words->insert(word_1, word_1);
  
  // STEP: num_expanded = 0
  size_t num_expanded = 0;
  size_t wordsize = word_1.size();
  
  // STEP: WHILE search_nodes is not empty:
  while (!search_nodes->empty())
  {
    // STEP: current_node = search_nodes.remove() (pop next search node off the stack or queue
    SearchTreeNode* current_node = search_nodes->front();
    search_nodes->pop();
    //cout << "Popped " << current_node->word << endl;
    // "expand" the current search node
    
    // ++num_expanded;
    ++num_expanded;
    //cout << "Num_expanded: " << num_expanded << endl;
    
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
          // cout << word_1 << endl;
          SearchTreeNode* tempNode = current_node;
          stack<string> * tempStack = new stack<string>;
          tempStack->push(word_2);
          while (tempNode->parent)
          {
            tempStack->push(tempNode->word);
            // cout << tempNode->word << endl;
            tempNode = tempNode->parent;
            
          }
          size_t count = 0;
          cout << setw(2) << count;
          cout << " " << word_1 << endl;
          
          // tempStack->push(word_1);
          while (!tempStack->empty())
          {
            cout << setw(2) << ++count;
            cout << " " << tempStack->top() << endl;
            tempStack->pop();
          }
          // cout << word_2 << endl;
          // Print number of search nodes expanded
          cout << "Nodes Expanded: " << num_expanded << endl;
          cout << "Time Elapsed: " << timer.elapsed() << endl;
          return;
        }
        
        //  IF successor is legal (in dictionary)
        //  && IF (successor has been discovered) == false
        bool isLegal = dict->lookup(successor);
        bool isExplored = explored(explored_words, successor);
        
        if (isLegal && (isExplored == false))
        {
          // STEP: Create a newSearchNode containing successor,
          //       pointing to it's parent (current_node)
          SearchTreeNode* newSearchNode = new SearchTreeNode (successor, current_node);
          
          // STEP: push newSearchNode onto search_nodes queue
          //       add successor to explored_words list
          search_nodes->push(newSearchNode);
          explored_words->insert(successor, successor);
          
          //cout << "Pushed " << successor << " (" << current_node->word << ")" << endl;
        }
/*      ELSE
         successor isn't in the dictionary
         AND/OR has already been explored
*/    }
    }              
  }
  cout << "Darn.\nNo StepByStep solution found..." << endl;
  cout << "Nodes Expanded: " << num_expanded << endl;
  cout << "Time Elapsed: " << timer.elapsed() << endl;
  return;
}

void stackStepByStep(Dictionary* dict, string& word_1, string& word_2)
{
  
  
  
  
  
  return;
}


bool explored (AVLTree<string, string>*& AVLExplored, string& searchword)
{
  string * temp = AVLExplored->lookup(searchword);
  if (temp)
  {
    if (*temp==searchword)
      return true;
  }
  return false;
}

