//  Paul Reny - COMP 15
//  Bag.h
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef RENYP_NS_ONE
#define RENYP_NS_ONE

#include <cstdlib>
#include "Node.h"

using namespace std;

namespace renyp_ns_one
{
  typedef Node::element_t
  typedef Node::pos_int pos_int;
  
  class Bag
  {
  public:
    Bag() { head = NULL; total_nodes = 0; }
    ~Bag() { clear(head); total_nodes = 0; }
    
    void insert(const element_t& item){head_insert(head, item); ++total_nodes;
      
    element_t remove() { remove(head); --total_nodes; }
    bool is_empty() const { return !bool(total_nodes); }
  
    void operator =(const Bag& source);
    pos_int size() const {return total_nodes; }
  private:
    Node* head;
    element_t data;
    pos_int total_nodes;
  }
}
#endif
