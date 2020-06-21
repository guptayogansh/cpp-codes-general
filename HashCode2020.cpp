#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int Books, Libraries, Days;

    freopen("c_incunabula.txt", "r", stdin);
    freopen("c_output.txt", "w", stdout);

    cin >> Books >> Libraries >> Days;
    int A;
    A = Libraries;
    cout << A;

    vector<int> index(Books);
    iota(begin(index), end(index), 0);

    vector<int> scores(Books);
    for (int i = 0; i < Books; i++)
        cin >> scores[i];

    vector<pair<int, int>> v;

    for (int i = 0; i < Books; i++) // B = 6
        v.push_back(make_pair(index[i], scores[i]));

    sort(v.begin(), v.end(), [](const pair<int, int> &a, const pair<int, int> &b) -> bool {
        return (a.second > b.second);
    });

    int B, T, M;

    vector<int> lib_books;

    int input_lib_books;

    int K, Y, temp;
    vector<int> output_books;
    set<int> val;

    for (int i = 0; i < Libraries; i++)
    {
        lib_books.clear();
        output_books.clear();

        cin >> B >> T >> M;

        for (int i = 0; i < B; i++)
        {
            cin >> input_lib_books;
            lib_books.push_back(input_lib_books);
        }

        sort(lib_books.begin(), lib_books.end());

        int days_left = Days - T;
        int days_req_for_all_books = ceil(days_left / M);

        Y = i;

        if (days_req_for_all_books <= days_left)
            temp = B;
        else
            temp = days_left * M;

        for (int i = 0; i < v.size(); i++)
        {
            if (val.count(v[i].first) != 0)
                continue;

            if (binary_search(lib_books.begin(), lib_books.end(), v[i].first))
            {
                output_books.push_back(v[i].first);
                val.insert(v[i].first);
                temp--;
            }

            if (temp == 0)
                break;
        }

        K = output_books.size();

        cout
            << "\n"
            << Y << " " << K << "\n";
        for (int i = 0; i < output_books.size(); i++)
            cout << output_books[i] << " ";
    }

    index.clear();
    scores.clear();
    lib_books.clear();
    v.clear();
    output_books.clear();

    return 0;
}