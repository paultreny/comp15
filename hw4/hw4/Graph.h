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
#include <stack>
#include <vector>
#include <limits.h>
#include <float.h>
#include <iomanip>

using namespace std;


//typedef vector<map<string, double> > graph;
//typedef map< pair <string, int>, double> neighbors;
  
class Flightpath; // aka EDGE
class aGraph;

struct compare_flights;

void reset_airports(aGraph&);

//struct compare_flights{}; //bool operator()(Flightpath*, Flightpath*) const;

class Airport // AIRPORT - NODE - VERTEX
{
public:
  string  cityCode;
  list    <Flightpath*> adjAirports;
  bool    visited;
  double  min_cost;
  Airport *prev_ptr;
  Airport(string code){ cityCode = code; min_cost = DBL_MAX, prev_ptr = NULL, visited = 0; }
};


class Flightpath // FLIGHTPATH - EDGE
{
public:
  double price;
  Airport* origin;
  Airport* dest;
  Flightpath(double c, Airport *o = NULL, Airport *d = NULL):price(c), origin(o), dest(d) {}  
  ~Flightpath() { if (origin) delete origin; if (dest) delete dest; }
};


class aGraph // aGraph - NodeMap - AIRPORTS
{
public:
  size_t size;
  map < string, Airport* > agraph;
  Airport* find_in_agraph (const string &code)
  {
    Airport* result = agraph[code];
    if ( result == 0 )
    {
      ++size;
      result = agraph[code] = new Airport(code);
    }
    return result;
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
			
      if (!mapit->second) break;  // if no cityname
      o << (*mapit).second->cityCode << endl; // output origin city
      
      list<Flightpath*> adjAirports = (*mapit).second->adjAirports;
			list<Flightpath*>::iterator f;
      
      for(f = adjAirports.begin(); f != adjAirports.end(); f++)
      {
        //<< (*mapit).second->cityCode
				cout  << "   -> " << (*f)->dest->cityCode << " price: " << (*f)->price <<endl;
			}
		}
		return o;
	}
};


struct compare{ bool operator()(Airport * &a, Airport * &b) const
{ return (b->min_cost) < (a->min_cost); }
};


//struct compare_flights { bool operator()(Flightpath* &a, Flightpath* &b) const
//  { return ((b->dest->cityCode) < (a->dest->cityCode)); }
//};


// for each solution, reset node information
void reset_airports(aGraph &ag)
{
	map <string,Airport*>::iterator mapit;
	for(mapit = ag.agraph.begin(); mapit != ag.agraph.end(); mapit++)
  {
		(*mapit).second->min_cost = DBL_MAX; 
		(*mapit).second->prev_ptr = NULL;
		(*mapit).second->visited = false;
	}
}


// DIJKSTRA ALGORITHM
void dijkstra ( string s, string t, aGraph &airports )
{

  Airport* source = airports.agraph[s];
	if(source==0){cout << s << " not in map. " << endl; return;}
//	else cout << s << " in map. ";
	
  Airport* target = airports.agraph[t];
	if(target==0){cout << t << " not in map. " << endl; return;}
//	else cout << t << " in map. " << endl;
  
	
  //reset_airports(airports);  // INITIALIZE ALL AIRPORT MIN_COST VALUES
  
	// put the source into pq and loop until empty
	
  priority_queue < Airport*, deque<Airport*>, compare>  pq;
	pq.push(source);
  
  stack<Airport*> flightStack;
  
  source->min_cost = 0;
  source->visited = true;
  
  //bool found = false;
  while(!pq.empty())
  {
		// process least cost node.
		Airport* curr = pq.top();
    curr->visited = true;
		if (curr->min_cost == DBL_MAX) { break; }
    pq.pop();

    
//    if (curr->cityCode == target->cityCode)
//    {
//      found = true;
//      while(curr->prev_ptr)
//      {
//        if (curr)
//        {
//          traceroute.push(curr);
//          curr = curr->prev_ptr;
//        }
//      }
//      while (!traceroute.empty())
//      {
//        Airport* output = traceroute.top();
//        traceroute.pop();
//        cout << output->prev_ptr->cityCode << " -> " << output->cityCode  << " $" << 
//        output->min_cost << endl;
//      }
//      break;
//    }

    
		list<Flightpath*>::iterator flight;  // NEIGHBORING AIRPORTS
		for(flight = curr->adjAirports.begin();
        flight != curr->adjAirports.end(); 
        flight++) 
      {
      Airport *next = (*flight)->dest;
			if(!next->visited)
      {
        next->min_cost = (*flight)->price + curr->min_cost;
				next->visited = true;
				next->prev_ptr = curr;
        //cout << " pushing " << next->cityCode << " $" << next->min_cost << endl;;
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
//                  
//      if (next->cityCode == target->cityCode )
//      {
//        while (!pq.empty())
//          {
//            Airport* path = pq.top();
//            pq.pop();
//            cout << path->cityCode << " " << path->min_cost << " " << (*flight)->price << endl;
//            
//            
//            
//          }
//          break;
//        }

  //stack<Airport*> traceroute;
  //Airport* current = target;
  //if (!current) exit(EXIT_FAILURE);
//  if (!source) exit(EXIT_FAILURE);
//  while (current->cityCode != source->cityCode)
//  {
//    traceroute.push(current);
//    current = current->prev_ptr;
//  }
  //cout << source->cityCode;
//  if (found == true)
//  {
//    while (!traceroute.empty())
//    {
//      Airport* output = traceroute.top();
//      traceroute.pop();
//      cout << output->prev_ptr->cityCode << " -> " << output->cityCode << " $" << output->min_cost << endl;
//    }
//  }
  //cout << target->cityCode << " S" << target->min_cost << endl;
  
//


//void get_graph(string const &filename, aGraph &agraph) 
//{
//	ifstream inf(filename.c_str());
//	string from, to;
//	double weight;
//	while ( inf.good() ) 
//	{
//		inf >> from >> to >> weight;
//		if ( inf.good() ) 
//		{
//			Airport *Target = agraph.find_in_agraph(to);
//			Airport *Source = agraph.find_in_agraph(from);
//			Flightpath *connector = new Flightpath(weight,Target);
//			Source->adjAirports.push_back(connector);
//		}
//	}
//}

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


