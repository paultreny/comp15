/*
	
	Defines the template type Heap<element_t> which represents a binary MAX heap.

	bool operator<(const element_t&, const element_t&) must be defined.

	default constructor for element_t must be defined.

	Internally, heap is stored in an array with the top element in index zero.

*/

#ifndef COMP15_HEAP_H
#define COMP15_HEAP_H

#include <algorithm> // swap
#include <vector> // vector
#include <cstring> // memcpy

namespace comp15 { 

template <typename element_t>
class Heap {

	protected:  

		size_t alloc; // allocated space 
		element_t *A;  // the array of data, indecies used are zero through n-1 (STORAGE)
		int n; // heap size

		// ensure heap has enough space for n elements
		void reserve(size_t n); 

		// make a heap from the possibly-out-of-place element at i, O(lg n)
		void reheapify_up(int i);

		// make a heap from the possibly-out-of-place element at i, O(lg n)
		void reheapify_down(int i);

		// swap nodes at indecies i and j
		virtual void swap(int i, int j) { std::swap(A[i],A[j]); }
	
		// enforce heap property that node @ index i is >= node @ index j
		// return true iff values were swapped (MAX_HEAP)
		virtual bool hp(int i, int j) { if (valid(i) && valid(j) && A[i] < A[j]) { swap(i,j); return true; } else { return false; } }

		// is index i in the valid range?
		inline bool valid(int i) const { return 0 <= i && i <  this->n; } // (STORAGE)
	
	public:
		
		// create empty heap
		Heap() { alloc=0; A = NULL; n=0; }
		
		// create heap from somebody else's array (set the pointer directly to it)
		Heap(element_t *data, int size) { alloc=0; A=data; n=size; }
		
		// (re-)initialize heap with given values
		// all previous values are discarded
		// Warning:  May not be a heap!  Call `build_heap() afterwards'
		template <typename iterator_t>
		void initialize(iterator_t begin, iterator_t end); 
		
		// build heap (i.e., make current data into a heap), O(n)
		void build_heap();
		
		// insert an element, maintaining heap, O(lg n)
		virtual void insert(const element_t&);

		// remove an element, maintaining heap, O(lg n)
		virtual element_t remove(); 

		// check if heap is empty, O(1)
		inline bool is_empty() const { return n==0; }

		// get size, O(1)
		inline int size() const { return n; }

		// get height, O(lg n)
		int height() const { int n,h; for (h=-1,n=this->n; n; n/=2) {h++;} return h; }
	
		// delete the array
		virtual ~Heap() { if (alloc) { delete[] A; } }
		
};

template <typename element_t>
template <typename iterator_t>
void Heap<element_t>::initialize(iterator_t begin, iterator_t end) { 

	// copy each item to my array, starting at position 0
	this->n = 0;

	for (iterator_t it = begin; it!=end; it++) { 
		
		// update n and store in next position
		this->reserve(n+1); // make room for new item (STORAGE)
		this->A[ n++ ] = *it;  // STORAGE

	}

}

template <typename element_t>
void Heap<element_t>::insert(const element_t &addend) {

	this->reserve(n+1); // make room for new item (STORAGE)
	A[ n++ ] = addend;  // add new element to last position (STORAGE)
	reheapify_up( n );	// and reheapify up

}

template <typename element_t>
void Heap<element_t>::reserve(size_t size) { 
	if (this->alloc < size) { 
		size_t new_alloc = size*2; 
		element_t *B = new element_t[new_alloc]; 
		memcpy(B, A, sizeof(element_t)*n); 
		if (alloc) { delete[] A; } 
		alloc = new_alloc; 
		A = B;
	}
}

template <typename element_t>
element_t Heap<element_t>::remove() {
	
	element_t ans = this->A[0]; // store copy of return value for later (STORAGE)
	this->swap( 0, n-1 ); // move last item to root (STORAGE)
	this->n--; // reduce number of items
	reheapify_down(0);	// make this a heap (STORAGE)
	return ans;

}

template <typename element_t>
void Heap<element_t>::build_heap() { 

	for (int i=this->n/2; i>=0; i--) { // for each node, last child to root... (STORAGE)
		reheapify_down(i); // make the subtree @ i a heap, assume all nodes below it are heaps
	}

}

template <typename element_t>
void Heap<element_t>::reheapify_down(int i) { 
	
	// Reheapify down:  Swap with largest child if either child is larger than i.

	bool swapped; // keep track of whether hp(i,j) results in a swap

	do { 
	
		int j = 2 * i + 1; // Let j be the index of the larger value child, assign to left child (STORAGE)
		if (valid(2*i+2) && A[2*i+1] < A[2*i+2]) { j = 2*i+2; } // if right child is valid and larger (MAX_HEAP), assign j to right child (STORAGE)
		
		swapped = this->hp( i, j ); 	// swapped <-  did maintenance of heap property (hp) that node i >= node j result in a swap?

		i = j;	// let i be the index of the larger child
		
	} while (swapped); // continue reheapifying down while we keep swapping values down

}

template <typename element_t>
void Heap<element_t>::reheapify_up(int i) { 
	
	// swap with parent while necessary

	while ( this->hp( (i+1)/2-1 , i ) ) { i = (i+1) / 2 - 1; } // STORAGE
		// while maintaining the heap property (hp) that parent of i >= i, let
		// i be the parent index and keep reheapifying up


}

}//namespace
#endif
