//  Paul Reny - COMP 15
//  Bag.cpp
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//

#include <algorithm>
#include <cassert>
#include <cstdlib>
#include "Node.h"
#include "Bag.h"

using namespace std;

namespace renyp_ns_zero
{
  Bag::Bag()
  {
    head = NULL;
    total_nodes = 0;
  }
    
  Bag::Bag(const Bag& source)
  //library facilities total_nodes: algorithm
  {
    Node* tail_ptr;  // Needed for argument of list_copy
    list_copy(source.head, head, tail_ptr);
    total_nodes = source.total_nodes;
  }
  
  Bag::~Bag()
  {
    list_clear(head);
    total_nodes = 0;           
  }
  
  bool Bag::remove() //erase_one / needs to have no arguments?
  {
    head_remove(head);
    --total_nodes;
  }
  
  void Bag::insert(const element_t& item)
  {
    head_insert(head, item);
    ++total_nodes;   
  }

  bool Bag::is_empty() const
  {
    return !bool(total_nodes);        
  }
  
  void Bag::operator =(const Bag& source)
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
    total_nodes = copyee.total_nodes;
    copy(copyee.data, copyee.data + total_nodes, data);
  }
}

