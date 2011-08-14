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
class pgraph {

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
  bool **edges;
  Item *labels;
  std::size_t allocated;
  std::size_t many_vertices;

};

#include "pgraph.template"
#endif



edges = new (bool*) [n];
for (i=0; i<n; ++i)
edges[i] = new bool[n];

for ( i=0; i<n; ++i)
  for ( j=0; j<n; ++j)
    edges[i][j] = false;
    
implementation should include a constructor with one argument. this argument is a size_t value that specifies the initial allocation for the number or roes and columns in the adjacency matrix.
    
add_vertex is called and the matrix is already full, then add_vertex should call resize to alocate larger adj matrix.