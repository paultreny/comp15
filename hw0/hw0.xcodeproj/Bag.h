//  Paul Reny - COMP 15
//  Bag.h
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef RENYP_NS_ONE
#define RENYP_NS_ONE // a standard way to make sure #include only includes this file once (see Section 2.3 in the book)

#include <cstdlib>

namespace renyp_ns_one
{
    class Bag
    {
    public:
        typedef int element_t; // define element_t (the type of item that goes in this Bag) as integer for this assignment
        typedef std::size_t size_type;
        static const size_type DEFAULT__CAP = 50;
        
        Bag(size_type init_cap = DEFAULT_CAP);
        Bag(const Bag& copyee);
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
    
/*
    ~Bag();
    
    // insert (a copy of) an item into the Bag
    void insert(const element_t &item);
    
    // remove an item from the Bag, return a copy (assumes the bag is nonempty)
    element_t remove(); 
	
    // check if the Bag is empty
    bool is_empty() const;
*/    

#endif	// (end the #ifndef above)
