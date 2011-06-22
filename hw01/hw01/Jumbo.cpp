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
  if (value == 0)
  {
    head->push_back(0);
    return;
  }
  else
  while (value != 0)
  {
    head->push_back(value%10);
    value /= 10;
  }
  head->reverse();
}


Jumbo::Jumbo (const string& valuestr)
{
  head = new list<int> ();
  for (int i = 0; i != valuestr.size(); i++)
  {
    head->push_back((valuestr[i])-'0');
  }
}

Jumbo::~Jumbo()
{
  head->clear();
  delete head;
}

Jumbo::Jumbo (const Jumbo& source)
{
  this->head = new list<int> ();
  this->head = source.head;
  /*for (list<int>::iterator it = source.head->begin(); it != source.head->end(); it++)
  {
    head->push_back(*it);
  }*/
}

string Jumbo::str() const
{
  string temp;
  list<int>::const_iterator iter;
  for (iter = head->begin(); iter != head->end(); ++iter)
  {
    int tempnum = *iter;
    tempnum+=48;
    temp+=(char(tempnum));
    //cout << temp << " " << endl;
  }
  
  return temp;
}


Jumbo Jumbo::add (const Jumbo& source) const
{
  if (source.head == NULL && this->head == NULL) return Jumbo();
  if (source.head == NULL) return *this;
  if (this->head == NULL) return source;
  if (&source == this) return *this; //double the number
  if (source.head->size() > head->size())
    for (list<int>::iterator it = head->begin(); it != head->end(); ++it)
      {
        
        
      }  

  return source;
}
Jumbo& Jumbo::operator= (const Jumbo& source)
{
  if (source.head == this->head) return *this;
  this->head->clear();
  this->head = source.head;
  return *this;
}// make sure to check if assigning obj to itself



ostream& operator<< (ostream& out, const Jumbo &n)
{
  list<int>::iterator it;
  for (it = n.head->begin(); it != n.head->end(); ++it)
  {
    cout << *it;
  }
  return out;
};
