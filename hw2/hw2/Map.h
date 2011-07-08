//  Paul Reny - COMP 15 - 07/07/11
//  HW2
//  Map.h
//
//  Copyright 2011 Keith Noto. All rights reserved.
//
/*
 
 Maintains a set of <key, value> pairs
 
 comp15::Map provides an abstract parent type so various mapping strategies may
 implement the same interface.
 
 */


#ifndef COMP15_MAP_H
#define COMP15_MAP_H

namespace comp15 { // so that types and functions defined here are put in our special namespace
  
  template <typename key_t, typename data_t>
  class Map {
    
  public:
    
    // insert item w/key, return true if inserted (some subclasses may insert
    // duplicates and always return true)
    virtual bool insert(const key_t &key, const data_t &data) = 0;
    
    // remove item w/key, return true iff found
    virtual bool remove(const key_t &key) = 0;
    
    // return pointer-to-data_t if found else NULL
    virtual data_t* lookup(const key_t &key) = 0;
    
    virtual ~Map() { } 
    
  };
  
} // namespace
#endif

