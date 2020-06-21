#include <bits/stdc++.h>
using namespace std;

int main()
{

    vector<vector<int>> grid(3, vector<int>(4, 7));

    for (int row = 0; row < grid.size(); row++)
    {
        for (int col = 0; col < grid[row].size(); col++)
        {
            cout << grid[row][col] << " ";
        }
        cout << "\n";
    }

    cout << "\n\n";

    vector<vector<int>> vec(3, vector<int>(4, 1));

    vec[2].push_back(25);

    for (int i = 0; i < vec.size(); i++)
    {
        for (int j = 0; j < vec[i].size(); j++)
        {
            cout << vec[i][j] * 2 - 4 << " ";
        }
        cout << "\n";
    }
    return 0;
}