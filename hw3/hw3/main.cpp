//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  main.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//


#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include "AVLTree.h"
#include "hash.h"

using namespace comp15;

using namespace std;

int main ()
{
  // STOPWORD Hash Table setup
  // large prime to avoid collisions, memory is cheap!
  const unsigned long TBLSZ = 8004823;
	unsigned long *table = new unsigned long[TBLSZ]; 
  for (unsigned long i=0; i<TBLSZ; i++) 
  {
    table[i] = 0; // Zero out table
  }
  
  // FILE INPUT setup
  const char STOPFILE[] = "/g/15/2011uc/public_html/homework/hw3/stopwords.txt";
  //const char STOPFILE[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/stopwords.txt";
  int stop_hashed = 0;
  
  for (ifstream fin(STOPFILE); !fin.eof(); fin>>ws)
  {
		if (!fin)     // Read in and error check the file input
    {
      cerr << "Error reading \"" << STOPFILE << "\"" << endl;
      exit(-1);
    }
    
    string w;
		fin >> w;
		unsigned long hv = hash(w); // hash stop words using murmurhash3
		if (table[hv % TBLSZ] == 1) // if there is a hash conflict, output error
    { 
      cout << "Stopword Collision! Fix Hash! " << w
           << " " << (hv % TBLSZ) << endl;
    }
    else
    {
      ++table[hv % TBLSZ];
      ++stop_hashed;
    }
  }
  cout << "Stop words: " << stop_hashed << endl;
  
  
  // CREATE DATA STRUCTURE
  // Chosen to use AVLTree, for ease of use and speed
  AVLTree<string, int> * word_count = new AVLTree<string, int>;
  int unique_words = 0, maxcount = 0;
  string maxword;
  
  
  // FILE INPUT Setup / cin function
  //  const char FILENAME[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/flatland.txt";
  //  ifstream fin(FILENAME);
  //  while (!fin.eof())
  while (!cin.eof()) // redirect standard input, ie,  "./main < flatland.txt"
  {
    string word;
    bool isWord = false;
    //fin >> word;
    cin >> word;
    bool foundStart = false;
    bool foundEnd = false;
    int substr_start = 0;
    int substr_len = 0;
    
    
    // STRING PARSING for file input
    for (int i=0; i< (int)word.size(); i++)
    {      
      if (isalpha(word[i])) // finds and marks the position of first letter
      {
        if (!foundStart) // has start of word been found?
        {
          substr_start = i;
          foundStart = true;
        }
        if (!foundEnd) // has end of word been found?
        {
          ++substr_len;
          isWord = true;// if a letter present, it is a word
          word[i] = tolower(word[i]); // CONVERT TO LOWERCASE (tolower)
        }       
      }
      else // once at end of word, if a second symbol isn't encountered
      {    
        if (isWord)
        {
          foundEnd = true;
        }
      }
    }
    if (isWord)
    {
      if (!foundEnd) // if only a first symbol, trim front part of string
      {
        substr_len = (int)word.size() - substr_start;
      }
      word = word.substr(substr_start, substr_len); // trim string of non-chars
    }
    
    
    // STRING COMPARISON with stopwords, if hash collision, it is a stopword
    if( isWord && ( table[hash(word) % TBLSZ] == 0) ) 
    {
      if (word_count->lookup(word))         // IF word is already in our tree
      {                                     // increment count++
        int *count = word_count->lookup(word);
        *count = *count + 1;
        if (*count > maxcount) 
        {
          maxcount = *count;
          maxword = word;
        }
      }
      else                                  // If a new word, insert with 1
      {                                     // occurance
        word_count->insert(word, 1);
        ++unique_words;
      }
    }
  }
  cout << "Unique Words:  " << unique_words << endl;
  cout << "Most Frequent:\n " << maxword << " ~ " << maxcount << " times!" << endl;
  
  return EXIT_SUCCESS;
}

