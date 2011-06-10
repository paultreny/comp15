//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Node.h
//  

#ifndef RENYP_NS_ZERO
#define RENYP_NS_ZERO

#include <cstdlib>

using namespace std;

namespace renyp_ns_zero
{
  typedef int element_t;
  typedef std::size_t pos_int;
  
  class Node
  {
    public:
      Node (const element_t& init_data = element_t(), Node* init_next = NULL)
        {node_data = init_data; node_next = init_next; }
      void set_data (const element_t& new_data) {node_data = new_data; }
      void set_next (Node* new_next) { node_next = new_next; }
      element_t get_data () const { return node_data; }
      Node* get_next() {return node_next; }
      const Node* get_next () const {return node_next; }
    private:
      element_t node_data;
      Node* node_next;
  };
  
  void node_insert (Node*& head_ptr, const element_t& item);
  element_t node_remove (Node*& head_ptr);
  void clear (Node*& head_ptr);
}
#endif
