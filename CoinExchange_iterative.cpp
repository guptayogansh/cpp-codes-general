#include<bits/stdc++.h>
#define INF 1e9+7
using namespace std;

vector<int> coins = {1,3,4};

const int n = 10;
int value[n+1];


int solve(int n){
value[0] = 0;

for(int x=1;x<=n;x++){
    value[x] = INF;
    for(auto c:coins)
      value[x] = min(value[x],value[x-c]+1);
}

return value[n];

}

int main()
{
    cout<<solve(10);
}