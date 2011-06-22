// PAUL RENY - COMP 15 - 06/21/2011
// HW1
// Jumbo.cpp
//

#include "Jumbo.h" // include Jumbo, of course!

ostream& operator<< (ostream& out, const Jumbo &n) // OVERLOADED << OPERATOR
{
  list<unsigned int>::const_iterator it;
  if (n.head->empty()) { // if Jumbo doesn't contain anything, output "Empty"
    cout << "Empty" << endl;
    return out;
  }
  // Output each digit of the Jumbo
  for (it = n.head->begin(); it != n.head->end(); ++it) 
  {
    cout << *it;
  }
  return out;
};

Jumbo::Jumbo() { // DEFAULT CONSTRUCTOR
  head = new list<unsigned int> ();
}

Jumbo::Jumbo (unsigned int value) { // INTEGER CONSTRUCTOR
  head = new list<unsigned int> ();
  if (value == 0) { // if the int is simply 0, add 0 and return;
    head->push_back(0);
    return;
  }
  else { // add value%10, set value = value/10, until value is 0, digit by digit
    while (value != 0) {
      head->push_front(value%10); // add digits to front, as you start with ones place, and finish with left-most
      value /= 10;
    }
  }
}

Jumbo::Jumbo (const string& valuestr) { // STRING CONSTRUCTOR
  head = new list<unsigned int> ();
  // For each digit in string, add to back, as you read them left->right 
  for (unsigned int i = 0; i != valuestr.size(); i++) {
    head->push_back((unsigned int)(valuestr[i])-'0'); // subtrace 48 to convert char value to int
  }
}

Jumbo::Jumbo (const Jumbo& source) { // COPY CONSTRUCTOR
  head = new list<unsigned int> ();
  *head = *source.head; // uses list assignment operator= to create new list with same # and values of elements in the same order
}

Jumbo::~Jumbo() { // DESTRUCTOR
  head->clear();
  delete head;
}

string Jumbo::str() const { // STRING MEMBER FUNCTION
  string temp;
  list<unsigned int>::const_iterator iter;
  // Iterate through list and add each digit to a temp string, (add 48 to each value to convert from int to correct char value
  for (iter = head->begin(); iter != head->end(); ++iter) {
    unsigned int tempnum = *iter;
    tempnum+=48;
    temp+=(char(tempnum));
    //cout << temp << " " << endl;
  }
  return temp;
}

Jumbo Jumbo::add (const Jumbo& source) const { // ADD MEMBER FUNCTION
  list <unsigned int> * new_head = new list<unsigned int> ();
  unsigned int carryover = 0; // Carry the 1's Place temp variable
  if (source.head == NULL && this->head == NULL) return Jumbo(); // if both empty, return empty Jumbo
  if (source.head == NULL) return *this; // if source is empty, just return *this
  if (this->head == NULL) return source; // if *this is empty, just return source
  if (&source == this) // if this is adding to itself
  {
    for (list<unsigned int>::const_reverse_iterator itt = head->rbegin(); itt != head->rend(); ++itt)
    {
      // iterate through, double each digit and carry the 1 if necessary
      unsigned int temp = (*itt + *itt + carryover);
      new_head->push_front(temp%10);
      carryover = temp/10;
    }
  }
  else if (source.head->size() >= head->size()) // if source is bigger than this, or same size
  {
    list<unsigned int>::const_reverse_iterator tir = source.head->rbegin();
    for (list<unsigned int>::const_reverse_iterator rit = head->rbegin(); rit != head->rend(); ++rit)
    {
      unsigned int temp = (*rit + *tir + carryover);
      new_head->push_front(temp%10);
      carryover = temp/10;
      ++tir;
    }
    while (tir != source.head->rend()) // carry the 1 through the rest of the source list, if it is longer
    {
      unsigned int temptwo = (*tir+carryover);
      new_head->push_front(temptwo%10);
      carryover = temptwo/10;
      ++tir;
    }
  }
  else if (head->size() > source.head->size()) // if this is bigger than source
  {
    list<unsigned int>::const_reverse_iterator rit = head->rbegin();
    for (list<unsigned int>::const_reverse_iterator tir = source.head->rbegin(); tir != source.head->rend(); ++tir)
    {
      // iterate through, adding both digits, carrying the 1 if need be
      unsigned int temp = (*rit + *tir + carryover);
      new_head->push_front(temp%10);
      carryover = temp/10;
      ++rit;
    }
    while (rit != head->rend()) // carry the 1 through the rest of the head list if it is longer
    {
      unsigned int temptwo = (*rit+carryover);
      new_head->push_front(temptwo%10);
      carryover = temptwo/10;
      ++rit;
    }    
  }
  if (carryover == 1) new_head->push_front(1); // if one is still being carried, add it to the front of the list
  Jumbo RoboJumbo;
  RoboJumbo.head = new_head; // assigned new list to a new Jumbo, return it
  return RoboJumbo;
}

Jumbo& Jumbo::operator= (const Jumbo& source) { //check if assigning self
  if (*this->head == *source.head) return *this;
  head->clear();
  *head = *source.head; // uses list assignment operator= to create new list with same # and values of elements in the same order
  return *this;
}
