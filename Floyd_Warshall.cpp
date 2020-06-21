#include <bits/stdc++.h>
#define V 5
#define INF 9999
using namespace std;

int d[V][V];

int adj[][V] = {
    {0, 5, INF, 9, 1},
    {5, 0, 2, INF, INF},
    {INF, 2, 0, 7, INF},
    {9, INF, 7, 0, 2},
    {1, INF, INF, 2, 0}};

void FW(int x, int y)
{

    for (int i = 0; i < V; i++)
        for (int j = 0; j < V; j++)
        {
            if (i == j)
                d[i][j] = 0;
            else if (adj[i][j])
                d[i][j] = adj[i][j];
            else
                d[i][j] = INF;
        }

    for (int k = 0; k < V; k++)
        for (int i = 0; i < V; i++)
            for (int j = 0; j < V; j++)
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);

    cout << d[x - 1][y - 1];
}

int main()
{
    FW(4, 3);
}