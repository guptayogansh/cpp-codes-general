#include<bits/stdc++.h>

using namespace std;

vector<int> coins = {1,3,4};

const int n = 6;
int memo[n];
bool calculated[n];


int solve(int x){
    if(x<0) return 0;
    if(x==0) return 1;
    if(calculated[x]) return memo[x];
    
    int ways = 0;
    for(auto c: coins)
     ways += solve(x-c);
     
    memo[x] = ways;
    calculated[x] = true;
     
    return ways;
}


int main(){
    
    cout<< solve(5);
}