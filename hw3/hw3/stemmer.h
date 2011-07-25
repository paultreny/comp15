/*	This is a modified version of the Porter stemming algorithm from 

	Porter, 1980, An algorithm for suffix stripping, Program, Vol. 14, no. 3,
	pp 130-137,

	See:  http://tartarus.org/~martin/PorterStemmer/
	      http://tartarus.org/~martin/PorterStemmer/c.txt

	This version is modified to include a std::string -> std::string function for general use.

*/

#include <string>

/** Compute and return a stemmed version of the given word */
std::string stem(const std::string &word); 


