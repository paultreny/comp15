//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Bag.h
//  

#include <cstdlib> // used for NULL
#include "Node.h"

using namespace std;

namespace renyp_ns_zero // custom namespace
{
  typedef element_t element_t;
  typedef pos_int pos_int;
  
  class Bag
  {
  public:
    // Constructor - Destructor
    Bag() { head = NULL; total_nodes = 0; }
    ~Bag() { clear(head); total_nodes = 0; }
    
    // inserts an item into the bag, increments total_nodes
    void insert(const element_t& item){node_insert(head, item); ++total_nodes;}
    
    // removes an item from the bag, decrements total_nodes
    element_t remove();
    // returns true(1) if empty, false(0) if not
    bool is_empty() const { return !(bool(total_nodes)); }
    // publicly accessible size() function to return total_nodes
    pos_int size() const {return total_nodes; }
    
  private:
    Node* head; // private pointer, keeps track of our linked list of Nodes
    pos_int total_nodes;
  };
}
