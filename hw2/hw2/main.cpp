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
  Dictionary * dict = new Dictionary("/usr/share/dict/words");
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
    
    // check if the same word >_>
    if (word_1 == word_2)
    {
      cout << "Path Found!\n 0 " << word_1 << endl
      << "Nodes Expanded: none" << endl << "Time Elapsed: 0s" << endl;
      return EXIT_SUCCESS;
    }
  
  // STEP: choose Queue (q) or Stack (s) implementations
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
  
  // STEP: create search_nodes (new empty data structure) QUEUE
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
    
    ++num_expanded;
    // STEP: "expand" the current search node
    // FOR EACH: word_step of current_node's word):
    for (size_t position = 0; position < wordsize; position++)
    {
      for (char letter='a'; letter <= 'z'; letter++)
      {
        string word_step = current_node->word.substr(0,position) 
        + letter
        + current_node->word.substr(position+1, wordsize);
        
        if (word_step == word_2)
        {
          // Print Solution (use a temp stack to make it pretty)
          cout << "Path Found!" << endl;
          SearchTreeNode* tempNode = current_node;
          stack<string> * tempStack = new stack<string>;
          tempStack->push(word_2);
          while (tempNode->parent)
          {
            tempStack->push(tempNode->word);
            tempNode = tempNode->parent;
          }
          size_t count = 0;
          cout << setw(2) << count;
          cout << " " << word_1 << endl;
          while (!tempStack->empty())
          {
            cout << setw(2) << ++count;
            cout << " " << tempStack->top() << endl;
            tempStack->pop();
          }
          // Print number of search nodes expanded
          cout << "Nodes Expanded: " << num_expanded << endl;
          cout << "Time Elapsed: " << timer.elapsed() << "s" << endl;
          return;
        }
        
        //  IF word_step is legal (in dictionary)
        //  && IF (word_step has been discovered) == false
        bool isLegal = dict->lookup(word_step);
        bool isExplored = explored(explored_words, word_step);
        
        if (isLegal && (isExplored == false))
        {
          // STEP: Create a newSearchNode containing word_step,
          //       pointing to it's parent (current_node)
          SearchTreeNode* newSearchNode = new SearchTreeNode (word_step, current_node);
          
          // STEP: push newSearchNode onto search_nodes queue
          //       add word_step to explored_words list
          search_nodes->push(newSearchNode);
          explored_words->insert(word_step, word_step);
        }
/*      ELSE
         word_step isn't in the dictionary
         AND/OR has already been explored
*/    }
    }              
  }
  cout << "Darn.\nNo StepByStep solution found..." << endl;
  cout << "Nodes Expanded: " << num_expanded << endl;
  cout << "Time Elapsed: " << timer.elapsed() << "s" << endl;
  return;
}


// STACK IMPLEMENTATION
void stackStepByStep(Dictionary* dict, string& word_1, string& word_2)
{
  Timer timer; // initiate timer
  
  // STEP: create search_nodes (new empty data structure) STACK
  stack<SearchTreeNode*> * search_nodes = new stack<SearchTreeNode*>;
  
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
    SearchTreeNode* current_node = search_nodes->top();
    search_nodes->pop();
    
    ++num_expanded;
    // STEP: "expand" the current search node
    // FOR EACH: word_step of current_node's word):
    for (size_t position = 0; position < wordsize; position++)
    {
      for (char letter='a'; letter <= 'z'; letter++)
      {
        string word_step = current_node->word.substr(0,position) 
        + letter
        + current_node->word.substr(position+1, wordsize);
        
        if (word_step == word_2)
        {
          // Print Solution (use a temp stack to make it pretty)
          cout << "Path Found!" << endl;
          SearchTreeNode* tempNode = current_node;
          stack<string> * tempStack = new stack<string>;
          tempStack->push(word_2);
          while (tempNode->parent)
          {
            tempStack->push(tempNode->word);
            tempNode = tempNode->parent;
          }
          size_t count = 0;
          cout << setw(2) << count;
          cout << " " << word_1 << endl;
          while (!tempStack->empty())
          {
            cout << setw(2) << ++count;
            cout << " " << tempStack->top() << endl;
            tempStack->pop();
          }
          // Print number of search nodes expanded
          cout << "Nodes Expanded: " << num_expanded << endl;
          cout << "Time Elapsed: " << timer.elapsed() << "s" << endl;
          return;
        }
        
        //  IF word_step is legal (in dictionary)
        //  && IF (word_step has been discovered) == false
        bool isLegal = dict->lookup(word_step);
        bool isExplored = explored(explored_words, word_step);
        
        if (isLegal && (isExplored == false))
        {
          // STEP: Create a newSearchNode containing word_step,
          //       pointing to it's parent (current_node)
          SearchTreeNode* newSearchNode = new SearchTreeNode (word_step, current_node);
          
          // STEP: push newSearchNode onto search_nodes queue
          //       add word_step to explored_words list
          search_nodes->push(newSearchNode);
          explored_words->insert(word_step, word_step);
        }
/*      ELSE
         word_step isn't in the dictionary
         AND/OR has already been explored
*/    }
    }              
  }
  cout << "Darn.\nNo StepByStep solution found..." << endl;
  cout << "Nodes Expanded: " << num_expanded << endl;
  cout << "Time Elapsed: " << timer.elapsed() << "s" << endl;
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

