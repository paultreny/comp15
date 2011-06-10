//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Bag.h
//  

#include <cstdlib>
#include "Node.h"

using namespace std;

namespace renyp_ns_zero
{
  typedef element_t element_t;
  typedef pos_int pos_int;
  
  class Bag
  {
  public:
    Bag() { head = NULL; total_nodes = 0; }
    ~Bag() { clear(head); total_nodes = 0; }
    
    void insert(const element_t& item){node_insert(head, item); ++total_nodes;}
    element_t remove() { --total_nodes; return(node_remove(head)); }
    bool is_empty() const { return !bool(total_nodes); }
    pos_int size() const {return total_nodes; }
    
  private:
    Node* head;
    element_t data;
    pos_int total_nodes;
  };
}
