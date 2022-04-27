#include <iostream>
#include <algorithm>
using namespace std;

typedef struct edge
{
    int u, v, weight;
} edge;

void edges(int Graph[10][10], int &n, edge edgeList[], int &e)
{
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            if (Graph[i][j] != 0)
            {
                edgeList[e].u = i;
                edgeList[e].v = j;
                edgeList[e].weight = Graph[i][j];
                e++;
            }
        }
    }
}

void edge_sort(edge edgeList[], int &e)
{
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = 0; j < e - 1 - i; j++)
        {
            if (edgeList[j].weight > edgeList[j + 1].weight)
                swap(edgeList[j], edgeList[j + 1]);
        } 
    }
}

bool compareEdgeWeights(edge a, edge b)
{
    return a.weight < b.weight;
}

int main()
{
    int Graph[10][10], n;
    system("cls");
    cout << "Enter number of vertices: ";
    cin >> n;
    cout << "Enter weight of edge between the vertices:\n";
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cout << "(" << i << ", " << j << "): ";
            cin >> Graph[i][j];
        }
    }
    edge edgeList[100];
    int e = 0;
    edges(Graph, n, edgeList, e);
    sort(edgeList, edgeList + e, compareEdgeWeights);
    //edge_sort(edgeList, e);
    cout << "\nEdge list for graph: ";
    for(int i = 0; i < e; i++)
        cout << "\n(" << edgeList[i].u << ", " << edgeList[i].v << "): " << edgeList[i].weight;
    return 0;
}