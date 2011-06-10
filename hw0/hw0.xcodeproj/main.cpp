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
  element_t input = element_t();
  cout << "[hw0] Let's test my Bag!" << endl;
  cout << "[hw0] (T|F) Prevented crash from removing from empty bag? "; 
  cout << boolalpha; // sets cout to display true/false instead of 1/0
  cout << !bag_1.remove() << endl; // Bag.remove() returns 0 if empty
  cout << "[hw0] Enter numbers (separated by spaces), then enter" << endl;
  cout << "[hw0] a negative number and press Enter when done:";
  while (true) // loop in as many numbers as user likes
  {
    cin >> input;
    if (input < 0) break;
    bag_1.insert(input); // test of Bag.insert(input)
  }
  cout << "[hw0] " << bag_1.size() << " items inserted into Bag!" << endl;
  cout << "[hw0] Checking if Bag is empty... " << bag_1.is_empty() << endl;
  cout << "[hw0] ";
  for (pos_int i = bag_1.size(); i > 0; i--) // removing items until empty
    {
      cout << bag_1.remove() << " ";
    }
  cout << "removed." << endl;
  cout << "[hw0] Checking if Bag is empty... " << bag_1.is_empty() << endl;
  
  cout << "[hw0] Goodbye!" << endl;
  
  // create a few Bags, insert and remove things, and make sure they have all
	// the properties of a bag.
  
	return EXIT_SUCCESS;
  
}
