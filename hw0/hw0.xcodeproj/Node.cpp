//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Node.cpp
//  

#include "Node.h"

namespace renyp_ns_zero // custom namespace
{
  void node_insert (Node*& head_ptr, const element_t& item) // adds a node
  {
    head_ptr = new Node(item, head_ptr);
  }
  
  element_t node_remove (Node*& head_ptr) // removes head node, points to next
                                          // and returns the item from node
  {
    Node *temp;
    element_t grabbed = head_ptr->get_data();
    temp = head_ptr;
    head_ptr = head_ptr->get_next();
    delete temp;
    return grabbed;
  }
  
  void clear (Node*& head_ptr) // removes all nodes, used for destructor
  {
    while (head_ptr != NULL)
      node_remove(head_ptr);  
  }
  
}
