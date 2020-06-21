#include <bits/stdc++.h>
using namespace std;

class Test
{
    int id;
    string name;

public:
    Test() : id(0), name("") {}
    Test(int id, string name) : id(id), name(name) {}

    void display()
    {
        cout << id << " " << name << "\n";
    }

    // bool operator<(const Test &obj) const //This is operator overloading. This is helping us to override the meaning of "<" to id < obj.id so that the sort function that we use works fine
    // {
    //     return id < obj.id;
    // }

    friend bool comp(const Test &a, const Test &b);
};

//instead of the above operator overloading we can also make a function and pass that (Comparator function). This is basically a function pointer

bool comp(const Test &a, const Test &b)
{
    return a.id < b.id;
}
int main()
{

    vector<Test> vec;

    vec.push_back(Test(194, "yogansh"));
    vec.push_back(Test(19, "tapishwar"));

    sort(vec.begin(), vec.end(), comp);
    for (int i = 0; i < vec.size(); i++)
    {
        vec[i].display();
    }

    return 0;
}