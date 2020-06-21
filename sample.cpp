#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int books, libraries, days;
    freopen("a_example.txt", "r", stdin);
    freopen("a_output.txt", "w", stdout);

    cin >> books >> libraries >> days;
    vector<int> scores(books);
    for (int i = 0; i < books; i++)
        cin >> scores[i];

    vector<pair<pair<int, int>, pair<pair<int, int>, pair<vector<int>, map<int, int>>>>> library;

    int B, T, M;
    vector<int> lib_books;
    map<int, int> books_scores;
    int input_lib_books;

    for (int i = 0; i < libraries; i++)
    {
        lib_books.clear();
        cin >> B >> T >> M;
        for (int j = 0; j < B; j++)
        {
            cin >> input_lib_books;
            lib_books.push_back(input_lib_books);
            books_scores[input_lib_books] = scores[input_lib_books];
        }
        library.push_back(make_pair(make_pair(i, B), make_pair(make_pair(T, M), make_pair(lib_books, books_scores))));
    }

    for (int i = 0; i < libraries; i++)
        cout << library[i].first.first << ":" << library[i].first.second << " " << library[i].second.first.first << " " << library[i].second.first.second << " ";

    return 0;
}