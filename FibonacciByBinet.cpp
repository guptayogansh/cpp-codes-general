#include<bits/stdc++.h>
#define ll long long
using namespace std;


void FibonacciByBinet(ll n){
    ll result = (pow((1+sqrt(5))/2,n) - pow((1-sqrt(5))/2,n))/sqrt(5);
    cout<< "F(" << n <<") = " << result;
}
int main(){
    ll n;
     cin>>n;
     FibonacciByBinet(n);
    return 0;
}