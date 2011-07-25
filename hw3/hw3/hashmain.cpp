#include <iostream>
#include <fstream>
using namespace std;

#include "hash.h" // define a hash function

int hashmain(int argc, char **argv) { 

	const unsigned int TBLSZ = 2000003; // choose a prime just in case
		// other fine choices:  1000003 2584853 3072263 8004823

	const char DEFAULT_FILENAME[] = "/usr/share/dict/words"; 
	const char *FILENAME = argc > 1  ? argv[1] : DEFAULT_FILENAME;

	unsigned int collisions = 0;	// count number of collisions	
	unsigned int keys = 0;			// 	and keys inserted into table

	unsigned int *table = new unsigned int[TBLSZ]; 
	for (unsigned int i=0; i<TBLSZ; i++) { table[i] = 0; }

	for (ifstream fin(FILENAME); !fin.eof(); fin>>ws) {

		if (!fin) { cerr << "Error:  Failed to read from input file \"" << FILENAME << "\"" << endl; exit(-1); }

		string w;
		fin >> w;

		unsigned long hv = hash(w); 

		if (hv != hash(w)) { cerr << "The hash function is BROKEN." << endl; exit(-1); }

		if (table[hv % TBLSZ]) { collisions++; }
		
		table[hv % TBLSZ]++;
		keys++;

	}

	cout << collisions << " collisions / " << keys << " keys = " << (100.0 * collisions / keys) << "%" << endl;

	return 0;

}
