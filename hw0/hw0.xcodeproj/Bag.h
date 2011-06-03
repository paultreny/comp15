//  Paul Reny - COMP 15
//  Bag.h
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

ifndef BAG_H
#define BAG_H 0 // a standard way to make sure #include only includes this file once (see Section 2.3 in the book)

typedef int element_t; // define element_t (the type of item that goes in this Bag) as integer for this assignment

class Bag {
	
private:
  
  // your code
	
public:
  
  Bag(); // Constructor (w/ default vals)
         // put Destructor at end
  
        // if time, Copy Constructor + assignment operator functions
  
  
  // insert (a copy of) an item into the Bag
  void insert(const element_t &item);
  
  // remove an item from the Bag, return a copy (assumes the bag is nonempty)
  element_t remove(); 
	
  // check if the Bag is empty
  bool is_empty() const;
	
};

#endif	// (end the #ifndef above)

class Bag {
public:
  typedef int element_t;
  
  /** Insert an item into the bag */
  void insert(const element_t &item);
  
  /** Remove an item from the bag (assuming it is not empty!) */
  const element_t remove();
  
  /** Check if a bag is empty */
  bool is_empty() const;
private:
  element_t item;
  
  
};