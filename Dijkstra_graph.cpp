#include <bits/stdc++.h>
#define V 5
#define INF 1e9
using namespace std;

vector<pair<int, int>> adj[V];

void addedge(int u, int v, int w)
{
    adj[u].push_back({v, w});
    adj[v].push_back({u, w});
}

int d[V];
priority_queue<pair<int, int>> q;
bool visited[V] = {false};

void D(int x, int y)
{
    for (int i = 1; i <= V; i++)
        d[i] = INF;

    d[x] = 0;

    q.push({0, x});

    while (!q.empty())
    {
        int n = q.top().second;
        q.pop();

        if (!visited[n])
            visited[n] = true;

        for (auto nd : adj[n])
        {
            int v = nd.first, w = nd.second;
            if (d[n] + w < d[v])
            {
                d[v] = d[n] + w;
                q.push({-d[v], v});
            }
        }
    }

    cout << d[y];
}

int main()
{

    addedge(1, 2, 5);
    addedge(1, 3, 3);
    addedge(1, 4, 7);
    addedge(2, 4, 3);
    addedge(2, 5, 2);
    addedge(3, 4, 1);
    addedge(4, 5, 2);
    D(1, 5);
}