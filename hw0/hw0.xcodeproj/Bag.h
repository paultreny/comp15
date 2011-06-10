//  Paul Reny - COMP 15
//  Bag.h
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef RENYP_NS_ONE
#define RENYP_NS_ONE // a standard way to make sure #include only includes this file once (see Section 2.3 in the book)

#include "Node.h"

namespace renyp_ns_one
{
  typedef Node::element_t //define element_t as an integer for this assignment
  typedef Node::pos_int pos_int;
  
  class Bag
  {
  public:
    Bag();
    Bag(const Bag& source);
    ~Bag();
    
    void insert(const element_t& item);
    element_t remove();
    bool is_empty() const;

    void operator =(const Bag& source);
    pos_int size() const {return total_nodes; }
  
  private:
    Node* head;
    element_t data;
    pos_int total_nodes;
  }
}
#endif
