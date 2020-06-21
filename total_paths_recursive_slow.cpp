#include <bits/stdc++.h>
#define V 6
using namespace std;

vector<int> adj[V + 1];

void addedge(int u, int v)
{
    adj[u].push_back(v);
}
int ct = 0;

void dfs(int s, int d)
{
    if (s == d)
        ct++;
    for (auto nd : adj[s])
        dfs(nd, d);
}

int main()
{

    addedge(1, 2);
    addedge(1, 4);
    addedge(2, 3);
    addedge(4, 5);
    addedge(5, 2);
    addedge(5, 3);
    addedge(3, 6);
    dfs(1, 3);
    cout << ct;
}