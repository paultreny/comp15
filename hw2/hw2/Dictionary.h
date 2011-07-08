#ifndef DICTIONARY_H
#define DICTIONARY_H 0 

#include <cstdlib>
#include <string> 

typedef std::string element_t; // define element (word) type

class Dictionary { 
	
private:
  
  element_t *data;	// dynamically-allocated array of words
  unsigned int capacity, words;	// array allocated size, array usage size
  
public:
  
  // Dictionary constructor builds from a file
  Dictionary() { data = NULL; } 
  Dictionary(const std::string &filename) { data=NULL; read(filename); }
  Dictionary(const char *filename) { data=NULL; read(filename); }
  
  // Read a file, replace any current set of words with these
  void read(const char *filename);
  void read(const std::string &filename) { read(filename.c_str()); }
  
  // look up a word, return pointer-to-element or NULL
  bool lookup(const element_t &word); 
  
  // destroy a dictionary
  ~Dictionary() { if (data) { delete[] data; } }
  
};

#endif


