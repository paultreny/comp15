//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Node.cpp
//  

#include "Node.h"

namespace renyp_ns_zero
{
  void node_insert (Node*& pointer, const element_t& item)
  {
    pointer = new Node(item, pointer);
  }
  
  void node_remove (Node*& head_ptr)
  {
    Node *temp;
    temp = head_ptr;
    head_ptr = head_ptr->get_next();
    delete temp;
  }
  
  void clear (Node*& head_ptr)
  {
    while (head_ptr != NULL)
      node_remove(head_ptr);  
  }
}