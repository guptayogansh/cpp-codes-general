#include <bits/stdc++.h>
using namespace std;

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(0);

    vector<string> strings;

    strings.push_back("one");
    strings.push_back("two");
    strings.push_back("three");

    //ways to print vectors
    // 1.st traditional way
    for (int i = 0; i < strings.size(); i++)
        cout << strings[i] << " ";
    cout << "\n";

    //2nd : Using iterators
    for (auto it = strings.begin(); it != strings.end(); it++)
        cout << *it << " ";

    vector<double> numbers(20);
    vector<double> nums(20, 1); // To initialise all the 20 elements of the vector to 1
    cout << "Size of numbers vector:"
         << " " << numbers.size() << "\n";

    int capacity = numbers.capacity(); // capacity is the size of the array the vector is internally maintaining
    cout << "Capacity of numbers vector:"
         << " " << capacity << "\n";

    for (int i = 0; i < 10000; i++)
    {
        if (numbers.capacity != capacity)
        {
            capacity = numbers.capacity();
            cout << "Capacity of numbers vector:"
                 << " " << capacity << "\n";
        }
        numbers.push_back(i);
    }

    // When the size exceeds the specified size, the vector copies all the elements to some other vector of a bigger size

    numbers.clear();
    cout << "Size of numbers vector:" // 0
         << " " << numbers.size() << "\n";
    cout << "Capacity of numbers vector:" // some big value
         << " " << capacity << "\n";

    // the clearing of a vector changes the size but not the capacity of the internal array maintained by the vector

    return 0;
}