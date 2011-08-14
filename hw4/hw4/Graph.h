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

using namespace std;


// AIRPORT - NODE - VERTEX
class Airport
{
public:
  string  IATAcode;
  list    Flightpath*> adjFlights;
  bool    visited;
  double  cost;
  Airport *prev_ptr;
}


// FLIGHTPATH - EDGE
class Flightpath
{
public:
  double weight;
  Airport * dest;
  
  Flightpath(double c, Airport *d = NULL):weight(c), dest(d) {}  
  
  ~Flightpath() { if (dest) delete dest; }
}


// AIRMAP - NODEMAP - AIRPORTS
class AirMap
{
public:
  map < string, Airport* > airmap;
  
  Airport * find_in_airmap (const string &iata)
  {
    Airport * result = airmap[iata];
    if ( result == 0 )
    {
      result = airmap[iata] = new Airport(iata);
      return result;
    }
  }
  friend ostream& operator<<(ostream& o, AirMap amap)
  {
		map<string,Node*>::iterator im;
		for(im = amap.airmap.begin(); im != amap.airmap.end(); im++)
    {
			//pair<string,Node*> p = *im;
			//o << p.second->name << endl;
			o << (*im).second->name << endl;
      list<Flightpath*> adjFlights = (*im).second->adjFlights;
			list<Flightpath*>::iterator f;
      for(f = adjFlights.begin(); f != adjFlights.end(); f++)
      {
				cout << "   -> " << (*f)->dest->IATA << " weight " << (*e=f)->weight <<endl;
			}
		}
		return o;
	}
};



// is this correct?
struct compare{
  bool operator()(Airport * &a,Airport * &b) const
  {
    // least to greatest
    return (b->cost) < (a->cost);      
  }
};



// for each solution, reset node information
void reset_airports(AirMap &nm){
	map<string,Airport*>::iterator im;
	for(im = nm.airmap.begin(); im != nm.airmap.end(); im++){
		(*im).second->cost = 0; 
		(*im).second->prev_ptr = 0;
		(*im).second->visited = false;
	}
}



// DIJKSTRA ALGORITHM
void dijkstra ( string s, string t, AirMap &airports )
{
	// check and report or abort
	Airport* source = airports.airports[s];
	if(source==0){cout << s << " not in map " << endl; return;}
	else cout << s << " in map " << endl;
	Airport* target = airports.airports[t];
	if(target==0){cout << t << " not in map " << endl; return;}
	else cout << t << " in map " << endl;
  
	reset_airports(airports);
  
	// put the source into pq and loop until empty
	priority_queue < Airport*, deque<Airport*>, compare>  pq;
	pq.push(source);
	while(!pq.empty()){
    
		// process least cost node.
		Airport* curr = pq.top(); 
		pq.pop();
		curr->visited = true;
    
		// process neighbors
		list<Flightpath*>::iterator flight;
		for(flight = curr->adjFlights.begin(); flight != curr->adjFlights.end(); flight++){
			Airport *next = (*flight)->dest;
			if(!next->visited){
				next->cost += (*flight)->weight + curr->cost;
				next->visited = true;
				next->prev_ptr = curr;
				cout << " pushing " << next->IATAcode << " cost " << next->cost << endl;;
				pq.push(next);
			}
			else{
				// see if this can cost less
			}
		}
	}
}


void get_graph(string const &filename, AirMap &air_map) 
{
	ifstream inf(filename.c_str());
	string from, to;
	double weight;
	while ( inf.good() ) 
	{
		inf >> from >> to >> weight;
		if ( inf.good() ) 
		{
			Airport *Target = air_map.find_in_airmap(to);
			Airport *Source = air_map.find_in_airmap(from);
			Flightpath *connector = new Flightpath(weight,Target);
			Source->adjFlights.push_back(connector);
		}
	}
}


int main(){
	AirMap airports;
	
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
}

#endif

