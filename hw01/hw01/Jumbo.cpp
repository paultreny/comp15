//
//  Jumbo.cpp
//  hw01
//
//  Created by Paul Reny on 6/21/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "Jumbo.h"
#include <iterator>
#include <list>

ostream& operator<< (ostream& out, const Jumbo &n)
{
  list<unsigned int>::const_iterator it;
  if (n.head->empty()) {
    cout << "Empty" << endl;
    return out;
  }
  for (it = n.head->begin(); it != n.head->end(); ++it)
  {
    cout << *it;
  }
  return out;
};

Jumbo::Jumbo() {
  head = new list<unsigned int> ();
}

Jumbo::Jumbo (unsigned int value) {
  head = new list<unsigned int> ();
  if (value == 0) {
    head->push_back(0);
    return;
  }
  else {
    while (value != 0) {
      head->push_front(value%10);
      value /= 10;
    }
    //head->reverse();
  }
}

Jumbo::Jumbo (const string& valuestr) {
  head = new list<unsigned int> ();
  for (int i = 0; i != valuestr.size(); i++) {
    head->push_back((valuestr[i])-'0');
  }
}

Jumbo::Jumbo (const Jumbo& source) {
  head = new list<unsigned int> ();
  *head = *source.head;
  /*for (list<int>::iterator it = source.head->begin(); it != source.head->end(); it++)
  {
    head->push_back(*it);
  }*/
}

Jumbo::~Jumbo() {
  head->clear();
  delete head;
}

string Jumbo::str() const {
  string temp;
  list<unsigned int>::const_iterator iter;
  for (iter = head->begin(); iter != head->end(); ++iter) {
    unsigned int tempnum = *iter;
    tempnum+=48;
    temp+=(char(tempnum));
    //cout << temp << " " << endl;
  }
  return temp;
}

Jumbo Jumbo::add (const Jumbo& source) const {
  list <unsigned int> * new_head = new list<unsigned int> ();
  if (source.head == NULL && this->head == NULL) return Jumbo();
  if (source.head == NULL) return *this;
  if (this->head == NULL) return source;
  if (&source == this) return *this; //double the number TBI
  unsigned int carryover = 0;
  if (source.head->size() > head->size())
  {
    list<unsigned int>::const_reverse_iterator tir = source.head->rbegin();
    for (list<unsigned int>::const_reverse_iterator rit = head->rbegin(); rit != head->rend(); ++rit)
    {
      unsigned int temp = (*rit + *tir + carryover);
      new_head->push_front(temp%10);
      carryover = temp/10;
      ++tir;
    }
    while (tir != source.head->rend())
    {
      unsigned int temptwo = (*tir+carryover);
      new_head->push_front(temptwo%10);
      carryover = temptwo/10;
      ++tir;
    }
  }
  else if (head->size() > source.head->size())
  {
    list<unsigned int>::const_reverse_iterator rit = head->rbegin();
    for (list<unsigned int>::const_reverse_iterator tir = source.head->rbegin(); tir != source.head->rend(); ++tir)
    {
      unsigned int temp = (*rit + *tir + carryover);
      new_head->push_front(temp%10);
      carryover = temp/10;
      ++rit;
    }
    while (rit != head->rend())
    {
      unsigned int temptwo = (*rit+carryover);
      new_head->push_front(temptwo%10);
      carryover = temptwo/10;
      ++rit;
    }    
  }
  if (carryover == 1) new_head->push_front(1);
  Jumbo RoboJumbo;
  RoboJumbo.head = new_head;
  return RoboJumbo;
}

Jumbo& Jumbo::operator= (const Jumbo& source) { //check if assigning self
  if (*this->head == *source.head) return *this;
  head->clear();
  *head = *source.head;
  return *this;
}


