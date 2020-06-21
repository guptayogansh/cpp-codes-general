#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    int books, libraries;
    unsigned int days;

    freopen("d_tough_choices.txt", "r", stdin);
    freopen("d_output.txt", "w", stdout);

    cin >> books >> libraries >> days;

    vector<int> index(books);
    iota(begin(index), end(index), 0);

    vector<int> scores(books);
    for (int i = 0; i < books; i++)
        cin >> scores[i];

    vector<pair<int, int>> scores_index;

    for (int i = 0; i < books; i++)
        scores_index.push_back(make_pair(scores[i], index[i]));

    sort(scores_index.begin(), scores_index.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return (a.first > b.first);
    });

    int B, T, M;
    int input_lib_books;
    unordered_set<int> lib_books;

    unordered_set<int> usable_books;
    map<int, vector<int>> id_books;

    vector<pair<int, float>> mp;
    map<int, int> mp1;
    map<int, int> mp2;

    for (int i = 0; i < libraries; i++)
    {
        lib_books.clear();
        cin >> B >> T >> M;

        for (int i = 0; i < B; i++)
        {
            cin >> input_lib_books;
            if (usable_books.find(input_lib_books) == usable_books.end())
            {
                lib_books.insert(input_lib_books);
                usable_books.insert(input_lib_books);
            }
        }

        int temp = lib_books.size();
        vector<int> helper(temp);
        vector<int> scores;
        helper.clear();
        scores.clear();
        if (temp == 0)
            continue;

        for (int i = 0; i < index.size(); i++)
        {
            auto it = lib_books.find(scores_index[i].second);
            if (it != lib_books.end())
            {
                helper.push_back(scores_index[i].second);
                scores.push_back(scores_index[i].first);
                temp--;
            }

            if (temp == 0)
                break;
        }

        for (int k = 0; k < helper.size(); k++)
            id_books[i].push_back(helper[k]);

        mp.push_back(make_pair(i, (float)(accumulate(scores.begin(), scores.end(), 0) + helper.size()) / T));
        mp1[i] = T;
        mp2[i] = M;
    }

    sort(mp.begin(), mp.end(), [](const pair<int, float> &a, const pair<int, float> &b) -> bool {
        return (a.second > b.second);
    });

    auto it = mp.begin();
    cout << id_books.size() << "\n";
    while (days > 0)
    {
        int a = it->first;

        days -= mp1[a];

        int days_req_for_all_books = round(id_books[a].size() / mp2[a]);

        if (days_req_for_all_books <= days)
        {
            cout << a << " " << id_books[a].size() << "\n";
            for (auto i = id_books[a].begin(); i != id_books[a].end(); i++)
            {
                cout << *i << " ";
            }
            cout << "\n";
        }

        else
        {
            cout << a << " " << days * mp2[a] << "\n";
            for (auto i = id_books[a].begin(); i != id_books[a].begin() + days * mp2[a]; i++)
            {
                cout << *i << " ";
            }
            cout << "\n";
        }

        if (a == mp.rbegin()->first)
            break;

        it++;
    }
    return 0;
}