//
//  pgraph.cpp
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include "pgraph.h"


#include <cassert>    // Provides assert
#include <cstdlib>    // Provides size_t
#include <set>        // Provides set


template <class Item>
const std::size_t pgraph<Item>::MAXIMUM;

template <class Item>
void pgraph<Item>::add_edge(std::size_t source, std::size_t target)
// Library facilities used: cassert, cstdlib
{
  assert(source < size( ));
  assert(target < size( ));
  edges[source][target] = true;
}

template <class Item>
void pgraph<Item>::add_vertex(const Item& label)
// Library facilities used: cassert, cstdlib
{
  std::size_t new_vertex_number;
  std::size_t other_number;
  
  assert(size( ) < MAXIMUM);
  new_vertex_number = many_vertices;
  many_vertices++;
  for (other_number = 0; other_number < many_vertices; ++other_number)
  {
    edges[other_number][new_vertex_number] = false;
    edges[new_vertex_number][other_number] = false;
  }
  labels[new_vertex_number] = label;
}

template <class Item>
bool pgraph<Item>::is_edge(std::size_t source, std::size_t target) const
// Library facilities used: cassert, cstdlib
{
  assert(source < size( ));
  assert(target < size( ));
  return edges[source][target];
}

template <class Item>
Item& pgraph<Item>::operator[ ] (std::size_t vertex)
// Library facilities used: cassert, cstdlib
{
  assert(vertex < size( ));
  return labels[vertex];     // Returns a reference to the label
}

template <class Item>
Item pgraph<Item>::operator[ ] (std::size_t vertex) const
// Library facilities used: cassert, cstdlib
{
  assert(vertex < size( ));
  return labels[vertex];     // Returns only a copy of the label
}

template <class Item>
std::set<std::size_t> pgraph<Item>::neighbors(std::size_t vertex) const
// Library facilities used: cassert, cstdlib, set
{
  std::set<std::size_t> answer;
  std::size_t i;
  
  assert(vertex < size( ));
  
  for (i = 0; i < size( ); ++i)
  {
    if (edges[vertex][i])
      answer.insert(i);
  }
  return answer;
}

template <class Item>
void pgraph<Item>::remove_edge(std::size_t source, std::size_t target)
// Library facilities used: cassert, cstdlib
{
  assert(source < size( ));
  assert(target < size( ));
  edges[source][target] = false;
}