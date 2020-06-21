#include<bits/stdc++.h>
#define items 7


using namespace std;

int zerooneknapsack(int wt[],int value[], int W){

    int dp[items+1][W+1];

    for(int i=0;i<=items;i++)
      dp[i][0] = 0;

    for(int j=0;j<=W;j++)
      dp[0][j] = 0;
    
    for(int i=1;i<=items;i++){
        for(int j=1;j<=W;j++){
            if(wt[i-1] <= j)
                 dp[i][j] = max(value[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else
               dp[i][j] = dp[i-1][j];
        }
    }

      for(int i=0;i<=items;i++){
            for(int j=0;j<=W;j++){
                cout<<dp[i][j]<<" ";
            }

            cout<<"\n";
        }



    //Backtracking algorithm to find which items were picked.

    int i = items;
    int j = W;

    while(i > 0 &&j > 0){
        if(dp[i][j] == dp[i-1][j])
          i = i - 1;
        else{
            cout<<"Picked item: "<<i<<"\n";
            j = j - wt[i-1];
            i = i - 1;
          
        }
    }



    return dp[items][W];
}

int main(){

    int wt[] = {2,1,3,2};
    int value[] = { 12,10,21,15};

    int W = 8;

 

    cout<< zerooneknapsack(wt, value, W);
  
    return 0;
}