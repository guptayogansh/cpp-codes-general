#include<bits/stdc++.h>
using namespace std;


int CoinExchangeSpaceOptimised(int n, vector<int>& deno){

    int k = deno.size();

    int *dp = new int[n+1];

    for(int i=0;i<=n;i++)
      dp[i] = i;

    for(int j = 1; j <k;j++){
        for(int i=1; i<=n;i++){
            if(deno[j]<=i && dp[i] > 1+dp[i-deno[j]])
              dp[i] = 1 + dp[i-deno[j]];
        }
    }

    int result = dp[n];

    delete [] dp;

    return result;
}


int main(){
   int n = 16;
   vector<int> deno = {1,7,10};

   cout<<CoinExchangeSpaceOptimised(n, deno);

    return 0;
}