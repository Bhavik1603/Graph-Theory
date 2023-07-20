#include <iostream>
#include <vector>
using namespace std;

class GraphAdjMatrix
{
private:
    int V; // Number of vertices
    vector<vector<int>> adjMatrix;

public:
    GraphAdjMatrix(int V)
    {
        this->V = V;
        adjMatrix.resize(V, vector<int>(V, 0));
    }

    void addEdge(int u, int v)
    {
        adjMatrix[u][v] = 1;
        adjMatrix[v][u] = 1; // For undirected graph
    }

    void printGraph()
    {
        cout << "Adjacency Matrix representation of the graph:" << endl;
        for (int i = 0; i < V; i++)
        {
            for (int j = 0; j < V; j++)
            {
                cout << adjMatrix[i][j] << " ";
            }
            cout << endl;
        }
    }
};

int main()
{
    int V = 5; // Number of vertices
    GraphAdjMatrix graph(V);

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
