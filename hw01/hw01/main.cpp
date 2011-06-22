// PAUL RENY - COMP 15 - 06/21/2011
// HW1
// main.cpp
//


#include <iostream>
#include <cstdlib>
#include <list>
#include "Jumbo.h"


using namespace std;


int main() { 
  
	Jumbo total(11223344);	// (test integer constructor)
	cout << total << endl;
	int count = 0;
  while (true) { 
    
		string instr;  // user input 
    
		++count;
    cout << count << endl;
    cout << "Running sum is: " << total.str() << endl << endl; // (test str() function)
    
		cout << "Add:  "; 	
		cin >> instr;
		cout << count << endl;
		Jumbo a = total; // create a from running total (test copy constructor)
		Jumbo b(instr); // create b from input (test string constructor)
    cout << count << endl;
    cout << "Jumbo A: " << a << endl;
    //Jumbo c = a.add(b);
    // create c from adding a and b (test add function)
    cout << "Jumbo B: " << b << endl;
    
    
		//total = b; // assign to total (test assignment operator)
		cout << "Jumbo total: " << total << endl;
	}
  
	return 0;  
}
