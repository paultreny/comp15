//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Bag.cpp
//  

#include <cstdlib>
#include "Node.h"
#include "Bag.h"

namespace renyp_ns_zero
{
  void Bag::insert(const element_t& item)
  {
    head_insert(head, item);
    ++total_nodes;   
  }
}
