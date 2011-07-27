#ifndef HASH_FUNCTION_H 
#define HASH_FUNCTION_H 0

#include <string>

// The hash function.  You implement this in hash.cpp

unsigned int hash( const std::string &word );
unsigned int DJBHash(const std::string& str);

#endif	
