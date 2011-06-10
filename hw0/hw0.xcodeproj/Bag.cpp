//  Paul Reny - COMP 15
//  Bag.cpp
//  hw0
//
//  Created by Paul Reny on 6/3/11.
//  Copyright 2011 Apple Computer. All rights reserved.
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
