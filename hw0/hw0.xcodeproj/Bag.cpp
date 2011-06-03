//  Paul Reny - COMP 15
//  Bag.cpp
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//

#include "Bag.h"
#include <algorithm>
#include <cassert>

using namespace std;

namespace renyp_ns_one
{
    const Bag::size_type Bag::DEFAULT_CAP;
    typedef int element_t; // define element_t (the type of item that goes in this Bag) as integer for this assignment
    typedef std::size_t size_type;
    static const size_type DEFAULT__CAP = 50;
    
    Bag::Bag(size_type init_cap)
    {
        data = new element_t[init_cap];
        current_cap = init_cap;
        used = 0;
    }
    
    Bag::Bag(const Bag& copyee)
    //library facilities used: algorithm
    {
        data = new element_t[copyee.current_cap];
        used = copyee.used;
        copy(copyee.data, copee.data + used, data);
    }
    
    Bag::~Bag()
    {
        delete[] data;            
    }
    
    void Bag::reserve(size_type new_cap)
    {
        element_t *new_array;
        if (new_cap == current_cap) {
            return;
        }
        if (new_cap < used) {
            new_cap = used;
        }
        new_array = new element_t[new_cap];
        copy(data, data + used; new_array);
        delete[] data;
        data = new_array;
        current_cap = new_cap;
        
    }
    bool Bag::remove(const element_t& target) //erase_one / needs to have no arguments?
    {
        
        
    }
    
    Bag::size_type Bag::erase(const element_t& target);
    void insert(const element_t& item);
    bool is_empty() const;
    void operator +=(const Bag& addend);
    
    Bag::void operator =(const Bag& copyee)
    {
        element_t *new_data;
        
        if (this == &copyee)
            return;
        if (current_cap != copyee.current_cap)
        {
            new_data = new element_t[copyee.current_cap];
            delete[] data;
            data = new_data;
            current_cap = copyee.current_cap;
        }
        used = copyee.used;
        copy(copyee.data, copyee.data + used, data);
    }
    
    size_type size() const {return used;}
    size_type count(const element_t& target) const;
    
private:
    element_t *data;
    size_type used;
    size_type current_cap;
    
}
// NONMEMBER FUNCTIONs for the bag class
Bag operator +(const Bag& b1, const Bag& b2);
}

  
  void insert(const element_t &item)
  {
    
    
    
  }
  
  element_t remove(); 
	
  bool is_empty() const;
  
}