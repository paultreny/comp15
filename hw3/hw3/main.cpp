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
//
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include "AVLTree.h"
#include "hash.h"

using namespace std;
using namespace comp15;

int main (int argc, const char * argv[])
{
// CREATE STOPWORDS TRIE
//  stopword_trie stop_words;

  const unsigned int TBLSZ = 8004823; // choose a prime just in case
                           //93563         // other fine choices:  1000003 2584853 3072263 8004823
  const char STOPFILE[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/stopwords.txt"; // /usr/share/dict/words
  unsigned int keys = 0;			// 	and keys inserted into table
	unsigned int *table = new unsigned int[TBLSZ]; 
  
  for (unsigned int i=0; i<TBLSZ; i++)
  {
    table[i] = 0; 
  }
  
	for (ifstream fin(STOPFILE); !fin.eof(); fin>>ws)
  {
		if (!fin) { cerr << "Error:  Failed to read from input file \""
                     << STOPFILE << "\"" << endl; exit(-1); }
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
		keys++;
    }
  }
  
  cout << "Stop words hashed: " << keys << endl;
  cout << "HW3" << endl;
 
  
    
  const char FILENAME[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/bard.txt";
  // CREATE DATA STRUCTURE
  AVLTree<string, int> * word_count = new AVLTree<string, int>;
  
  int unique_words = 0;
  int maxcount = 0;
  string maxword;
  
  ifstream fin(FILENAME);
  while (!fin.eof())
  {
    string word;
    //bool isLetter = false;
    bool isWord = false;
    fin >> word;
    bool foundStart = false;
    bool foundEnd = false;
    int substr_start = 0;
    int substr_len = 0;
    for (int i=0; i<word.size(); i++)
    {
      //isLetter = isalpha(word[i]); // CHECK IF NOT A LETTER (isalpha)
      
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
          word[i] = tolower(word[i]);
        }        // CONVERT TO LOWERCASE (tolower)
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
        substr_len = word.size() - substr_start;
      }
      word = word.substr(substr_start, substr_len);
    }
    if( isWord && table[hash(word) % TBLSZ] == 0) // COMPARE TO STOP WORDS
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

