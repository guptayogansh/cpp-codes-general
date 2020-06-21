#include<bits/stdc++.h>
using namespace std;

const int n = 5;
int value[][n] = {{3,7,9,2,7},{9,8,3,5,5}, {1,7,9,8,5}, {3,8,6,4,10},{6,3,9,7,8}};

int solve(){
  
  int sum[n][n];
  
  sum[0][0] = value[0][0];
  
  for(int x =1;x<n;x++)
    sum[0][x] = sum[0][x-1] + value[0][x];
    
 for(int y=1;y<n;y++)
    sum[y][0] = sum[y-1][0]+ value[y][0];
  
  
  for(int x=1;x<n;x++)
   for(int y=1;y<n;y++)
    sum[x][y] = max(sum[x-1][y], sum[x][y-1]) + value[x][y];
    
 return sum[n-1][n-1];
}

int main(){
    
    cout<<solve();
}