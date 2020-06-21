#include <bits/stdc++.h>
using namespace std;

int ShareMarket(int n, vector<int> price)
{

    int max_val = -1;
    vector<int> min_uptil(n);
    min_uptil[0] = price[0];
    vector<int> max_profit(n);

    for (int i = 1; i < n; i++)
    {
        min_uptil[i] = min(min_uptil[i - 1], price[i]);
    }

    for (int i = 0; i < max_profit.size(); i++)
    {
        max_profit[i] = price[i] - min_uptil[i];
        if (max_profit[i] > max_val)
            max_val = max_profit[i];
    }

    return max_val;
}

int main()
{

    vector<int> price{8, 1, 2, 4, 6, 3};

    int n = price.size();

    cout << ShareMarket(n, price);

    return 0;
}