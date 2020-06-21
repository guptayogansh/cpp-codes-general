#include<bits/stdc++.h>
using namespace std;

int arr[8] = {6,2,5,1,7,4,8,3};
int length[8];
const int n = 8;

int solve(){
    
    for(int x=0;x<n;x++)
    {
        length[x] = 1;
        for(int i=0;i<x;i++)
          if(arr[i]<arr[x])
           length[x] = max(length[x], length[i]+1);
    }
    
    
    for(auto c: length)
     cout<< c<<" ";
    return length[n-1];
    
}

int main(){
    
    cout<<solve();
}