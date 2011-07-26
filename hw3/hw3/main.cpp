//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  main.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//
// Your job is to choose one of the data structures covered in class that can map a character string to a integer, with the objective of optimizing retrieval time. You are expected to justify your decision.
//
//
//

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <fstream>
#include "ptrie.h"
#include "hash.h"

using namespace std;

int main (int argc, const char * argv[])
{
// CREATE STOPWORDS TRIE
//  stopword_trie stop_words;
  const unsigned int TBLSZ = 93563; // choose a prime just in case
                                      // other fine choices:  1000003 2584853 3072263 8004823
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
    
		unsigned long hv = hash(w); 
		
    if (hv != hash(w)) { cerr << "The hash function is BROKEN." << endl; exit(-1); }
    
		if (table[hv % TBLSZ] )
    {
      cout << "Stop Word!" << endl;
    }
		table[hv % TBLSZ]++;
		keys++;
    unsigned int j = 0;
    
    while (j != TBLSZ)
    {
      cout << setw(6) << j << " " << table[j] << endl;
      ++j;
    }
	}
  cout << "Stop words hashed: " << keys << endl;
  cout << "HW3" << endl;
  
  const char FILENAME[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/waldo.txt";
  // CREATE DATA STRUCTURE
  int discard = 0;
  int count = 0;
  for (ifstream fin(FILENAME); !fin.eof(); fin>>ws)
 // while (!cin.eof())
  {
      string word;
      bool isWord = true;
      fin >> word;
      
      for (int i=0; i<word.size(); ++i )
      {
        isWord = isalpha(word[i]);
        if (!isWord)
        {
          ++discard;
          break;
        }
        word[i] = tolower(word[i]);
      }
      if( isWord && !table[hash(word) % TBLSZ] )
      {
        cout << word << endl;
        ++count;
      }
  }
  cout << count << endl;
  cout << discard << endl;
      // CHECK IF NOT A LETTER (isalpha)
    
      // CONVERT TO LOWERCASE (tolower)
    
      // READ WORD
      
      // COMPARE TO STOP WORDS TRIE // HASH FUNCTION?
            
      // ADD WORD TO DATA STRUCTURE
      // & INCREMENT COUNT OF WORD
      
  
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

