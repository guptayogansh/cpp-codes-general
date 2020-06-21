#include<bits/stdc++.h>
using namespace std;

 const int num = 100;
 const int n = 5;
  int arr[] = {50,10,20,30,40};
  int dp[n+1][num+1] = {0};

  int solve(){

     for(int j=1;j<=num;j++){
       if(arr[0]<=j) dp[1][j] = arr[0];
       else dp[1][j] = 0;
     }

     for(int i=2;i<=n;i++)
         for(int j=1;j<=num;j++){
             if(arr[i-1] <= j) dp[i][j] = max(dp[i-1][j], arr[i-1]+ dp[i-2][j-arr[i-1]]);
             else dp[i][j] = dp[i-1][j];
        }
  
      // for(int i=0;i<=n;i++){
      //       for(int j=0;j<=num;j++){
      //           cout<<dp[i][j]<<" ";
      //       }

      //       cout<<"\n";
      //   }

        // Backtracking algorithm for max strawberries to find which bush values were picked

        int i = n;
        int j = num;

        while(i>0 && j>0){
          if(dp[i][j] == dp[i-1][j])
            i = i - 1;
          else{
            cout<<"Bush Picked " << i <<" with value: "<< arr[i-1]<<"\n";
            j = j - arr[i-1];
            i = i - 2; 
          } 
        }

  return dp[n][num];
  }

int main(){
    cout<< solve();
    return 0;
}