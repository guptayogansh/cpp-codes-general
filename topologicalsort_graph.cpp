#include <bits/stdc++.h>
#define V 6
using namespace std;

vector<int> adj[V];
vector<int> tsans;

void addedge(int u, int v)
{
  adj[u].push_back(v);
}

bool visited[V] = {0};

void dfs(int n)
{
  if (visited[n])
    return;
  visited[n] = true;
  for (auto nd : adj[n])
    dfs(nd);
  tsans.push_back(n);
}

void ts()
{
  for (int n = 1; n <= V; n++)
    if (!visited[n])
      dfs(n);
}

int main()
{
  addedge(1, 2);
  addedge(2, 3);
  addedge(3, 6);
  addedge(4, 1);
  addedge(4, 5);
  addedge(5, 2);
  addedge(5, 3);
  ts();
  reverse(tsans.begin(), tsans.end());
  for (auto a : tsans)
    cout << a << " ";
}