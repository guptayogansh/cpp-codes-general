#include<bits/stdc++.h>
#define ll long long
using namespace std;

// recursive approach
// ll BinaryExponentiation(ll a, ll n){

//     if (n==0)
//       return 1;
//     ll res = BinaryExponentiation(a, n/2);
//     if (n%2)
//       return res*res*a;
//     else
//       return res*res;
// }

//iterative approach - This one will be faster because of the recursive calls overhead
ll BinaryExponentiation(ll a, ll n){
    ll res = 1;
    while(n > 0){
        if(n & 1)
         res = res * a;
        a = a * a;
        n >>=1;
    }

    return res;
}

// Comput a^n mod m

// ll ComputeWithMod (ll a, ll n, ll m){
//     a %= m
//     ll res = 1;
//     while(n > 0){

//       if(n & 1)
//         res = res * a % m;
//      a = a * a %m;
//      n >>= 1;
//     }

//     return res;
    
// }
int main(){

    ll a,n;


    cin>>a>>n;
    
    cout<< BinaryExponentiation(a,n);

    return 0;
}