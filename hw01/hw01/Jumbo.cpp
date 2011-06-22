//
//  Jumbo.cpp
//  hw01
//
//  Created by Paul Reny on 6/21/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "Jumbo.h"

Jumbo::Jumbo()
{
  head = new list<int> ();

}

Jumbo::Jumbo (unsigned int value)
{
  head = new list<int> ();
  if (value == 0) head->push_front(0);
  else
  while (value != 0)
  {
    head->push_front(value%10);
    value /= 10;
  }
}


Jumbo::Jumbo (const string& valuestr)
{
  head = new list<int> ();
  for (int i = 0; i != valuestr.size(); i++)
  {
    head->push_back(valuestr[i]-'0');
  }
}

Jumbo::~Jumbo()
{
  head->clear();
  delete head;
}

Jumbo::Jumbo (const Jumbo& source)
{
  head = new list<int> ();
  head = source.head;
}

string Jumbo::str() const
{
  string temp = "";
  if (head == NULL) return "NULL"; 
  for (list<int>::iterator it = head->begin(); it != head->end(); it++)
  {
    temp+=(char(*it+48));   
  }
  return temp;
}


/*Jumbo::Jumbo Jumbo::add (const Jumbo&) const
{
  
  
  
  
}*/
Jumbo& Jumbo::operator= (const Jumbo& source)
{
  if (source.head == this->head) return *this;
  head->clear();
  head = source.head;
  return *this;
}// make sure to check if assigning obj to itself



ostream& operator<< (ostream& out, const Jumbo &n)
{
  list<int>::iterator it;
  for (it = n.head->begin(); it != n.head->end(); it++)
  {
    cout << *it;
  }
  return out;
};
