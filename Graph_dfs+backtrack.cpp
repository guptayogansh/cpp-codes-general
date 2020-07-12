#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n, m;
vector<int> adj[mxN], ans;
int p[mxN];
bool v[mxN] = {0};

void dfs(int n, int pn = -1)
{
    v[n] = 1;
    p[n] = pn;
    for (auto nd : adj[n])
    {
        if (nd == pn)
            continue;
        if (v[nd])
        {

            int u = n;
            while (n ^ nd)
            {
                ans.push_back(n);
                n = p[n];
            }
            ans.push_back(nd);
            ans.push_back(u);
            cout << ans.size() << "\n";
            for (auto it : ans)
                cout << it + 1 << " ";
            exit(0);
        }
        else
            dfs(nd, n);
    }
}

int main()
{

    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 0; i < n; i++)
        if (!v[i])
            dfs(i);
    cout << "IMPOSSIBLE";
}
