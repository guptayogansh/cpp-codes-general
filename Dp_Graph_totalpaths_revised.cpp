#include <bits/stdc++.h>
#define V 6
using namespace std;

vector<int> adj[V + 1];
vector<int> in(V + 1);
vector<int> ts;

void addedge(int u, int v)
{
  adj[u].push_back(v);
}

void kahn()
{
  for (int n = 1; n <= V; n++)
    for (auto nd : adj[n])
      in[nd]++;

  queue<int> q;

  for (int n = 1; n <= V; n++)
    if (in[n] == 0)
      q.push(n);

  while (!q.empty())
  {
    int n = q.front();
    q.pop();

    ts.push_back(n);

    for (auto nd : adj[n])
      if (--in[nd] == 0)
        q.push(nd);
  }
}
int count_paths(int s, int d)
{

  vector<int> paths(V + 1, 0);
  paths[s] = 1;
  for (int i = 0; i < ts.size(); i++)
    for (int j = 0; j < adj[ts[i]].size(); j++)
      paths[adj[ts[i]][j]] += paths[ts[i]];
  return paths[d];
}

int main()
{

  addedge(1, 2);
  addedge(1, 4);
  addedge(2, 3);
  addedge(3, 6);
  addedge(4, 5);
  addedge(5, 2);
  addedge(5, 3);
  kahn();
  cout << count_paths(2, 6);
}
