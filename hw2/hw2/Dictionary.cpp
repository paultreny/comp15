//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  Dictionary.cpp
//
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "Dictionary.h"
#include <algorithm>
#include <iostream> // notox
#include <cassert>
#include <fstream>
using namespace std;

// insert a word into the dictionary
void Dictionary::read(const char *filename) { 
  
	if (!data) { 
		capacity = 10;  // arbitrary initial capacity
		data = new element_t[capacity];
	} 
	words = 0;
  
  
	ifstream fin(filename); 
	assert(fin);
	fin >> ws;
	while (!fin.eof()) { 
    
		// need to expand dictionary?
		if (words == capacity) { 
			capacity = (capacity+1)*2; // double capacity
			element_t *newdata = new element_t[capacity]; 
			for (unsigned int i=0; i<words; i++) { 
				newdata[i] = data[i]; // copy word
			}
			delete[] data;
			data = newdata;
		}
    
		fin >> data[words++] >> ws; 
    
	}
  
	// The following code will SORT the array using the STL and the
	// (overloaded) operator<(const string&,const string&) operator.
  
	std::sort( data+0, data+words ); // uncomment this to sort the array here.
  
}

// look up a word, return pointer-to-element or NULL
bool Dictionary::lookup(const element_t &query_word) { 
  
	/*
   for (unsigned int i=0; i<words; i++) { 
   if ( data[i] == query_word ) { return true; }
   
   }
   return false;
   */
  
	unsigned int lo=0; // lowest possible index of query_word
	unsigned int hi=words; // (one greater than) the highest possible index of query_word
  
	// invariant(s):
	//	lo < hi (they don't index the same thing)
	//	data[lo] <= search word 
	//	data[hi] >  search word  (or hi is out-of-bounds)
	//  neither data[lo] nor data[hi] are search word (i.e. we haven't found it yet)
	while ( lo < hi ) { 
    
		int mid = (lo+hi)/2;
    
		int cmp = strcmp(query_word.c_str(), data[mid].c_str()); // compare 2 strings, return int
    
		if (cmp == 0) { // cmp==0 means two strings equal
			return true;
		} else if (cmp < 0) { // cmp < 0 means query_string < data[mid]
			hi = mid;
		} else { // cmp > 0 means query_string > data[mid]
			lo = mid+1;
		}
		
	}
  
	return false;
  
}

