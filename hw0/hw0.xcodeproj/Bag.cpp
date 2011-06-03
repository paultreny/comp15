//  Paul Reny - COMP 15
//  Bag.cpp
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//

#include "Bag.h"



namespace renyp_ns_one
{
    class Bag
    {
    public:
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
        {
            data = new element_t[copyee.current_cap];
            used = copyee.used;
            copy(copyee.data, copee.data + used, data);
            
        }
        ~Bag();
        
        void reserve(size_type new_cap);
        bool remove(const element_t& target); // needs to have no arguments?
        
        size_type erase(const element_t& target);
        void insert(const element_t& item);
        bool is_empty() const;
        void operator +=(const Bag& addend);
        void operator =(const Bag& copyee);
        
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