//
//  Jumbo.cpp
//  hw01
//
//  Created by Paul Reny on 6/21/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "Jumbo.h"

ostream& operator<< (ostream& out, const Jumbo &n)
{
  list<unsigned int>::const_iterator it;
  if (n.head->empty()) {
    cout << "NULL" << endl;
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
  if (source.head == NULL && this->head == NULL) return Jumbo();
  if (source.head == NULL) return *this;
  if (this->head == NULL) return source;
  if (&source == this) return *this; //double the number
  if (source.head->size() > head->size()) {
    for (list<unsigned int>::const_iterator it = head->begin(); it != head->end(); ++it)
      {
        
      }  
  }
  return source;
}

Jumbo& Jumbo::operator= (const Jumbo& source) { //check if assigning self
  if (*this->head == *source.head) return *this;
  head->clear();
  *head = *source.head;
  return *this;
}


