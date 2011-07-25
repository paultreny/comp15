//  Paul Reny - COMP 15 - 07/24/11
//  HW3
//  ptrie.h
//
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//

#ifndef PTRIE_H
#define PTRIE_H

#include <string>

using namespace std;

template <typename VALUE, int RANGE, typename KEYTYPE>
struct ptrie
{
  typedef VALUE value_t;
  enum
  {
    range_mask = RANGE-1,
    range = RANGE
  };
  typedef KEYTYPE key_t;
  typedef ptrie<VALUE,RANGE,KEYTYPE> type_t;
  
  value_t result;
  type_t * parent;
  type_t * table[RANGE];
  
  
  
  
  
  
  
  
  
  
  
  
  
  
private:
  void next();
  
  
  
};

#endif

