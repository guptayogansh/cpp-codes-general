// StairWayToHeaven
#include <bits/stdc++.h>
using namespace std;

int StairWayToHeaven(int *ways, int n)
{

    ways[0] = 1;
    ways[1] = 1;
    for (int i = 2; i <= n; i++)
        ways[i] = ways[i - 1] + ways[i - 2];
    int result = ways[n];
    delete[] ways;
    return result;
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    int *ways = new int[n + 1];

    cout << StairWayToHeaven(ways, n);
    return 0;
}