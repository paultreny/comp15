//
//  Node.cpp
//  hw0
//
//  Created by Paul Reny on 6/9/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//

#include "Node.h"

namespace renyp_ns_zero
{
  void insert (Node*& pointer, const element_t& item)
  {
    pointer = new Node(item, pointer);
  }
  void remove (Node*& head_ptr)
  {
    Node *temp;
    temp = head_ptr;
    head_ptr = head_ptr->get_next();
    delete temp;
  }
  
  void clear (Node*& head_ptr)
  {
    while (head_ptr != NULL)
      remove(head_ptr);  
  }
}