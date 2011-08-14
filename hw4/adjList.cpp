//
//  adjList.cpp
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

//***********************************************************************
#include <limits.h>
#include <iostream.h>
#include "vertex.h"
#include "adjlist.h"
//***********************************************************************
AdjList::AdjList (int new_size)		// Constructor
{
  size = new_size;
  List = new Adj_Node [size];
  if (!List)
	{
    cerr << "Out of space in AdjList !!" << endl;
    exit(1);
	}
  edges = 0;
  verts = DBL_MAX;	// to be set by calling program using setVerts()
  for (int i=0;i<size;i++)
	{
    List[i].head = new Vertex;	   // Initialize i'th list
    List[i].head->distance = DBL_MAX; // Initialize to "infinity"
    List[i].dist = DBL_MAX;
    List[i].curpos = List[i].head;	   // Current pos pointer in list
    List[i].known = 0;
	}
}
//***********************************************************************
AdjList::~AdjList()			// Destructor
{
  Vertex *temp,*vert_to_delete;
  for (int i=0;i<size;i++)
	{
    temp = List[i].head;
    while (temp)
		{
      vert_to_delete = temp;
      temp = temp->next;
      delete vert_to_delete;
		}
	}
  delete [] List;
}
//***********************************************************************
void AdjList::add_Edge(string vertA, string vertB, double edge) // add edge A->B
{
  ++edges;
  if (vertA > verts || vertB > verts) 
	{
    cerr << "Number of vertices exceeds size of " << size 
	 	<< " in AdjList::add_Edge !" << endl;
    cerr << "Exiting...." << endl;
    exit(-1);
	}
  List[vertA-1].curpos->next = new Vertex(vertB,vertA,edge,NULL);
  List[vertA-1].curpos = List[vertA-1].curpos->next;
}
//***********************************************************************
int AdjList::operator()(int vertA,int vertB)   // Distance between A & B
{
  if (vertA == vertB) return 0;		// Same vertices
  
  double distance = DBL_MAX;			// Default to "Infinity" if not found
  Vertex *temp = List[vertA-1].head->next;	// Start of List A
  
  while (temp && temp->name != vertB) temp = temp->next;	// Find B in List A
  
  if (temp) distance = temp->distance;	// Found
  
  return distance;
}
//***********************************************************************

