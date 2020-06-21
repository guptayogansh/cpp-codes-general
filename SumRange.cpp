#include <bits/stdc++.h>

using namespace std;

int SumRange(int m, int n, vector<int> my_array)
{

    vector<int> Sum_Until_i(my_array.size());

    Sum_Until_i[0] = my_array[0];

    for (int i = 1; i < Sum_Until_i.size(); i++)
    {
        Sum_Until_i[i] = Sum_Until_i[i - 1] + my_array[i];
    }

    if (m == 0)
        return Sum_Until_i[n];
    else
        return Sum_Until_i[n] - Sum_Until_i[m - 1];
}
int main()
{

    vector<int> my_array{1, -2, 3, 10, -8, 0};
    int m, n;
    cin >> m >> n;

    cout << SumRange(m, n, my_array);

    return 0;
}