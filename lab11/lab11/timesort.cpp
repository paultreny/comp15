/* 
	
	Uses the definitions of `integer_t' and `sort' in "sort.h"/"sort.cpp" to
	time how long sorting takes (for several large arrays)

*/

#include <cstdio>
#include <ctime> 

#include <iostream> 
using namespace std;

#include "sort.h"
using namespace comp15;

// Verify that an array of n integers, summing to sum is sorted
bool sorted(integer_t *A, size_t n, const integer_t sum); 

// A test consists of a problem size n and number of repitiions over which to average.
struct Test { 
	size_t n; 
	int reps;
};

int main() { 

	srand(9141979);
	clock_t total = 0; // total sort time

	// stop when reps == 0
	Test TESTS[] = { 
		{        0,  1}, 
		{        1,  1}, 
		{    10000, 64}, 
		{    50000, 32}, 
		{   100000, 16}, 
		{   500000,  8}, 
		{  1000000,  4}, 
		{  5000000,  2}, 
		{ 10000000,  1}, 
		{ 20000000,  1}, 
		{ 30000000,  1}, 
		{0,0} }; 

	for (int test=0; TESTS[test].reps; test++) { 

		const size_t n = TESTS[test].n;
		integer_t *A = new integer_t[ n ]; 
		clock_t time = 0;

		for (int trial=1; trial <= TESTS[test].reps; trial++) { 

			// populate array with random integer values
			integer_t checksum = 0;
			for (size_t i=0; i<n; i++) { checksum += A[i] = (integer_t)(rand()); }
			
			// okay, now sort it:
			clock_t t0 = clock();
			sort(A, n);
			clock_t t1 = clock();
			time += (t1-t0);

			// verify that it is sorted
			if (!sorted(A, n, checksum)) { 
				cerr << "FAIL" << endl; // cerr prints to "standard error"
				exit(-1); // end program
			}
		}

		// finally, free the memory
		delete[] A; 
			
		// print the answer (average sort time)
		printf("%10lu \t %10.3f\n", n, (double)(time) / (CLOCKS_PER_SEC * TESTS[test].reps));

		total += time;

	}
	printf("Test passed in %.3f seconds\n", (double)total / CLOCKS_PER_SEC); 

	return 0; 
}

bool sorted(integer_t *A, size_t n, const integer_t sum) { 
	integer_t check = n ? A[0] : 0;
	for (size_t i=1; i<n; i++) { 
		if (A[i-1] > A[i]) { return false; }
		check += A[i];
	}
	return sum==check;
} 

