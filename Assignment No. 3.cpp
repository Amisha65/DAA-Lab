#include <iostream>
#include <vector>
#include <climits>
using namespace std;

class Graph 
{
    int V;      // Number of vertices
    vector<vector<int>> edges;

public:
   Graph(int vertices) :  V(vertices) {}

    void addEdge(int u, int v, int weight) 
    {
        edges.push_back({u, v, weight});
    }

    void bellmanFord(int src) 
    {
        vector<int> dist(V, INT_MAX);
        dist[src] = 0;
        


        for (int i = 1; i <= V - 1; i++) 
        {
            for (auto edge : edges) 
            {
                int u = edge[0];
                int v = edge[1];
                int weight = edge[2];

                if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
                    dist[v] = dist[u] + weight;
            }
        }

        for (auto edge : edges) 
        {
            int u = edge[0];
            int v = edge[1];
            int weight = edge[2];

            if (dist[u] != INT_MAX && dist[u] + weight < dist[v]) 
            {
                cout << "Graph contains a negative-weight cycle" << endl;
                return;
            }
        }
        printSolution(dist);
    }

    void printSolution(vector<int>& dist) 
    {
        cout << "Vertex   Distance from Source" << endl;
        for (int i = 0; i < V; ++i) 
        {
            cout << i << "\t\t" << (dist[i] == INT_MAX ? "INF" : to_string(dist[i])) << endl;
        }
    }
};

int main() 
{
    int V, E;
    cout << "Enter the number of vertices: ";
    cin >> V;
    cout << "Enter the number of edges: ";
    cin >> E;

    Graph g(V);
    cout << "Enter the edges in the format (u v weight):" << endl;
    for (int i = 0; i < E; ++i) 
    {
        int u, v, weight;
        cin >> u >> v >> weight;
        g.addEdge(u, v, weight);
    }

    int src;
    cout << "Enter the source vertex: ";
   cin >> src;
    g.bellmanFord(src);
}



// OUTPUT:

// Enter the number of vertices: 6
// Enter the number of edges: 7
// Enter the edges in the format (u v weight):
// 3 2 6
// 5 3 1
// 0 1 5 
// 1 5 -3
// 1 2 -2 
// 3 4 -2 
// 2 4 3

// Enter the source vertex: 0
// Vertex   Distance from Source
// 0		0
// 1		5
// 2		3
// 3		3
// 4		1
// 5		2
