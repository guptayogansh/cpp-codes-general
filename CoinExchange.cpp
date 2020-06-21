#include<bits/stdc++.h>
using namespace std;

int CoinExchange(int n, vector<int> deno){
    
     int k = deno.size(); 
     int dp[n + 1][k+1];

        for (int j = 0; j <= k; j++) {
            dp[0][j] = 0;
        }

        for (int i = 0; i <= n; i++) 
            dp[i][0] = i;


        for (int j = 1; j <= k; j++) {
            for (int i = 1; i <= n; i++) {

                if (deno[j - 1] <= i && dp[i][j - 1] > dp[i - deno[j - 1]][j] + 1) {
                    dp[i][j] = 1 + dp[i - deno[j - 1]][j];
                } else {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        // for(int i=0;i<=n;i++){
        //     for(int j=0;j<=k;j++){
        //         cout<<dp[i][j]<<" ";
        //     }

        //     cout<<"\n";
        // }


        //Backtracking Algorithm - To find which coins were picked
        int i = n;
        int j = k;
        while(j>0 && i>0){
            if(dp[i][j] == dp[i][j-1])
              j = j-1;
            else{
                cout<<"Picked coin: "<<deno[j-1]<<"\n";
                i = i - deno[j-1];
            }
        }

        while(i > 0){
            cout<<"Picked coin: "<<deno[0]<<"\n";
            i = i -1;
        }
       
    return dp[n][k];
}
int main(){
    
    int n = 15;
    vector<int> deno(3);
    deno = {1,3,5};
    cout<<CoinExchange(n,deno);
    return 0;
}