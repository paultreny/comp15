//
//  Node.cpp
//  hw0
//
//  Created by Paul Reny on 6/9/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//

#include "Node.h"
#include <cassert>
#include <cstdlib>

using namespace std;

namespace renyp_ns_zero
{
  // returns length of the Node
  pos_int length (const Node* head_ptr)
  {
    const Node* cursor;
    pos_int answer;
    
    answer = 0;
    for (cursor = head_ptr; cursor != NULL; cursor = cursor->get_next( ))
      ++answer;
    return answer;
  }
  
  // adds a new Node at the head_ptr
  void head_insert (Node*& head_ptr, const element_t& item)
  {
    head_ptr = new Node(item, head_ptr);
  }
  
  // adds a new Node in front of the prev_ptr
  void insert (Node* prev_ptr, const element_t& item)
  {
    Node *insert_ptr;
    
    insert_ptr = new Node(item, prev_ptr->get_next());
    prev_ptr->set_next(insert_ptr);
  }
  
  // removes a Node at the head_ptr
  void head_remove (Node*& head_ptr)
  {
    Node *remove_ptr;
    
    remove_ptr = head_ptr;
    head_ptr = head_ptr->get_next();
    delete remove_ptr;
  }
  
  // removes a Node in front of the prev_ptr
  void remove (Node* prev_ptr)
  {
    Node *remove_ptr;
    
    remove_ptr = prev_ptr->get_next();
    prev_ptr->set_next(remove_ptr->get_next());
    delete remove_ptr;
  }

  // removes all nodes
  void clear (Node*& head_ptr)
  {
    while (head_ptr != NULL)
      head_remove(head_ptr);  
  }
}