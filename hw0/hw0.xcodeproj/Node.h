//
//  Node.h
//  hw0
//
//  Created by Paul Reny on 6/9/11.
//  Copyright 2011 Apple Computer. All rights reserved.
//
#include <cstdlib>
#include <string>

using namespace std;

class Node
{
  typedef string element_t;
  typedef std::size_t pos_int;
  
public:
  Node (const element_t& init_data = element_t(), Node* init_next = NULL) { data = init_data; next = init_next; }
  
  void set_data (const element_t& new_data) {data = new_data; }
  void set_next (Node* new_next) { next = new_next; }
  
  element_t get_data () const { return data; }
  
  const Node* get_next () const {return next; }
  Node* get_next() {return next; }
  
  pos_int length (const Node* head_ptr);
  void head_insert (Node*& head_ptr, const Node::element_t& entry);
  void insert (Node* prev_ptr, const Node::element_t& entry);
  Node* search (Node* head, const Node::element_t& target);
  const Node* search (const Node* head_ptr, const Node::element_t& target);
  Node* locate (Node* head_ptr, pos_int position);
  const Node* locate (const Node* head_ptr, pos_int position);
  
  void head_remove (Node*& head_ptr);
  void remove (Node* prev_ptr);
  void clear (Node*& head_ptr);
  void copy (const Node* source, Node*& head_ptr, Node*& tail_ptr);
  
private:
  element_t data;
  Node* next;
  
  
  
  
  
  
  
  
};