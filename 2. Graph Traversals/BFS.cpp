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

    // Breadth-First Search (BFS)
    void breadthFirstTraversal(int startVertex)
    {
        vector<bool> visited(V, false);
        queue<int> q;

        visited[startVertex] = true;
        q.push(startVertex);

        cout << "Breadth-First Traversal (BFS): ";
        while (!q.empty())
        {
            int v = q.front();
            q.pop();
            cout << v << " ";

            for (int u : adjList[v])
            {
                if (!visited[u])
                {
                    visited[u] = true;
                    q.push(u);
                }
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

    graph.breadthFirstTraversal(0); // Output: 0 1 2 3 4 5

    return 0;
}
