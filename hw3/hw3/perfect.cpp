//
//  perfect.cpp
//  hw3
//
//  Created by Paul Reny on 7/26/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "hash.h" 
#include <string>
#include <stdint.h>

using namespace std;

unsigned int hash( const string &word ) { 
  
	static const unsigned int INIT_VALUE = 0;
	static const unsigned int MULTIPLIER = 256;
  
	unsigned int h = INIT_VALUE;
  
	for (const char *c = word.c_str(); *c; c++) { 
    
		// for each input byte
		h = h * MULTIPLIER + ((unsigned int)(*c));
    
	}
  
  
	return h;
  
  
  
}