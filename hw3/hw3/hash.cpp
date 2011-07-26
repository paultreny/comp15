//
//  hash.cpp
//  hw3
//
//  Created by Paul Reny on 7/26/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "hash.h"

#include <stdint.h>

// Jenkins's Hash (copied from COMP15/Spring 2011)
unsigned int jenkins(const char *key, unsigned int length) { 
  
	uint32_t hash = 0; 
  size_t i;
  
	for(i = 0; i < length; i++) {
		hash += key[i];
		hash += (hash << 10);
		hash ^= (hash >> 6);
	}    
	hash += (hash << 3);
	hash ^= (hash >> 11);
	hash += (hash << 15);
	return hash;
}

unsigned int paulhash(const char *key, unsigned int length) {
  unsigned int hash = 5381;
  unsigned int i;
  for( i=0; i < length; i++)
  {
    hash = ((hash << 5) + hash) + i; // hash * 33 + c
  }
  return hash;
}

unsigned int paulhashFNV( const char *key, unsigned int length)
{
  unsigned int hash = 2166136261U;
  unsigned int multFNV = 16777619;
  for( unsigned int i = 0; i < length; i++)
  {
    hash = hash ^ (key[i]);
    hash = hash * multFNV;
  }
  return hash;
}


unsigned int hash(const std::string& word) { 
	return paulhashFNV(word.c_str(), word.size());
}