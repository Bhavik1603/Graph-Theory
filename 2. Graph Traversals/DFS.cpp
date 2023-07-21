#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Graph
{
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    Graph(int V)
    {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    // Depth-First Search (DFS)
    void DFS(int startVertex, vector<bool> &visited)
    {
        visited[startVertex] = true;
        cout << startVertex << " ";

        for (int v : adjList[startVertex])
        {
            if (!visited[v])
            {
                DFS(v, visited);
            }
        }
    }

    void depthFirstTraversal()
    {
        vector<bool> visited(V, false);

        cout << "Depth-First Traversal (DFS): ";
        for (int i = 0; i < V; i++)
        {
            if (!visited[i])
            {
                DFS(i, visited);
            }
        }
        cout << endl;
    }
};

int main()
{
    int V = 6; // Number of vertices
    Graph graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 4);
    graph.addEdge(3, 4);
    graph.addEdge(3, 5);
    graph.addEdge(4, 5);

    graph.depthFirstTraversal(); // Output: 0 1 3 4 2 5

    return 0;
}
