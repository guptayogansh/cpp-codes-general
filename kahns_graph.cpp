#include <bits/stdc++.h>
#define V 4
using namespace std;

vector<int> adj[V + 1];
vector<int> in(V + 1, 0);
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

    for (auto i : ts)
        cout << i << " ";
}

int main()
{
    addedge(1, 2);
    addedge(1, 4);
    addedge(3, 1);
    addedge(3, 4);
    addedge(4, 2);
    kahn();
}