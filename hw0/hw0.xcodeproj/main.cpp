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
  element_t input = 0;
  cout << "[hw0] Let's test some bags!" << endl;
  cout << "[hw0] Prevented crash from removing from empty bag? ";
  cout << boolalpha;
  cout << !bag_1.remove() << endl;
  cout << "[hw0] Enter numbers (separated by spaces)" << endl;
  cout << "[hw0] Enter a negative number and press Enter when done:";
  while (true)
  {
    cin >> input;
    if (input < 0) break;
    bag_1.insert(input);
  }
  cout << "[hw0] Numbers inserted into Bag!" << endl;
  cout << "[hw0] " << bag_1.size() << " items" << endl;
  
  for (pos_int i = bag_1.size(); i > 0; i--)
    {
      cout << "[hw0] "<< bag_1.remove() << " removed." << endl;
    }
  cout << "[hw0] Checking if Bag is empty... " << bag_1.is_empty() << endl;
  
  cout << "[hw0] Goodbye!" << endl;
  
  // create a few Bags, insert and remove things, and make sure they have all
	// the properties of a bag.
  
	return EXIT_SUCCESS;
  
}
