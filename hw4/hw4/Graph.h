//
//  Graph.h
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef PTR_COMP15_HW4_GRAPH
#define PTR_COMP15_HW4_GRAPH
#include <iostream>
#include <fstream>
#include <string>
#include <list>
#include <map>
#include <queue>
#include <vector>
#include <pair.h>

using namespace std;

class Flightpath; // aka EDGE

class Airport // AIRPORT - NODE - VERTEX
{
public:
  string  IATAcode;
  list    <Flightpath*> adjAirports;
  bool    visited;
  double  min_cost;
  Airport *prev_ptr;
  Airport(string code){ IATAcode = code; visited = 0; }
};


class Flightpath // FLIGHTPATH - EDGE
{
public:
  double price;
  Airport* origin;
  Airport* dest;
  Flightpath(double c, Airport *d = NULL):price(c), dest(d) {}  
  ~Flightpath() { if (dest) delete dest; }
};


class aGraph // aGraph - NodeMap - AIRPORTS
{
public:
  map < string, Airport* > agraph;
  Airport* find_in_agraph (const string &iata)
  {
    Airport* result = agraph[iata];
    if ( result == 0 )
    {
      result = agraph[iata] = new Airport(iata);
      return result;
    }
  }
  
  friend ostream& operator<<(ostream& o, aGraph ag)
  {
		map <string, Airport*>::iterator mapit;
		for(
        mapit = ag.agraph.begin(); 
        mapit != ag.agraph.end(); 
        mapit++)
    {	
      //pair<string,Node*> p = *im;
			//o << p.second->name << endl;
			
      if (!mapit->second) break;
      o << (*mapit).second->IATAcode << endl;
      
      list<Flightpath*> adjAirports = (*mapit).second->adjAirports;
			list<Flightpath*>::iterator f;
      
      for(f = adjAirports.begin(); f != adjAirports.end(); f++)
      {
				cout << "   -> " << (*f)->dest->IATAcode << " weight " << (*f)->price <<endl;
			}
		}
		return o;
	}
};


// is this correct?
struct compare{ bool operator()(Airport * &a, Airport * &b) const
  {
    // least to greatest
    return (b->min_cost) < (a->min_cost);      
  }
};


// for each solution, reset node information
void reset_airports(aGraph &ag)
{
	map<string,Airport*>::iterator mapit;
	for(mapit = ag.agraph.begin(); mapit != ag.agraph.end(); mapit++)
  {
		(*mapit).second->min_cost = 0; 
		(*mapit).second->prev_ptr = 0;
		(*mapit).second->visited = false;
	}
}


// DIJKSTRA ALGORITHM
void dijkstra ( string s, string t, aGraph &airports )
{
	// check and report or abort
	Airport* source = airports.agraph[s];
	if(source==0){cout << s << " not in map " << endl; return;}
	else cout << s << " in map " << endl;
	Airport* target = airports.agraph[t];
	if(target==0){cout << t << " not in map " << endl; return;}
	else cout << t << " in map " << endl;
  
	reset_airports(airports);
  
	// put the source into pq and loop until empty
	priority_queue < Airport*, deque<Airport*>, compare>  pq;
	pq.push(source);
	while(!pq.empty())
  {
		// process least cost node.
		Airport* curr = pq.top(); 
		pq.pop();
		curr->visited = true;
    
		// process neighbors
		list<Flightpath*>::iterator flight;
		for(
        flight = curr->adjAirports.begin(); 
        flight != curr->adjAirports.end(); 
        flight++)
    {
			Airport *next = (*flight)->dest;
			if(!next->visited)
      {
				next->min_cost += (*flight)->price + curr->min_cost;
				next->visited = true;
				next->prev_ptr = curr;
				cout << " pushing " << next->IATAcode << " cost " << next->min_cost << endl;;
				pq.push(next);
			}
			else
      {
				// see if this can cost less
			}
		}
	}
}


void get_graph(string const &filename, aGraph &agraph) 
{
	ifstream inf(filename.c_str());
	string from, to;
	double weight;
	while ( inf.good() ) 
	{
		inf >> from >> to >> weight;
		if ( inf.good() ) 
		{
			Airport *Target = agraph.find_in_agraph(to);
			Airport *Source = agraph.find_in_agraph(from);
			Flightpath *connector = new Flightpath(weight,Target);
			Source->adjAirports.push_back(connector);
		}
	}
}

/*
int main()
{
	aGraph airports;
	
  get_graph("graph.txt", airports);
  
  cout << "after read graph" << endl;
	cout << airports;
	string s,t;
	do{
		cout << " Please enter a source" << endl;
		cin >> s;
		cout << " Please enter a target" << endl;
		cin >> t;
		dijkstra(s,t,airports);
		cout << "Enter y to continue " << endl;
		cin >> s;
	}while(s == "y");
  return 0;
}
*/

#endif


