#include <bits/stdc++.h>
#define V 5
using namespace std;

vector<int> adj[V];

void addedge(int u, int v)
{
    adj[u].push_back(v);
    adj[v].push_back(u);
}

bool visited[V] = {0};
void dfs(int n)
{
    stack<int> stack;
    stack.push(n);

    while (!stack.empty())
    {
        n = stack.top();
        stack.pop();

        if (!visited[n])
        {
            visited[n] = true;
            cout << n << " ";
        }

        for (auto nd : adj[n])
            if (!visited[nd])
                stack.push(nd);
    }
}

int main()
{

    addedge(0, 1);
    addedge(0, 2);
    addedge(0, 3);
    addedge(0, 4);
    addedge(1, 3);
    addedge(2, 3);
    addedge(2, 4);
    addedge(3, 4);
    dfs(0);
}