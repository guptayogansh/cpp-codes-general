#include<bits/stdc++.h>
using namespace std;

const int n = 4;
const int W = 8;

int v[]={12,10,21,15};
int wt[]={2,1,3,2};

int dp[W+1]={0};

int solve(){

   for(int i=1;i<=n;i++)
    for(int j=W;j>=0;j--)
     if(wt[i-1]<=j && v[i-1] + dp[j-wt[i-1]] > dp[j] )
       dp[j] = v[i-1] + dp[j-wt[i-1]];
   return dp[W];
}


int main(){
    cout<<solve();
}