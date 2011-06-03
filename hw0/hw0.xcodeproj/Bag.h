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

class Bag {
	
public:
    typedef int element_t; // define element_t (the type of item that goes in this Bag) as integer for this assignment
    typedef std::size_t size_type;
    static const size_type DEEF_CAP = 50;
    
    Bag(size_type init_cap = DEEF_CAP);
    Bag(const Bag& fromBag);
    ~Bag();
    
    void reserve(size_type new_cap);
    bool remove(const element_t target);
    size_type erase(const element_t& target);
    void insert(const element_t& entree);
    void operator +=(const Bag& addend);
    void operator =(const Bag& source);
    

    
    Bag(
        const element_t& init_data = element_t(),
        Bag* init_fwd = NULL;
        Bag* init_bck = NULL;
        )
    { bag_data = init_data; fwd_ptr = init_fwd; bck_ptr = init_bck;}       // put Destructor at end
    
    
    // if time, Copy Constructor + assignment operator functions
    
    Bag(const Bag& copyee);
    
    
    
    ~Bag();
    
    // insert (a copy of) an item into the Bag
    void insert(const element_t &item);
    
    // remove an item from the Bag, return a copy (assumes the bag is nonempty)
    element_t remove(); 
	
    // check if the Bag is empty
    bool is_empty() const;
    
private:
    Bag* fwd_ptr;
    Bag* bck_ptr;
    element_t bag_data;
    element_t item;
    
};

#endif	// (end the #ifndef above)
