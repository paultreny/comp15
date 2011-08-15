//
//  Paul Reny - COMP15 - August 12th, 2011
//  HW4 - Random Airlines
//  
//  main.cpp
//  
//  Created by Paul Reny on 8/9/11.
//  Copyright 2011 Reny Design. All rights reserved.
//
//
//
//  This program is intended to read from standard-input
//  (cin) a text file containing lines of code formatted
//  similar to the example below, store it in a directed
//  graph and answer if it is possible to go from BOS to
//  MSN.
//  
//  
//
//  BOS	ORD	218.64
//  MSP	BOS	269.25
//  MSN	BOS	237.31
//  ORD	MSP	42.77
//  PHX	ORD	316.79
//  MSP	MSN	46.91
// 

#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <limits.h>
#include "Timer.h"
#include "Graph.h"


using namespace std;

void dijkstra (string, string, AirportMap&);

typedef pair<string, string> citycode;

int main (int argc, const char * argv[])
{
  ifstream arq(getenv("FLIGHTDATA")); cin.rdbuf(arq.rdbuf());
  // used for Xcode when testing ^ not needed for commandline
    
  AirportMap *flightmap = new AirportMap();
  int flightcount;
  comp15::Timer stopwatch;
  
  while(!cin.eof())  // read in data from cin, ie, "BOS  MMK  12.90"
  {
    citycode cityPair;
    double cost;
    cin >> cityPair.first
        >> ws 
        >> cityPair.second
        >> ws 
        >> cost 
        >> ws;
    
    // VERIFY City Names are only letters/numbers, convert to uppercase.  
    for (int i = 0; i < (int)cityPair.first.size(); i++) {
      assert(isalnum(cityPair.first[i]));
      cityPair.first[i] = toupper(cityPair.first[i]); }
    for (int i = 0; i < (int)cityPair.second.size(); i++) {
      assert(isalnum(cityPair.second[i]));
      cityPair.second[i] = toupper(cityPair.second[i]); }
    
    assert(cityPair.first != cityPair.second); // verify both aren't the same
    assert(cost >= 0);  // verify non-negative cost for each flight

    // Look for Airport in graph, if not alreayd present, add an airport node
    Airport *origin = flightmap->find_city(cityPair.first);
    Airport *destination = flightmap->find_city(cityPair.second);
    Flightpath *flightToDest = new Flightpath(cost, destination);

    // add a flight to destination to the origin's adjAirports list.
    origin->adjAirports.push_back(flightToDest);
    ++flightcount;
  }
  
  // formatted output
  cout << endl << flightcount << " Flights between " << flightmap->size << " Airports added to graph.";
  cout << "(" << fixed << setprecision(6) << stopwatch.elapsed() << " seconds elapsed.)" << endl << endl;
  comp15::Timer d_watch;
  dijkstra("BOS", "MSN", *flightmap);
  
  cout << endl << "(compute time after reading input:  " << fixed << setprecision(6) << d_watch.elapsed() << " seconds." << endl;
  //cout << *flightmap;
  
  return (EXIT_SUCCESS);
}


