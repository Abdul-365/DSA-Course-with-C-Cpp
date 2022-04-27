#include <iostream>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int u, v, weight;
} edge;

void applyUnion(int belongs[], int n, int vertice1, int vertice2)
{
    for (int i = 0; i < n; i++)
    {
        if (belongs[i] == vertice2)
            belongs[i] = vertice1;
    }
}

bool compareWeights(edge a, edge b)
{
    return a.weight < b.weight;
}

void kruskalalgo(int n, edge edgeList[], int &e, edge spanList[], int &s)
{
    sort(edgeList, edgeList + e, compareWeights);
    int belongs[n];
    for (int i = 0; i < n; i++)
        belongs[i] = i;
    int vertice1, vertice2;
    for (int i = 0; i < e; i++)
    {
        vertice1 = belongs[edgeList[i].u];
        vertice2 = belongs[edgeList[i].v];
        if (vertice1 != vertice2)
        {
            spanList[s] = edgeList[i];
            s++;
            applyUnion(belongs, n, vertice1, vertice2);
        }
    }
}

int main()
{
    int n, e = 0, s = 0;
    system("cls");
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter number of edges: ";
    cin >> e;
    edge edgeList[e], spanList[e];
    cout << "Enter vertices and weight of edge between them:\n";
    for (int i = 0; i < e; i++)
    {
        cout << "\nVertice 1: ";
        cin >> edgeList[i].u;
        cout << "Vertice 2: ";
        cin >> edgeList[i].v;
        cout << "Weight of edge: ";
        cin >> edgeList[i].weight; 
    }
    kruskalalgo(n, edgeList, e, spanList, s);
    cout << "\nSpanning tree for graph: ";
    for (int i = 0; i < s; i++)
        cout << "\n(" << spanList[i].u << ", " << spanList[i].v << "): " << spanList[i].weight;
    return 0;
}