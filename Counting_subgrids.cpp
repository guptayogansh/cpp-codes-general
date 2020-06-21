/*
Given an n× n grid whose each square is either black (1) or white (0), calculate the number of subgrids
whose all corners are black
*/

#include<bits/stdc++.h>
#define ll long long
#define m 1e9+7


const int mxn = 5;


int counting_subgrids(int grid[][mxn]){
    
 
    int subgrids = 0;
    for(int a=0;a<mxn;a++)
      for(int b=a+1;b<mxn;b++)
      {
          int count = 0;
          for(int i=0;i<mxn;i++)
            // if(grid[a][i] == 1 && grid[b][i] == 1) count++;
            count += __builtin_popcount(grid[a][i]&grid[b][i])
           subgrids += (count*(count-1))/2;
      }
      
  return subgrids;
}
using namespace std;

int main(){
    
  int grid[][mxn] = {
      {0,1,0,0,1},
      {0,1,1,0,0},
      {1,0,0,0,0},
      {0,1,1,0,1},
      {0,0,0,0,0}
  };
  
  
  cout<< counting_subgrids(grid);
 
}