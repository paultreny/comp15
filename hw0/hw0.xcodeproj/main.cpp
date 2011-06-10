//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Main.cpp
//  

#include "Bag.h"
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <stdexcept>

using namespace std;
using namespace renyp_ns_zero;

//void print_bag (const Bag& mybag);

int main() { 
  
	Bag bag_1;
  int input;
  cout << "Let's test some bags!\nEnter some numbers, then" << endl;
  cout << "Enter a negative number when done:";
  cin >> input;
  while (input >= 0);
  {
    bag_1.insert(input);
    cin >> input;
  }
  cout << "Numbers inserted into Bag!" << endl;
  cout << bag_1.size() << " items" << endl;
  for (pos_int i = bag_1.size(); i > 0; i--)
    {
      cout << bag_1.remove() << " removed." << endl;
    }
  cout << "Checking if Bag is empty... " << (bag_1.is_empty() ? "True":"False")
  << endl;
  
  cout << "Goodbye!" << endl;
  
  // create a few Bags, insert and remove things, and make sure they have all
	// the properties of a bag.
  
	return EXIT_SUCCESS;
  
}
