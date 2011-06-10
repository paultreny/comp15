//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Node.cpp
//  

#include "Node.h"

namespace renyp_ns_zero
{
  element_t grab(Node*& head_ptr)
  {
    element_t grabbed = head_ptr->get_data();
    node_remove(head_ptr);
    return grabbed;
  }
  
  void node_insert (Node*& pointer, const element_t& item)
  {
    pointer = new Node(item, pointer);
  }
  
  element_t node_remove (Node*& head_ptr)
  {
    Node *temp;
    element_t grabbed = head_ptr->get_data();
    temp = head_ptr;
    head_ptr = head_ptr->get_next();
    delete temp;
    return grabbed;
  }
  
  void clear (Node*& head_ptr)
  {
    while (head_ptr != NULL)
      node_remove(head_ptr);  
  }
  
}