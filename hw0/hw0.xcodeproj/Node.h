//
//  Node.h
//  hw0
//
//  Created by Paul Reny on 6/9/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//
#ifndef RENYP_NS_ZERO
#define RENYP_NS_ZERO

#include <cstdlib>
#include <string>

using namespace std;

namespace renyp_ns_zero
{
  typedef string element_t;
  typedef std::size_t pos_int;
  
  class Node
  {
    
    
  public:
    Node (const element_t& init_data = element_t(), Node* init_next = NULL) {node_data = init_data; node_next = init_next; }
    
    void set_data (const element_t& new_data) {node_data = new_data; }
    void set_next (Node* new_next) { node_next = new_next; }
    
    element_t get_data () const { return node_data; }
    
    const Node* get_next () const {return node_next; }
    Node* get_next() {return node_next; }
    
  private:
    element_t node_data;
    Node* node_next;
};
  
  pos_int length (const Node* head_ptr);
  void head_insert (Node*& head_ptr, const element_t& item);
  void insert (Node* prev_ptr, const element_t& item);
  Node* search (Node* head, const element_t& target);
  const Node* search (const Node* head_ptr, const element_t& target);
  Node* locate (Node* head_ptr, pos_int position);
  const Node* locate (const Node* head_ptr, pos_int position);
  
  void head_remove (Node*& head_ptr);
  void remove (Node* prev_ptr);
  void clear (Node*& head_ptr);
  
}


#endif











