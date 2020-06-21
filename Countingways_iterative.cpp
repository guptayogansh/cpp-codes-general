#include<bits/stdc++.h>

using namespace std;

vector<int> coins = {1,3,4};

const int n = 5;
const int m = 1e9+7;
int ways[n+1];


int solve(int n){
   ways[0] = 1;
   for(int x=1;x<=n;x++)
    for(auto c:coins)
     if(x-c>=0){
      ways[x] += ways[x-c];
      ways[x] %= m;
     }
      
return ways[n];
}


int main(){
    
    cout<< solve(5);
}