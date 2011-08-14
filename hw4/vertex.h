//
//  vertex.h
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//
//**************************************************************************
#include <stdlib.h>
#include <string>
//**************************************************************************
#ifndef VERTEX_H
#define VERTEX_H
//**************************************************************************
// Vertex class, holds the vertex's name, parent, distance between them.
class Vertex
{
private:
	
public:
  // Default constructor
	Vertex(){next=NULL;};
  // Overloaded constructor, initializes variables
	Vertex(string n,string p,double d, Vertex *pointer=NULL)
	{name=n;parent=p;distance=d;next=pointer;};
  
  // Variable retrieval methods
	void setName(string nme) {name = nme;};
	void setParent(string newParent) {parent = newParent;};
	void setDistance(double dist) {distance = dist;};
  
  // Overloaded equals operator
	void operator =(Vertex& b) {
    name = b.name;
		parent = b.parent;
		distance = b.distance;
  };
	double operator >(Vertex& b) {return (distance > b.distance);};
	double operator >=(Vertex& b) {return (distance >= b.distance);};
	double operator <(Vertex& b) {return (distance < b.distance);};
	double operator <=(Vertex& b) {return (distance <= b.distance);};
  // Public pointer variable to another vertex
	Vertex *next;
	string name;
	string parent;
	double distance;
};
//**************************************************************************
#endif
//**************************************************************************

