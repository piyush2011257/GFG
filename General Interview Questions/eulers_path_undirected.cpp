/*
Following is Fleury’s Algorithm for printing Eulerian trail or cycle (Source Ref1).
1. Make sure the graph has either 0 or 2 odd vertices.
2. If there are 0 odd vertices, start anywhere. If there are 2 odd vertices, start at one of them.
3. Follow edges one at a time. If you have a choice between a bridge and a non-bridge, always choose the non-bridge.
4. Stop when you run out of edges.

The idea is, “don’t burn bridges“ so that we can come back to a vertex and traverse remaining edges. For example let us consider the following graph. 

http://www.geeksforgeeks.org/fleurys-algorithm-for-printing-eulerian-path/

Why degree should be even for cycle?
EUler cycle path - union of multiple disjoint eulerian cycles
One edge for going out and another to come back and complete the cycle and hence for each outgoing edge to start one cycle there is corresponding incoming edge to handle the return to complete the eulerian disjoint cycle

Same case extened for directed graphs - 
start is outgoing edge and return edge for completing cycle is indegree edge

For eulerian path in undirected- 
2 nodes odd-? 1  having start only and 1 having end only

Extending for directed - 1 having ingree + 1 == outdegree for start of path and other having outdegree + 1 == indegree to terminate the path
*/

#include <iostream>
#include <string.h>
#include <algorithm>
#include <list>
using namespace std;

class Graph
{	int V;
  	list<int> *adj;
	public:
  	Graph(int V)
	{	this->V = V;
		adj = new list<int>[V];
	}
  	~Graph()
	{	delete [] adj;	
	}
  	void addEdge(int u, int v)
	{	adj[u].push_back(v); 
		adj[v].push_back(u); 
	}
  	void rmvEdge(int u, int v);
  	void printEulerTour();
  	void printEulerUtil(int s);
  	int DFSCount(int v, bool visited[]);
  	bool isValidNextEdge(int u, int v);
};

void Graph::printEulerTour()
{	int u = 0;
  	for (int i = 0; i < V; i++)
      		if (adj[i].size() & 1)
        	{   u = i; break;  }

  	printEulerUtil(u);
  	cout << endl;
}

void Graph::printEulerUtil(int u)
{	list<int>::iterator i;
  	for (i = adj[u].begin(); i != adj[u].end(); ++i)
  	{	int v = *i;
      		if (v != -1 && isValidNextEdge(u, v))
      		{	cout << u << "-" << v << "  ";
          		rmvEdge(u, v);
          		printEulerUtil(v);
      		}
  	}
}

bool Graph::isValidNextEdge(int u, int v)
{	// The edge u-v is valid in one of the following two cases: 
	// 1) If v is the only adjacent vertex of u
  	int count = 0;  // To store count of adjacent vertices
  	list<int>::iterator i;
  	for (i = adj[u].begin(); i != adj[u].end(); ++i)
     		if (*i != -1)
        		count++;
  	if (count == 1)
    		return true;
	// 2) If there are multiple adjacents, then u-v is not a bridge Do following steps to check if u-v is a bridge

  	// 2.a) count of vertices reachable from u
  	bool visited[V];
  	memset(visited, false, V);
  	int count1 = DFSCount(u, visited);
  	// 2.b) Remove edge (u, v) and after removing the edge, count vertices reachable from u
	rmvEdge(u, v);
 	memset(visited, false, V);
  	int count2 = DFSCount(u, visited);
	// 2.c) Add the edge back to the graph
  	addEdge(u, v);
	// 2.d) If count1 is greater, then edge (u, v) is a bridge
  	return (count1 > count2)? false: true;
	// Easier method to check if edge is bridge or not. If number of edges reachable earlier < no. of edges reachable after -> diconnectedness -> edge ios bridge
}

void Graph::rmvEdge(int u, int v)
{	list<int>::iterator iv = find(adj[u].begin(), adj[u].end(), v);
  	*iv = -1;
  	list<int>::iterator iu = find(adj[v].begin(), adj[v].end(), u);
  	*iu = -1;
}

int Graph::DFSCount(int v, bool visited[])
{	visited[v] = true;
  	int count = 1;
  	list<int>::iterator i;
  	for (i = adj[v].begin(); i != adj[v].end(); ++i)
      		if (*i != -1 && !visited[*i])
          		count += DFSCount(*i, visited);
	return count;
}

int main()
{	Graph g1(4);
  	g1.addEdge(0, 1);
  	g1.addEdge(0, 2);
  	g1.addEdge(1, 2);
  	g1.addEdge(2, 3);
  	g1.printEulerTour();

  	Graph g2(3);
  	g2.addEdge(0, 1);
  	g2.addEdge(1, 2);
  	g2.addEdge(2, 0);
  	g2.printEulerTour();

  	Graph g3(5);
  	g3.addEdge(1, 0);
  	g3.addEdge(0, 2);
  	g3.addEdge(2, 1);
  	g3.addEdge(0, 3);
  	g3.addEdge(3, 4);
  	g3.addEdge(3, 2);
  	g3.addEdge(3, 1);
  	g3.addEdge(2, 4);
  	g3.printEulerTour();
	return 0;
}

/*
Assuming eulerian path / circut exists

http://en.wikipedia.org/wiki/Eulerian_path#Fleury.27s_algorithm
While the graph traversal in Fleury's algorithm is linear in the number of edges, i.e. O(|E|), we also need to factor in the complexity of detecting bridges. If we are to re-run Tarjan's linear time bridge-finding algorithm after the removal of every edge, Fleury's algorithm will have a time complexity of O(|E|2).

Thus during dfs, after burning each edge, we need to run SCC check algorithm to determine if the edge is a cut edge for the remaining Graph

Algorithm
s=start vertex

if no edge
	finish
else if s has multiple edges
	choose one edge which is not Cut Edge
else
	choose the left over edge
remove the chosen edge from the adjacency representation of graph
let edge be {s,s'} the s=s'
recursive
*/
