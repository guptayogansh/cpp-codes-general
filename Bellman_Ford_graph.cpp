#include <bits/stdc++.h>
#define INF 1e9
#define V 5
using namespace std;

vector<tuple<int, int, int>> edges;
int dist[V];
int u, v, w;

void BF(int x, int y)
{

    for (int i = 1; i <= V; i++)
        dist[i] = INF;

    dist[x] = 0;

    for (int i = 1; i < V - 1; i++)
    {
        for (auto e : edges)
        {
            tie(u, v, w) = e;
            dist[v] = min(dist[v], dist[u] + w);
        }
    }
    cout << dist[y];
}

int main()
{
    edges.push_back({1, 2, 5});
    edges.push_back({1, 3, 3});
    edges.push_back({1, 4, 7});
    edges.push_back({2, 4, 3});
    edges.push_back({2, 5, 2});
    edges.push_back({3, 4, 1});
    edges.push_back({4, 5, 2});
    BF(1, 5);
}