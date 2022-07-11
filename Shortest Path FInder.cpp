
/*
*******  SHORTEST PATH FINDER   *******

*******  DIJKSTRA ALGORITHM      *******

*/




#include <iostream>
using namespace std;
#include <limits.h>
 
#define V 6
 
//finding the vertex with minimum distance value
//set of vertices not yet included in shortest path tree
int minDist(int dist[], bool sptSet[])
{
   int min = INT_MAX, min_ind; // Initializing min value
 
    for (int v = 0; v < V; v++)
        if (sptSet[v] == false && dist[v] <= min)
            min = dist[v], min_ind = v;
            return min_ind;
}
 
//functioning to print the constructed distance array
void printSol(int dist[])
{
    cout <<"Vertex   \t Distance from Source" << endl;
    for (int i = 0; i < V; i++)
        cout  << i << " \t\t"<<dist[i]<< endl;
}
 
//Dijkstra's single source shortest path algorithm
//a graph represented using adjacency matrix representation
void Dijkstra(int graph[V][V], int source)
{
    int dist[V]; // The output array.  dist[i] will hold the shortest
    // distance from src to i
 
    bool sptSet[V]; // sptSet[i] will be true if vertex i is included in shortest
    // path tree or shortest distance from src to i is finalized
 
    // Initialize all distances as INFINITE and stpSet[] as false
    for (int i = 0; i < V; i++)
        dist[i] = INT_MAX, sptSet[i] = false;
 
    // Distance of source vertex from itself is always 0
    dist[source] = 0;
 
    // Find shortest path for all vertices
    for (int count = 0; count < V - 1; count++) {
        // Pick the minimum distance vertex from the set of vertices not
        // yet processed. u is always equal to src in the first iteration.
        int u = minDist(dist, sptSet);
 
        // Mark the picked vertex as processed
        sptSet[u] = true;
 
        // Update dist value of the adjacent vertices of the picked vertex.
        for (int v = 0; v < V; v++)
 
            // Update dist[v] only if is not in sptSet, there is an edge from
            // u to v, and total weight of path from src to  v through u is
            // smaller than current value of dist[v]
            if (!sptSet[v] && graph[u][v] && dist[u] != INT_MAX
                && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
 
    // print the constructed distance array
    printSol(dist);
}
 
int main()
{
   
    int graph[V][V] = {  
        {0, 1, 2, 0, 0, 5},
        {1, 0, 0, 5, 1, 0},
        {2, 0, 0, 2, 3, 0},
        {0, 5, 2, 0, 2, 2},
        {0, 1, 3, 2, 0, 1},
        {0, 0, 0, 2, 1, 0}
        
    };
 
    Dijkstra(graph, 0);
 
    return 0;
}
