#include <bits/stdc++.h>
#define V 4
using namespace std;

vector<int> adj[V];
void addedge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool visited[V] = {0};

void bfs(int n)
{
    queue<int> q;
    q.push(n);

    while (!q.empty())
    {
        n = q.front();
        q.pop();

        if (!visited[n])
        {
            visited[n] = true;
            cout << n << " ";
        }

        for (auto nd : adj[n])
            if (!visited[nd])
                q.push(nd);
    }
}

int main()
{
    addedge(0, 1);
    addedge(0, 2);
    addedge(1, 2);
    addedge(2, 0);
    addedge(2, 3);
    addedge(3, 3);
    bfs(2);
}