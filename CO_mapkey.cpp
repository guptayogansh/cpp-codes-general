#include <bits/stdc++.h>

using namespace std;

class Library
{

    int books;
    int signup_time;
    int books_per_day;
    vector<int> lib_books;

public:
    Library() : books(0), signup_time(0), books_per_day(0), lib_books({0}) {}
    Library(int books, int signup_time, int books_per_day, vector<int> lib_books) : books(books), signup_time(signup_time), books_per_day(books_per_day), lib_books(lib_books) {}

    void display() const
    {
        cout << books << " " << signup_time << " " << books_per_day << "\n";
        for (auto it : lib_books)
        {
            cout << it << " ";
        }

        cout << "\n";
    }

    bool operator<(const Library &obj) const
    {
        return lib_books.size() > obj.lib_books.size();
    }
};

int main()
{

    map<Library, int> lib_info;
    vector<int> lib_books = {0, 1, 2, 3, 4};
    lib_info[Library(5, 2, 2, lib_books)] = 0;
    lib_books = {0, 2, 3, 5};
    lib_info[Library(4, 3, 1, lib_books)] = 1;

    for (auto it = lib_info.begin(); it != lib_info.end(); it++)
    {
        cout << it->second << ":";
        it->first.display();
    }

    return 0;
}