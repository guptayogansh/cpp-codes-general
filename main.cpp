#include <bits/stdc++.h>
using namespace std;

void tail(int n)
{

    if (n == 0)
        return;
    cout << "Tail recursion returning with n=" << n << "\n";
    tail(n - 1);
}

void head(int n)
{
    if (n == 0)
        return;
    head(n - 1);
    cout << "Head recursion returning with n=" << n << "\n";
}

int main()
{

    tail(10);
    return 0;
}