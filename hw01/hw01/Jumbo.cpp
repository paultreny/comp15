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
  

}

Jumbo::Jumbo (const string& valuestr)
{
  for (int i = 0; i != valuestr.size(); i++)
  {
    head->push_back(valuestr[i]-'0');
  }
  cout << head->size();
}

Jumbo::~Jumbo()
{
  head->clear();
  delete head;
}

Jumbo::Jumbo (const Jumbo& source)
{
  this->head = source.head;
}

/*Jumbo::Jumbo Jumbo::add (const Jumbo&) const
{
  
  
  
  
}*/


