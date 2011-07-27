//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  main.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//
// Your job is to choose one of the data structures covered in class that can 
// map a character string to a integer, with the objective of optimizing
// retrieval time. You are expected to justify your decision.
//
// I've chosen to use a Hash function for comparing the stop words, and
// an AVL tree for keeping track of the unique words and their number of
// occurances.
//
// I did this for a couple of reasons. A hash table for the small number of
// of stop words (319) means that it is relatively easy to compare a hash of
// a word as it is input, and if there is a conflict, then it is ignored, as
// it shares the same address as a stopword.
//
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

int main (int argc, const char * argv[])
{
  //const char STOPFILE[] = "/g/15/2011uc/public_html/homework/hw3/stopwords.txt";
  const char STOPFILE[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/stopwords.txt";
  int stop_hashed = 0; // 
  const unsigned long TBLSZ = 8004823; // choose a prime just in case
                                       //93563         // other fine choices:  1000003 2584853 3072263 8004823
	unsigned long *table = new unsigned long[TBLSZ]; 
  
  for (unsigned long i=0; i<TBLSZ; i++) 
  {
    table[i] = 0; // Zero out table
  }
  
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
    
    if (hv != hash(w)) // if the hash function doesn't work, cerr <<
    {
      cerr << "The hash function is BROKEN." << endl; exit(-1);
    }
    
		if (table[hv % TBLSZ] == 1) // if there is a hash conflict, 
    { 
      cout << "StopWord Hash Conflict! " << w << " " << (hv % TBLSZ) << endl;
    }
    else
    {
      table[hv % TBLSZ]++;
      stop_hashed++;
    }
  }
  
  cout << "Stop words hashed: " << stop_hashed << endl;
  cout << "HW3" << endl;
  
  
  
  // CREATE DATA STRUCTURE
  AVLTree<string, int> * word_count = new AVLTree<string, int>;
  
  int unique_words = 0;
  int maxcount = 0;
  string maxword;
  
  //  const char FILENAME[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/flatland.txt";
  //  ifstream fin(FILENAME);
  //  while (!fin.eof())
  while (!cin.eof())
  {
    string word;
    bool isWord = false;
    //fin >> word;
    cin >> word;
    bool foundStart = false;
    bool foundEnd = false;
    int substr_start = 0;
    int substr_len = 0;
    for (int i=0; i<word.size(); i++)
    {      
      if (isalpha(word[i])) // if at least one letter
      {
        if (!foundStart)
        {
          substr_start = i;
          foundStart = true;
        }
        if (!foundEnd)
        {
          ++substr_len;
          isWord = true;
          word[i] = tolower(word[i]); // CONVERT TO LOWERCASE (tolower)
        }       
      }
      else
      {
        if (isWord)
        {
          foundEnd = true;
        }
      }
    }
    if (isWord)
    {
      if (!foundEnd)
      {
        substr_len = (int)word.size() - substr_start;
      }
      word = word.substr(substr_start, substr_len);
    }
    //if( isWord && !pTrieIsMember(stopTrie, word) ) // COMPARE TO STOP WORDS
    if( isWord && ( table[hash(word) % TBLSZ] == 0) ) 
    {
      if (word_count->lookup(word))
      {
        int *count = word_count->lookup(word);
        *count = *count + 1;
        if (*count > maxcount)
        {
          maxcount = *count;
          maxword = word;
        }
      }
      else
      {
        word_count->insert(word, 1);
        ++unique_words;
      }
    }
  }
  cout << "unique words: " << unique_words << endl;
  cout << "most frequent: " << endl << maxword << " " << maxcount << " times." << endl;
  
  // DATA STRUCTURE THOUGHTS
  //
  // Heap/Priority Queue might be good, would keep track of words with the highest occurance
  //
  //
  //
  //
  // 
  
  return EXIT_SUCCESS;
}

