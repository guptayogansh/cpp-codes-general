#include<bits/stdc++.h>
#define INF 1e9+7
using namespace std;


vector<int> coins = {1,3,4}
const int n = 10;

bool ready[n+1];
int value[n+1];

int solve(int x){

    if(x<0) return INF;
    if(x==0) return 0;
    if(ready[x]) return value[x];

    int result = INF;
    for(auto c:coins)
      result = min(result, solve(x-c)+1);

    ready[x] = true;
    value[x] = result;
    return result;
}


int main(){

    cout<<solve(10);
}