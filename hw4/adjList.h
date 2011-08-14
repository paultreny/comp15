//
//  adjList.h
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

//**************************************************************************
#ifndef ADJLIST_H
#define ADJLIST_H
//**************************************************************************
#include "vertex.h"
//**************************************************************************
const int List_Default_Size = 1001;
//**************************************************************************
class AdjList //Adjacency List class
{
private:
  int size;
  int edges;
  int verts;
  struct Adj_Node {
    Vertex *curpos;
    Vertex *head;
    short known;
    double dist;
  } *List;
  
public:
  AdjList(int new_size = List_Default_Size);
  ~AdjList();
  
  void add_Edge(int ptA,int ptB, int edge);
  int operator ()(int vertA,int vertB);
  
  int Empty() {return (size == 0);};
  void setVerts(int nv) {verts = nv;};
  int no_of_edges() {return edges;};
  int no_of_verts() {return verts;};
  void setKnown(int i,short status) {List[i-1].known = status;};
  short Known(int i) {return List[i-1].known;};
  int distance(int i) {return List[i-1].dist;};
  void setDist(int i, int distance) {List[i-1].dist = distance;};
  Vertex *start(int i) {return List[i-1].head->next;};
  
};
//**************************************************************************
#endif
//**************************************************************************
