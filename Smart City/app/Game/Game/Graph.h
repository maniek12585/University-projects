#pragma once
#include <list>
#include <vector>
#include <set>
#include <iostream>
#include <stack>

// This class represents a directed graph using adjacency 
// list representation 
class Graph
{
	int V;    // No. of vertices 
	std::list<int> *adj;    // adjacency lists 

	bool graphInitialised;
public:
	Graph() {};
	~Graph() {}; 

	std::deque<int> shortestPath;

	void initGraph(int x);

	void addEdge(int v, int w, int weight); // adds an edge 

	// finds shortest path from source vertex ‘s’ to 
	// destination vertex ‘d’. 
	int findShortestPath(int s, int d);

	//void printGraph();

	// print shortest path from a source vertex ‘s’ to 
	// destination vertex ‘d’. 
	int printShortestPath(int parent[], int s, int d);

	//making graph out of objects on game map
	void matrixToGraph(int **gameMap, int **mapIndex, int columns, int rows);

	bool getGraphInitialised() { return this->graphInitialised; }
	void setGraphInitialised(bool x) { this->graphInitialised = x; }
};



