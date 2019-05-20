#include "Graph.h"

//making graph out of objects on game map
void  Graph::matrixToGraph(int **gameMap,int **mapIndex, int columns, int rows)
{

	for (int i = 0; i < rows; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (gameMap[i][j] != 0 && gameMap[i][j] != 12 && gameMap[i][j] != 13)
			{
				// current node (i*columns) + j
				//checking for neighbour above
				if ((i - 1) >= 0) 
				{
					if (gameMap[i - 1][j] != 0 && gameMap[i - 1][j] != 12 && gameMap[i - 1][j] != 13)
					{
						this->addEdge(mapIndex[i][j], mapIndex[i-1][j], 1);
					}
				}
				
				//checking for neighbour under
				if (i + 1 < rows)
				{
					if (gameMap[i + 1][j] != 0 && gameMap[i + 1][j] != 12 && gameMap[i + 1][j] != 13)
					{
						this->addEdge(mapIndex[i][j], mapIndex[i + 1][j], 1);
					}
				}
				
				//checking for neighbour on right
				if ((j + 1) < columns)
				{
					if (gameMap[i][j + 1] != 0 && gameMap[i][j + 1] != 12 && gameMap[i][j + 1] != 13)
					{
						this->addEdge(mapIndex[i][j], mapIndex[i][j+1], 1);
					}
				}
				
				//checking for neighbour on left
				if ((j - 1) >= 0)
				{
					if (gameMap[i][j - 1] != 0 && gameMap[i][j - 1] != 12 && gameMap[i][j - 1] != 13)
					{
						this->addEdge(mapIndex[i][j], mapIndex[i][j - 1], 1);
					}
				}
			}
		}
	}
}

void Graph::initGraph(int x)
{
	this->V = x;
	this->adj = new std::list<int>[2 * x];
	this->graphInitialised = true;
}

void Graph::addEdge(int v, int w, int weight)
{
	// split all edges of weight 2 into two 
	// edges of weight 1 each.  The intermediate 
	// vertex number is maximum vertex number + 1, 
	// that is V. 
	if (weight == 2)
	{
		this->adj[v].push_back(v + this->V);
		this->adj[v + this->V].push_back(w);
	}
	else // Weight is 1 
		this->adj[v].push_back(w); // Add w to v’s list. 
}

// To print the shortest path stored in parent[] 
int Graph::printShortestPath(int parent[], int s, int d)
{
	static int level = 0;

	// If we reached root of shortest path tree 
	if (parent[s] == -1)
	{
		/*std::cout << "Shortest Path between " << s << " and "
			<< d << " is " << s << " ";*/
		this->shortestPath.push_back(s);
		return level;
	}

	this->printShortestPath(parent, parent[s], d);

	level++;
	if (s - 2 < V)
	{
		this->shortestPath.push_back(s);
		//std::cout << s << " ";
	}

	return level;
}

// This function mainly does BFS and prints the 
// shortest path from src to dest. It is assumed 
// that weight of every edge is 1 
int Graph::findShortestPath(int src, int dest)
{
	if (shortestPath.size() > 0) 
	{
		int size = this->shortestPath.size();
		for (int i = 0; i < size; i++)
		{
			shortestPath.pop_back();
		}
	}

	// Mark all the vertices as not visited 
	bool *visited = new bool[2 * V];
	int *parent = new int[2 * V];

	// Initialize parent[] and visited[] 
	for (int i = 0; i < 2 * V; i++)
	{
		visited[i] = false;
		parent[i] = -1;
	}

	// Create a queue for BFS 
	std::list<int> queue;

	// Mark the current node as visited and enqueue it 
	visited[src] = true;
	queue.push_back(src);

	// 'i' will be used to get all adjacent vertices of a vertex 
	std::list<int>::iterator i;

	while (!queue.empty())
	{
		// Dequeue a vertex from queue and print it 
		int s = queue.front();

		if (s == dest)
		{
		return printShortestPath(parent, s, dest);
		}
		queue.pop_front();

		// Get all adjacent vertices of the dequeued vertex s 
		// If a adjacent has not been visited, then mark it 
		// visited and enqueue it 
		for (i = adj[s].begin(); i != adj[s].end(); ++i)
		{
			if (!visited[*i])
			{
				visited[*i] = true;
				queue.push_back(*i);
				parent[*i] = s;
			}
		}
	}
}

