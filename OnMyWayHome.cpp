#include <bits/stdc++.h>

using namespace std;

int OnMyWayHome(int m, int n, vector<vector<int>> &ways)
{

    for (int i = 0; i < ways.size(); i++)
    {
        ways[i][0] = 1;
    }

    for (int j = 0; j < ways[0].size(); j++)
    {
        ways[0][j] = 1;
    }

    for (int i = 1; i < ways.size(); i++)
    {
        for (int j = 1; j < ways[i].size(); j++)
        {
            ways[i][j] = ways[i][j - 1] + ways[i - 1][j];
        }
    }

    // for (int i = 0; i < ways.size(); i++)
    // {
    //     for (int j = 0; j < ways[i].size(); j++)
    //     {
    //         cout << ways[i][j] << " ";
    //     }
    //     cout << "\n";
    // }

    int result = ways[m - 1][n - 1];
    ways.clear();
    return result;
}

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int m, n;

    cin >> m >> n;

    vector<vector<int>> ways(m, vector<int>(n));

    cout << OnMyWayHome(m, n, ways);

    return 0;
}