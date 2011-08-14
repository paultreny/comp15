//  Paul Reny
//  pgraph.h
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef PTR_COMP15_HW4_PGRAPH
#define PTR_COMP15_HW4_PGRAPH

#include <cstdlib>
#include <set>
//#include <limits.h>


template <class Item>
class pgraph 
{
  
public:
  static const std::size_t MAXIMUM = INT_MAX;
  
  pgraph() { many_vertices = 0; }
  
  void add_vertex(const Item& label);
  void add_edge(std::size_t source, std::size_t target);
  void remove_edge(std::size_t source, std::size_t target);
  Item& operator [ ] ( std::size_t vertex);
  
  std::size_t size() const {return many_vertices; }
  bool is_edge(std::size_t source, std::size_t target) const;
  std::set<std::size_t> neighbors(std::size_t vertex) const;
  Item operator [ ] (std::size_t vertex) const;
  
  
private:
  bool edges[MAXIMUM][MAXIMUM];
  Item labels[MAXIMUM];
  std::size_t many_vertices;

};

#include "pgraph.template"
#endif



