//  Paul Reny - COMP 15
//  2011/06/09
//  Assignment: hw0
//  File: Bag.cpp
//  

#include "Node.h"
#include "Bag.h"

namespace renyp_ns_zero
{
  element_t Bag::remove()
  {
    if (!is_empty())
    {
      --total_nodes;
      return(node_remove(head));
    }
    return 0;
  };
}
