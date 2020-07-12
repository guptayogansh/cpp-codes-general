#include <bits/stdc++.h>
using namespace std;

const int mxN = 1e5;
int n, m;
vector<int> adj[mxN];
int p[mxN];
bool v[mxN] = {0}, act[mxN];

void dfs(int n, int pn = -1)
{
    v[n] = 1;
    act[n] = 1;
    p[n] = pn;
    for (auto nd : adj[n])
    {
        if (act[nd])
        {
            vector<int> ans = {n};
            while (n ^ nd)
            {
                n = p[n];
                ans.push_back(n);
            }
            ans.push_back(ans[0]);
            reverse(ans.begin(), ans.end());
            cout << ans.size() << "\n";
            for (auto it : ans)
                cout << it + 1 << " ";
            exit(0);
        }
        else
            dfs(nd, n);
    }
    act4[n] = 0;
}

int main()
{
    cin >> n >> m;
    while (m--)
    {
        int a, b;
        cin >> a >> b, --a, --b;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; i++)
        if (!v[i])
            dfs(i);

    cout << "IMPOSSIBLE";
}