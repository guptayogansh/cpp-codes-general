#include<bits/stdc++.h>
using namespace std;

int wt[]={1,3,3,5};
const int n = 4;
const int W = 12;

bool possible[W+1];

void solve(){
    
   
     possible[0] = true;
     for (int k = 1; k <= n; k++) {
        for (int x = W; x >= 0; x--) {
           if (possible[x]) possible[x+wt[k-1]] = true;
         }
     }
    
    for(int i=0;i<=W;i++)
     cout<< possible[i]<<" ";
     
     return;
}

int main(){
    
    solve();
}