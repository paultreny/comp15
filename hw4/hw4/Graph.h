//
//  Paul Reny - COMP15 - August 12th, 2011
//  HW4 - Random Airlines
//  
//  Graph.h
//  
//  Created by Paul Reny on 8/9/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#ifndef PTR_COMP15_HW4_GRAPH
#define PTR_COMP15_HW4_GRAPH
#include <iostream>
#include <iomanip>
#include <string>
#include <list>
#include <map>
#include <stack>
#include <limits>
#include <float.h>
#include <queue>

using namespace std;

class Airport;
class Flightpath;
class AirportMap;

void reset_airports(AirportMap&);
void dijkstra (string, string, AirportMap&);


class Airport // Airport (Node/Vertex)
{
public:
  string  cityCode;
  list    <Flightpath*> adjAirports;
  bool    visited;
  double  min_cost;
  Airport *prev_ptr;
  Airport(string code){ 
    cityCode = code, 
    min_cost = std::numeric_limits<double>::infinity(), 
    prev_ptr = NULL, 
    visited = 0; }
};

class Flightpath // Flightpath (Weighted Edge)
{
public:
  double price;
  Airport* dest;
  Flightpath(double c, Airport *d = NULL):price(c), dest(d) {}  
  ~Flightpath() { if (dest) delete dest; }
};

class AirportMap // AirportMap (Graph)
{
public:
  size_t size;
  map <string, Airport*> airportmap;

  Airport* find_city (const string &code)
  {
    Airport* result = airportmap[code];
    if ( result == 0 )
    {
      ++size;
      result = airportmap[code] = new Airport(code);
    }
    return result;
  }
  
  friend ostream& operator<<(ostream& o, AirportMap ag)
  {
		map <string, Airport*>::iterator map_it;
		for(
        map_it = ag.airportmap.begin(); 
        map_it != ag.airportmap.end(); 
        map_it++)
    {				
      if (!map_it->second) break;  // if no cityname
      o << (*map_it).second->cityCode << endl; // output origin city
      
      list<Flightpath*> adjAirports = (*map_it).second->adjAirports;
      for(list<Flightpath*>::iterator f = adjAirports.begin(); f != adjAirports.end(); f++)
      {	cout << " -> " << (*f)->dest->cityCode << " $ " << (*f)->price <<endl; }
		}
		return o;
	}
};


struct compare{ bool operator()(Airport * &a, Airport * &b) const
{ return (b->min_cost) < (a->min_cost); }
};

// for each solution, reset node information
void reset_airports(AirportMap &ag)
{
	map <string,Airport*>::iterator mapit;
	for(mapit = ag.airportmap.begin(); mapit != ag.airportmap.end(); mapit++)
  {
		(*mapit).second->min_cost = std::numeric_limits<double>::infinity(); 
		(*mapit).second->prev_ptr = NULL;
		(*mapit).second->visited = false;
	}
}


// DIJKSTRA ALGORITHM
void dijkstra ( string s, string t, AirportMap &airports )
{
  
  Airport* source = airports.airportmap[s];
	if(source==0){cout << s << " not in map. " << endl; return;}
  Airport* target = airports.airportmap[t];
	if(target==0){cout << t << " not in map. " << endl; return;}
  
  priority_queue < Airport*, deque<Airport*>, compare>  pq;
	pq.push(source);
  
  stack<Airport*> flightStack;
  source->min_cost = 0;
  source->visited = true;
  
  while(!pq.empty())
  {
    Airport* curr = pq.top(); // MIN priority queue, cheapest path first
    pq.pop();
    curr->visited = true;
    
		list<Flightpath*>::iterator flight_it;  // NEIGHBORING AIRPORTS
		for(flight_it = curr->adjAirports.begin(); flight_it != curr->adjAirports.end(); flight_it++) 
    {
      Airport *next = (*flight_it)->dest;
			if(!next->visited)
      {
        next->min_cost = (*flight_it)->price + curr->min_cost;
				next->visited = true;
				next->prev_ptr = curr;
        if (next->cityCode == target->cityCode)
        {
          pq.push(next);
        }
        if (next==target) { break;}
      }
    }
    
    if (target->min_cost == DBL_MAX)
    {
      cout << "No connecting flights from " << 
      source->cityCode << " to " << 
      target->cityCode << " found." << endl;
    }
    else
    {
      cout << "Yes, flights from " << source->cityCode << " to " <<
      target->cityCode << " are available!" << endl;
      cout << "For example: " << endl;
      Airport* route = target;
      while(route != source)
      {
        flightStack.push(route);
        route = route->prev_ptr;    
      }
      int step = 0;
      double total = 0;
      cout.setf(ios::left, ios::adjustfield);
      
      while( !flightStack.empty() )
      {
        cout << ++step << ":        ";
        cout << setw(8) << flightStack.top()->prev_ptr->cityCode << "-> "; 
        cout << setw(8) << flightStack.top()->cityCode << "  $";
        cout << setprecision(2) << setw(8) << flightStack.top()->min_cost-total << endl;
        total = flightStack.top()->min_cost;
        flightStack.pop(); 
      }
      cout << "---------------------------------------" << endl;
      cout << setw(10) << " " << setw(8) << source->cityCode << "-> ";
      cout << setw(8) << target->cityCode << "  $";
      cout << setprecision(2) << setw(8) << target->min_cost << endl;
    }
  }
}


#endif


