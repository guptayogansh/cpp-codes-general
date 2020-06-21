#include<bits/stdc++.h>
using namespace std;

string str1 = "love";
string str2 = "movie";

const int m = 4;
const int n = 5;

int dp[m+1][n+1];

int solve(){
    
    for(int i=0;i<=m;i++)
     for(int j=0;j<=n;j++){
         if(i==0) dp[i][j] = j;
         else if(j==0) dp[i][j] = i;
         else if(str1[i-1]==str2[j-1]) dp[i][j] = dp[i-1][j-1];
         // we would've taken dp[i-1][j-1] + cost[a][b]
         // here cost[a][b] = 0 if last character was same and 1 if last was different
         // we took this as a separate case so that we didn't have to worry about another array
         else dp[i][j] = 1 + min(dp[i][j-1], min(dp[i-1][j] , dp[i-1][j-1]));
     }
     
     return dp[m][n];
}

int main(){
    
    cout<<solve();
}