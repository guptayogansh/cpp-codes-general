#include <bits/stdc++.h>

using namespace std;

int RodCutter(int n, vector<int> cost, vector<int> rod)
{

    rod[0] = 0;
    rod[1] = cost[1];
    int max_val;
    for (int i = 2; i <= n; i++)
    {
        max_val = -1;
        for (int j = 1; j <= i; j++)
        {
            max_val = max(max_val, cost[j] + rod[i - j]);
        }
        rod[i] = max_val;
    }

    int result = rod[n];
    rod.clear();

    return result;
}
int main()
{

    vector<int> cost = {0, 2, 4, 7, 8};

    int n;
    cin >> n;
    vector<int> rod(n + 1);
    cout << RodCutter(n, cost, rod);
    return 0;
}
