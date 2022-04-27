#include <iostream>
using namespace std;

typedef struct edge
{
    int u, v, weight;
} edge;

typedef struct primsTable
{
    int key, pie, mst;
} primsTable;

void primsAlgo(int n, edge edgeList[], int e, primsTable table[])
{
    for (int i = 0; i < n; i++)
    {
        table[i].key = INT_MAX;
        table[i].mst = false;
    }
    table[0].key = 0;
    table[0].pie = -1;

    for (int i = 0; i < n; i++)
    {
        int min = INT_MAX, minPos;
        for (int i = 0; i < n; i++)
        {
            if (table[i].mst == false && table[i].key < min)
            {
                min = table[i].key;
                minPos = i;
            }
        }
        table[minPos].mst = true;
        if (table[minPos].pie != -1)
            cout << "\n(" << minPos << ", " << table[minPos].pie << "): " << table[minPos].key;
        for (int i = 0; i < e; i++)
        {
            if (edgeList[i].u == minPos)
            {
                int neighbour = edgeList[i].v;
                if (table[neighbour].mst == false && table[neighbour].key > edgeList[i].weight)
                {
                    table[neighbour].key = edgeList[i].weight;
                    table[neighbour].pie = edgeList[i].u;
                }
            }
            if (edgeList[i].v == minPos)
            {
                int neighbour = edgeList[i].u;
                if (table[neighbour].mst == false && table[neighbour].key > edgeList[i].weight)
                {
                    table[neighbour].key = edgeList[i].weight;
                    table[neighbour].pie = edgeList[i].v;
                }
            }
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
    edge edgeList[e];
    cout << "Enter vertice no.(starting from 0) and weight of edge between them:\n";
    for (int i = 0; i < e; i++)
    {
        cout << "\nVertice 1: ";
        cin >> edgeList[i].u;
        cout << "Vertice 2: ";
        cin >> edgeList[i].v;
        cout << "Weight of edge: ";
        cin >> edgeList[i].weight;
    }
    primsTable table[n];
    primsAlgo(n, edgeList, e, table);
    return 0;
}
