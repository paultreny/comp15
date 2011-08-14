//
//  main.cpp
//  hw4
//
//  Created by Paul Reny on 8/9/11.
//  Copyright 2011 __MyCompanyName__. All rights reserved.
//

#include <iostream>
#include <fstream>
#include <list>
#include <cstdlib>
#include <iomanip>
#include <cassert>
#include <queue>
#include <limits.h>

#include "Graph.h"

using namespace std;

void dijkstra (string, string, aGraph&);

int main ( int argc, const char * argv[])
{
  aGraph *flightmap = new aGraph();
  
  ifstream arq(getenv("FLIGHTDATA"));
  cin.rdbuf(arq.rdbuf());
  
  //cout << "  A  |  B  |   Cost" << endl;
  while(!cin.eof())
  {
    string iata1, iata2;
    double cost;
    cin >> iata1 >> ws >> iata2 >> ws >> cost >> ws;
    
    // CHECK IF 3 letter Alpha and both cities, or discard.
    for (int i = 0; i < 3; i++)
    {
      assert(sizeof(iata1));
      assert(sizeof(iata2));
      assert(isalpha(iata1[i]));
      assert(isalpha(iata2[i]));
    }
    
//    if (iata1 > iata2)  // make it so the two cities are in alphabetical order
//    {
//      string temp = iata1;
//      iata1 = iata2;
//      iata2 = temp;
//    }
    assert(cost > 0);
//    flightmap->add_vertex(iata1);
//    flightmap->add_vertex(iata2);
//    flightmap->add_edge();
    
    Airport *Source = flightmap->find_in_agraph(iata1);
    Airport *Target = flightmap->find_in_agraph(iata2);
    Flightpath *dest_target = new Flightpath(cost, Target);
    //Flightpath *dest_source = new Flightpath(cost, Source);
    
    
    //if (!redEye ) return (EXIT_FAILURE);
    
    //cout << redEye->price << redEye->dest->cityCode << endl;

    Source->adjAirports.push_back(dest_target);
//    Target->adjAirports.push_back(dest_source);
    
    //
    //cout << " " << iata1 << " | " << iata2 << " | "; 
    //cout << setw(8) << cost << endl;
       
  }
  cout << *flightmap;
  dijkstra("BOS", "MSN", *flightmap);
  
  //cout << *flightmap;
  return (EXIT_SUCCESS);
}


/*
struct Vertex {
  int id;
  std::vector<int> neighbors;
  int dist_from_source;  // need some sentry value for "infinity"
  int prev;  // need some sentry value for "undefined"
};

*/


/*
(
s.dist = 0
for (;;)
v = smallest unknown distance vertex
if (v == not_a_vertex) break;
v.known = true;

for each w adjacent to v
if ( ! w.known )
if ( v.dist + c(v,w) < w.dist)
{ decrease (w.dist to  v.dist + c(v,w) 
            w.path = v;
            }
  */        
            
  /*  if (argc == 1)
  {
    file_provided = 1;
    ifstream fin;
  } 
  
  
  if (!fin) { cerr << "Error:  Failed to read from input file \"" << argv << "\"" << endl; exit(EXIT_FAILURE); }
  fin.open(argv, ifstream::in);
  
  while(!fin.eof())
  {
    string iata1, iata2;
    double cost;
    
    fin >> iata1 >> ws >> iata2 >> ws >> cost >> ws;
    
    cout << iata1 >> endl >> iata2 >> endl >> cost >> endl;
    
    //fares.push(new pair<string,string>(iata1, iata2));
    
    
    
    
  };
  
  for (ifstream fin(FILEPATH); !fin.eof(); fin.getlin
*/
  
/*
     = (argc > 1) ? (argv[1]) : FILENAME; // let 27 items be the default
  const char FILENAME[] = argv[]; 
  
for (ifstream fin(FILENAME); !fin.eof(); fin>>ws) {
    


  const char STOPFILE[] = "/g/15/2011uc/public_html/homework/hw3/stopwords.txt";
  //const char STOPFILE[] = "/Users/paulreny/GitHub/comp15/hw3/hw3/stopwords.txt";

  for (ifstream fin(STOPFILE); !fin.eof(); fin>>ws)
  {
    if (!fin) // Read in and error check the file input
    {
      cerr << "Error reading \"" << STOPFILE << "\"" << endl;
      exit(-1);
    }
    
    string w;
    fin >> w;
    unsigned long hv = hash(w); // hash stop words using murmurhash3
    if (table[hv % TBLSZ] == 1) // if there is a hash conflict, output error
    {
      cout << "Stopword Collision! Fix Hash! " << w
      << " " << (hv % TBLSZ) << endl;
    }
    else
    {
      ++table[hv % TBLSZ];
      ++stop_hashed;
    }
  }
*/
// 
// 
// 
// 
// Random Airlines -> input
//
//  BOS	ORD	218.64
//  MSP	BOS	269.25
//  MSN	BOS	237.31
//  ORD	MSP	42.77
//  PHX	ORD	316.79
//  MSP	MSN	46.91
//
//  DEPTH and BREADTH first search without recursion
//  
//  Run Review * after Audrius Meskauskas
//  Breadth first search. At every step, the demo highlights the content of the queue. To see the recursion-less depth first search, select the last item in the algorithm combo box (Depth first NR).
//  Depth and breadth first search can be implemented without using recursion. We need a queue or list to enqueue/dequeue nodes to process. For both types of the search, the algorithm can be implemented the following way:
//  
//  Enqueue the start node.
//  While the queue is not empty:
//  
//  Dequeue node.
//  Visit it (print, for example)
//  Enqueue all children/neighbours of the node
//  
//  If we use the first-in first-out (FIFO) queue, the algorithm works as a breadth first search. If we use the first-in last-out stack instead, this converts the same actions into the depth first search algorithm. For the arbitrary graph, it may be required to maintain the list of visited nodes and not process them again.
//  
//  Both depth first and breadth first search runs in O(V+E) = O(b^d) time where d is the number of nodes and b is the branching factor (a most typical number of childs per node), V is the number of vertices and E is the number of edges
//  
//  
//
//
//DIJKSTRA
//
//  The algorithm assigns the "distance value" to every node. This value is the distance (cost) to reach the node from the initial (starting) node. This value is of course zero for the initial node itself. At the start of the algorithm, it is set to be infinite for all other nodes in the graph. The algorithm also needs to remember the collection of already visited nodes. The "current node" is initially set to the initial node.
//    
//    The can be implemented as following:
//    
//    For current node, calculate the tentative distance for all its unvisited nodes. For example, if current node (A) has distance of 7, and an edge connecting it with another node has a traversing cost of 2, the distance to B through A will be 7+2=9. If some larger distance has been previously assigned to this node, overwrite the distance.
//      Mark the current node as visited. A visited node will not be checked ever again. The distance, assigned to this node, is now is final and minimal.
//      Set the unvisited node with the smallest distance (from the start node, considering all nodes in graph) as the next "current node" and continue from step 1.
//      
//      The algorithms terminates when the goal node becomes the current node. If we need to find the distance till every node, the algorithm runs until there are no more unvisited nodes remaining in the graph. Unlike the Depth first search, the algorithm does not store directly the path itself - if this path is required, it must be separately recorded.
//        
//        Differently from the Depth first search, the algorithm does not directly simulate "walking over the graph". The new current node in the next iteration of the loop need not be picked next to the current node; it can be picked anywhere in the graph. However node that already has some assigned tentative distance will have priority over completely unknown node for that the current tentative distance is infinite. This rule will force the search to concentrate closer to the start node. For some complex graph significant part of nodes may stay unexplored as they definitely cannot be on a shortest path between the start and goal node.
//          
//          Depending from how well the used data structures are implemented, the algorithm can run in from till time, where V is the number of vertexes and E is the number of edges[1].
//          
//          Dijkstra algorithm can be viewed as a separate case of A* algorithm with zero heuristic function.
//          [Edit]
//          
//          
//          
//          
//
// Accept File Input from CSTD input < AND Args[]  
//
   



/*
 BOS	ORD	200.00
 MSP	BOS	300.00
 MSN	BOS	400.00
 ORD	MSP	 50.00
 PHX	ORD	500.00
 MSP	MSN	 25.00
*/


