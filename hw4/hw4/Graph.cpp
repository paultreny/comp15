//
//  Graph.cpp
//  hw4
//
//  Created by Paul Reny on 8/14/11.
//  Copyright 2011 Reny Design. All rights reserved.
//

#include <cstdlib>
#include <vector>

using namespace std;


struct Vertex {
  int id;
  std::vector<int> neighbors;
  double dist_from_source;  // need some sentry value for "infinity"
  int prev;  // need some sentry value for "undefined"
};


template <class >
class <#class name#> {
  <#instance variables#>
  
public:
  <#member functions#>
};
  
public:
  <#member functions#>
};

template <vector>
class Graph {
  <#instance variables#>
  
public:
  <#member functions#>
};
class 

/*
#include "Graph.h"


class Graph {
  
private:
  
  bool** adjacencyMatrix;
  
  int vertexCount;
  
public:
  
  Graph(int vertexCount) {
    
    this->vertexCount = vertexCount;
    
    adjacencyMatrix = new bool*[vertexCount];
    
    for (int i = 0; i < vertexCount; i++) {
      
      adjacencyMatrix[i] = new bool[vertexCount];
      
      for (int j = 0; j < vertexCount; j++)
        
        adjacencyMatrix[i][j] = false;
      
    }
    
  }
  
  
  
  void addEdge(int i, int j) {
    
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
      
      adjacencyMatrix[i][j] = true;
      
      adjacencyMatrix[j][i] = true;
      
    }
    
  }
  
  
  
  void removeEdge(int i, int j) {
    
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount) {
      
      adjacencyMatrix[i][j] = false;
      
      adjacencyMatrix[j][i] = false;
      
    }
    
  }
  
  
  
  bool isEdge(int i, int j) {
    
    if (i >= 0 && i < vertexCount && j > 0 && j < vertexCount)
      
      return adjacencyMatrix[i][j];
    
    else
      
      return false;
    
  }
  
  
  
  ~Graph() {
    
    for (int i = 0; i < vertexCount; i++)
      
      delete[] adjacencyMatrix[i];
    
    delete[] adjacencyMatrix;
    
  }
  
};
*/


