// Paul Reny - 11/06/02 - COMP 15
// LAB 1
// FILE: lab1.cpp
// REFERENCES USED: (I'm rusty...)
// 	Data Structures & Other Objects Using C++, by 
//  Main & Savich
// 	 Specifically: Chapters 1,3,5, Appendices A, F, H, L
// cplusplus.com reference pages
//	 Specifically: string, cstdlib, fstream, stdexcept

#include <fstream> // provides fstream
#include <iostream> // provides cout & cin
#include <cstdlib> // provides NULL, EXIT_SUCCESS
#include <string> // provides use of strings
#include <stdexcept> // provides throwing of exceptions
#include "Timer.h"
#include "Node.h"

using namespace std;
// Allows all Standard Library items to be used
using namespace reny_paul_namespc_one; 
// allows Node class to be used (using custom namespace)

int main ()
{
	Timer::Timer *stopwatch = new Timer(); // declares timer
	Node *head=NULL; // declares head pointer, sets to NULL
	string filename_; // declares filename
	cout << "[lab1] Enter filename: ";
	cin >> filename_; // get filename from user
	ifstream file_in_ (filename_.c_str());//validate filename
	if (!file_in_) {
		cerr << "[lab1] Unable to open \'" << filename_ << "\'\n";
		// return error if filename invalid
		exit(EXIT_FAILURE);
	} // announce exit_failure to system
	while (!file_in_.eof())// while not the end of the file
	{
		string line_;
		getline(file_in_, line_); // get next line
		head = new Node(line_, head); //puts word in a new 
		file_in_ >> ws;// node at front of list, updates pointers
	} // remove whitespace at end of line
	file_in_.close(); // close file when finished reading in
	cout << "[lab1] File \'" << filename_ << "\' read successfully.\n";
	string search_word; // declares search string
	Node *cursor=NULL; // declares current node cursor
	bool wasFound; // declares true false
	cout << "[lab1] Enter QQQ to Quit" << endl;
	while (true)
	{	// do as long as user inputs y or Y
		wasFound=false; // reset wasFound to false
		search_word=""; // initialize search_word
		cout << "[lab1] Search word: ";
		cin >> search_word; // get input for search_word
		if (search_word.compare("qqq") == 0 || search_word.compare("QQQ") == 0) {break;}
		for (cursor=head; cursor != NULL; cursor = cursor->get_next())
		{
			if ( search_word.compare(cursor->get_data()) == 0) {// iterate through nodes until end of list 
				wasFound=true; break;// compare node data to search_word, break loop if a match
			}
		}		
		if (wasFound==true) {
			cout << "[lab1] Hooray, \'" << search_word << "\' is in the file! :-) \n";
		} // output if word match
		else {
			cout << "[lab1] BUMMER, \'" << search_word << "\' is NOT in the file.  :-(\n";
		}	// output if word not found
	} // prompt for additional word
	cursor = NULL; 
  delete cursor; // clean-up cursor pointer
	cout << "[lab1] Oh my, " << (*stopwatch).elapsed() << " seconds elapsed.\n"; // output time elapsed
	return EXIT_SUCCESS; // exit & inform system of success
}
