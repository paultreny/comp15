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
  
  void node_insert (Node*& head_ptr, const element_t& item)
  {
    head_ptr = new Node(item, head_ptr);
  }
  
  element_t node_remove (Node*& head_ptr)
  {
    if (head_ptr == NULL) {return -1;}
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
