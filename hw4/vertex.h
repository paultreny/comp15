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

#include <iostream> 
#include <fstream> 
#include <stdio.h> 
#include <stdlib.h> 
#include <ctype.h> 
#include <string.h> 
#include <math.h> 
#include <limits.h> 
#include <vector>

using namespace std;

class Edge;

class Node 
{ 
public: 
  int id; 
  bool visited; 
  vector <Edge*>* adj; 
  double distance; 
  Node* previous; 
  Node(int); 
  ~Node(){}; 
};

class Edge 
{ 
  public: Node* initial; 
  Node* next; 
  double w; 
  Edge(Node*, 
  Node*, int); 
  ~Edge(){}; 
  
  bool Connects(Node* node1, Node* node2) 
  {
  return((node1==this->initial&&node2==this->next)||(node1==this->next&&node2==this->initial));
  }
};

Node::Node(int a) 
{ 
  id=a; 
  visited=0; 
  adj=new vector<Edge*>; 
  previous=NULL; 
  distance=DBL_MAX;
}


Edge::Edge(Node* a, Node* b, double weight) 
{ 
  initial=a; 
  next=b; 
  w=weight; 
}


class MyGraph
{ 
  public: int Maxnodes; 
  int m; 
  vector <Edge*> Akmes; 
  vector <Node*> List; 
  Node* remaining[]; 
  MyGraph(int); 
  ~MyGraph();
  int GetNumNodes(); 
  int GetNumEdges(); 
  void InsertEdge(int,int,double); 
};

MyGraph::MyGraph(int size) 
{ 
  Maxnodes=size;
  for (int i=1;i<=Maxnodes;i++)
  {
    Node* temp=new Node(i);
    List.push_back(temp);
  } 
  m=0; 
}

MyGraph::~MyGraph() {}

int MyGraph::GetNumNodes() { return Maxnodes; }

int MyGraph::GetNumEdges() { return Akmes.size(); }

void MyGraph::InsertEdge(int x, int y, double w)
{ 
  Node* a=List[x-1]; 
  Node* b=List[y-1]; 
  Edge* akmi=new Edge(a,b,w); 
  Edge* akmi2=new Edge(b,a,w); 
  Akmes.push_back(akmi); 
  a->adj->push_back(akmi); 
  b->adj->push_back(akmi2); 
}