// PAUL RENY - COMP 15 - 06/21/2011
// HW1
// Jumbo.h
//

#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

class Jumbo
{
public:
  Jumbo();
  
  Jumbo(const Jumbo&);
  
  ~Jumbo();

  Jumbo (unsigned int value);
  
  Jumbo (const string& valuestr);
  
  
  string str() const;
  
  
  
  Jumbo& operator= (const Jumbo&); // make sure to check if assigning obj to itself
  
  Jumbo add (const Jumbo& added) const;
  
  /* OPTIONAL   
   Jumbo operator+(const Jumbo &addend) const;
   Jumbo operator+(unsigned int value) const;
   Jumbo& operator+=(const Jumbo &addend); 
   Jumbo& operator+=(unsigned int value);   
  */
  
  /* ALSO OPTIONAL 
   bool operator==(const Jumbo&) const;
   bool operator<(const Jumbo&) const;
   bool operator<=(const Jumbo &RHS) const;
   bool operator>=(const Jumbo &RHS) const;
   bool operator>(const Jumbo &RHS) const;
   bool operator!=(const Jumbo &RHS) const;
   
   Hint: The best way to do this is to write one function that takes two Jumbos (or their private internal representations) and returns:
   
   zero if they are equal
   a negative number if the first Jumbo is less than the other, or
   a positive number if the first Jumbo is greater than the other. 
   
   */
  friend Jumbo operator+ (const Jumbo&, const Jumbo&);
  //  friend istream& operator>> (istream &in, Jumbo &n);
  //  friend ostream& operator<< (ostream &out, const Jumbo &n);

private:
  list<size_t> * head;
  

 

};