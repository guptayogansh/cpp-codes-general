#include <bits/stdc++.h>
using namespace std;

bool sort_index_scores(const pair<int, int> &a,
                       const pair<int, int> &b)
{
    return (a.second > b.second);
}

int main()
{
    vector<pair<int, int>> v;
    int index[] = {0, 1, 2, 3, 4, 5};
    int score[] = {1, 2, 3, 6, 5, 4};

    for (int i = 0; i < 6; i++) // B = 6
        v.push_back(make_pair(index[i], score[i]));

    sort(v.begin(), v.end(), sort_index_scores);

    vector<int> test;

    for (int i = 0; i < 6; i++)
    {
        cout << v[i].first << ":" << v[i].second << "\n";
        test.push_back(v[i].first);
    }

    for (int i = 0; i < 6; i++)
    {
        cout << test[i] << " ";
    }
}