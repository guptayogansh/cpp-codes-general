#include<bits/stdc++.h>
using namespace std;


int wt[]={1,3,3,5};
const int n = 4;
const int W = 12;

bool possible[n+1][W+1];

void solve(){
    
     possible[0][0] = true;

    for (int k = 1; k <= n; k++) {
       for (int x = 0; x <= W; x++) {
            if (x-wt[k-1] >= 0) possible[k][x] |= possible[k-1][x-wt[k-1]];
            possible[k][x] |= possible[k-1][x];
        }
    }
     
     for(int x=0;x<=n;x++){
      for(int k=0;k<=W;k++)
       cout<< possible[x][k]<<" ";
       
      cout<<"\n";
     }
     
     return;
}

int main(){
    
    solve();
}