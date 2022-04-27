#include <iostream>
#include <vector>
#include <list>
#include <utility>
#include <algorithm>
using namespace std;

typedef struct edge 
{
    int u, v, weight;
}edge;

void edges(vector<list<pair<int, int>>> &Graph, vector<edge> &edgeList)
{
    for (int i = 2; i < Graph.size(); i++)
    {
        list<pair<int, int>> adjacent = Graph[i];
        pair<int, int> adj;
        for (auto j : adjacent)
        {
            adj = j;
            if(adj.first >= i)
                break;
            edgeList.push_back({i, adj.first, adj.second});
        }
    } 
}

bool compareEdgeWeights(edge a, edge b)
{
    return a.weight < b.weight;
}

int main()
{
    system("cls");
    vector<list<pair<int, int>>> Graph;
    list<pair<int, int>> adjacent;
    adjacent.push_back(make_pair(0, 0));
    Graph.push_back(adjacent);
    int v, vertice, weight;
    cout << "Enter number of vertices: ";
    cin >> v;
    cout << "\nEnter vertices adjacent to the given vertice and their weights: " << endl
         << "(Press 0 to enter for next vertice)\n";
    for (int i = 1; i <= v; i++)
    {
        cout << endl << i << ": \n";
        list<pair<int, int>> adjacent;
        while(v)
        {
            cout << "Vertice: ";
            cin >> vertice;
            if(vertice == 0)
                goto next_vertice;
            cout << "Weight: ";
            cin >> weight;
            adjacent.push_back(make_pair(vertice, weight));
        }
        next_vertice:
        Graph.push_back(adjacent);
    }
    vector<edge> edgeList;
    edges(Graph, edgeList);
    sort(edgeList.begin(), edgeList.end(), compareEdgeWeights);
    cout << "\nEdge list for graph: ";
    for(int i = 0; i < edgeList.size(); i++)
        cout << "\n(" << edgeList[i].u << ", " << edgeList[i].v << "): " << edgeList[i].weight;
    return 0;
}