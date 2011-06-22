// PAUL RENY - COMP 15 - 06/21/2011
// HW1
// Jumbo.h
//

#ifndef HW1_JUMBO_PAULRENY
#define HW1_JUMBO_PAULRENY

#include <iostream> // for cout and cin, and string
#include <cstdlib> // for stl
#include <list> // for list

using namespace std;

class Jumbo
{
  friend ostream& operator<< (ostream &out, const Jumbo &n);
  // OVERLOADED << OPERATOR
  
public:
  Jumbo(); // DEFAULT CONSTRUCTOR
  Jumbo (unsigned int value); // INT CONSTRUCTOR
  Jumbo (const string& valuestr); // STRING CONSTRUCTOR
  
  Jumbo (const Jumbo& source); // COPY CONSTRUCTOR
  ~Jumbo(); // DESTRUCTOR
  
  string str() const; // Returns string representation of Jumbo
  Jumbo add (const Jumbo& source) const; // Adds one Jumbo to another
  
  Jumbo& operator= (const Jumbo& source); // assigns value of one Jumbo to another
  
private:
  list<unsigned int>* head; // Jumbo's data structure, internal list of digits
  
  /* OPTIONAL   
   friend Jumbo operator+ (const Jumbo&, const Jumbo&);
   
   Jumbo operator+(const Jumbo &addend) const;
   Jumbo operator+(unsigned int value) const;
   Jumbo& operator+=(const Jumbo &addend); 
   Jumbo& operator+=(unsigned int value);   
   
   bool operator==(const Jumbo&) const;
   bool operator<(const Jumbo&) const;
   bool operator<=(const Jumbo &RHS) const;
   bool operator>=(const Jumbo &RHS) const;
   bool operator>(const Jumbo &RHS) const;
   bool operator!=(const Jumbo &RHS) const;
   
   friend istream& operator>> (istream &in, Jumbo &n);
   */
};
#endif
