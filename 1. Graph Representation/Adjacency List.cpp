#include <iostream>
#include <vector>
using namespace std;

class GraphAdjList
{
private:
    int V; // Number of vertices
    vector<vector<int>> adjList;

public:
    GraphAdjList(int V)
    {
        this->V = V;
        adjList.resize(V);
    }

    void addEdge(int u, int v)
    {
        adjList[u].push_back(v);
        adjList[v].push_back(u); // For undirected graph
    }

    void printGraph()
    {
        cout << "Adjacency List representation of the graph:" << endl;
        for (int i = 0; i < V; i++)
        {
            cout << i << " -> ";
            for (int v : adjList[i])
            {
                cout << v << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V = 5; // Number of vertices
    GraphAdjList graph(V);

    graph.addEdge(0, 1);
    graph.addEdge(0, 4);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(1, 4);
    graph.addEdge(2, 3);
    graph.addEdge(3, 4);

    graph.printGraph();

    return 0;
}
