#include<bits/stdc++.h>
using namespace std;

int JumpingJacks(int n){

    int dp[n+1];
    dp[0] = 0;
    dp[1] = 0;

    for(int i=2;i<=n;i++){
       if(i%2==0&&i%3==0)
         dp[i] = 1 + min(dp[i-1], min( dp[i/2], dp[i/3]));
       else if(i%2==0)
         dp[i] = 1 + min(dp[i-1], dp[i/2]);
       else if(i%3==0)
         dp[i] = 1+ min(dp[i-1], dp[i/3]);
       else
         dp[i] = 1 + dp[i-1];

    }

    for(int i=0;i<=n;i++)
      cout<<dp[i]<<" ";

  return dp[n];
}

int main(){

    int distance = 25;
    cout<< "\n"<< JumpingJacks(distance);

    return 0;
}