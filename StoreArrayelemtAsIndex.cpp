#include <bits/stdc++.h>

using namespace std;

int main()
{

    vector<int> arr(5);
    arr = {2, 4, 5, 6, 7};
    int max = *max_element(arr.begin(), arr.end());

    vector<int> cnt(max + 1);

    for (int i = 0; i < 5; i++)
    {
        ++cnt[arr[i]];
    }

    for (auto it : cnt)
    {
        cout << it << " ";
    }
    return 0;
}