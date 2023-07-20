#include <iostream>
#include <vector>
using namespace std;

class GraphEdgeList
{
private:
    int V; // Number of vertices
    vector<pair<int, int>> edgeList;

public:
    GraphEdgeList(int V)
    {
        this->V = V;
    }

    void addEdge(int u, int v)
    {
        edgeList.push_back({u, v});
        edgeList.push_back({v, u}); // For undirected graph
    }

    void printGraph()
    {
        cout << "Edge List representation of the graph:" << endl;
        for (auto edge : edgeList)
        {
            cout << edge.first << " -> " << edge.second << endl;
        }
    }
};

int main()
{
    int V = 5; // Number of vertices
    GraphEdgeList graph(V);

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
