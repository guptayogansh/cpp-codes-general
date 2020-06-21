#include<bits/stdc++.h>
#define rows 3
#define columns 3
using namespace std;


int MinCostPath(vector<vector<int>>& cost, int m,int n){
     
     int dp[rows][columns];

     dp[0][0] = cost[0][0];

     //Filling First column ( Which if I will look in the tree {Bottom up tree from 0,0 until 2,2}
     //is the leftmost part of the tree -> when we take only down step)
     for(int i = 1;i<=m;i++)
         dp[i][0] = dp[i-1][0] + cost[i][0];
     

     //Filling the First row( Which if I will look in the tree is the rightmost part of the tree -> when
     // we only take a right step)

    for(int j = 1;j<=n;j++)
        dp[0][j] = dp[0][j-1]+cost[0][j];


     for(int i=1;i<=m;i++){
         for(int j=1;j<=n;j++){
             dp[i][j] = cost[i][j] + min(dp[i-1][j-1], min( dp[i-1][j], dp[i][j-1]));
         }
     }


    //   for(int i=0;i<=m;i++){
    //      for(int j=0;j<=n;j++){
    //          cout<<dp[i][j]<<" ";
    //      }
    //      cout<<"\n";
    //  }


     return dp[m][n];
  }


int main(){


    vector<vector<int>> cost(rows, vector<int>(columns, 0));
    
    cost= {
        {1,2,3},
        {4,8,2},
        {1,5,3}
    };

    cout<<MinCostPath(cost,2,2);

    return 0;
}