#include <cstddef> // `size_t' (see http://en.wikipedia.org/wiki/Size_t)

#ifndef SORT_H
#define SORT_H

namespace comp15 { 

	typedef int integer_t; 	// could change to longer/shorter/unsigned int type (but not for this lab!)
	void sort(integer_t *A, size_t n);

}//namespace
#endif 
