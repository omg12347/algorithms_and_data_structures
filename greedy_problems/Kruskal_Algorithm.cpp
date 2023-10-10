#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

#define edge pair<int, int>

class Graph {
private:
    vector<pair<int, edge>> graphEdges; // original graph
    vector<pair<int, edge>> minimumSpanningTree; // minimum spanning tree
    int *parent;
    int vertices; // number of vertices/nodes in the graph

public:
    Graph(int V);
    void addEdge(int u, int v, int weight);
    int findSet(int i);
    void unionSets(int u, int v);
    void kruskal();
    void printMinimumSpanningTree();
};

Graph::Graph(int V) {
    parent = new int[V];

    for (int i = 0; i < V; i++)
        parent[i] = i;

    graphEdges.clear();
    minimumSpanningTree.clear();
    vertices = V;
}

void Graph::addEdge(int u, int v, int weight) {
    graphEdges.push_back(make_pair(weight, edge(u, v)));
}

int Graph::findSet(int i) {
    if (i == parent[i])
        return i;
    else
        return findSet(parent[i]);
}

void Graph::unionSets(int u, int v) {
    parent[u] = parent[v];
}

void Graph::kruskal() {
    int uRep, vRep;
    sort(graphEdges.begin(), graphEdges.end());

    for (int i = 0; i < graphEdges.size(); i++) {
        uRep = findSet(graphEdges[i].second.first);
        vRep = findSet(graphEdges[i].second.second);

        if (uRep != vRep) {
            minimumSpanningTree.push_back(graphEdges[i]);
            unionSets(uRep, vRep);
        }
    }
}

void Graph::printMinimumSpanningTree() {
    cout << "Edges : Weight" << endl;

    for (int i = 0; i < minimumSpanningTree.size(); i++) {
        cout << minimumSpanningTree[i].second.first << " - "
             << minimumSpanningTree[i].second.second << " : "
             << minimumSpanningTree[i].first << endl;
    }
}

int main() {
    Graph g(6);
    g.addEdge(0, 1, 4);
    g.addEdge(0, 2, 4);
    g.addEdge(1, 2, 2);
    g.addEdge(1, 0, 4);
    g.addEdge(2, 0, 4);
    g.addEdge(2, 1, 2);
    g.addEdge(2, 3, 3);
    g.addEdge(2, 5, 2);
    g.addEdge(2, 4, 4);
    g.addEdge(3, 2, 3);
    g.addEdge(3, 4, 3);
    g.addEdge(4, 2, 4);
    g.addEdge(4, 3, 3);
    g.addEdge(5, 2, 2);
    g.addEdge(5, 4, 3);
    g.kruskal();
    g.printMinimumSpanningTree();
    return 0;
}
