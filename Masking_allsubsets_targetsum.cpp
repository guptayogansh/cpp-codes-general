#include<bits/stdc++.h>
using namespace std;

int main(){
    
 int a[] = {1,2,3,4,5,6};
 
 int target = 8;
 
 int n = 6;
 
 for(int mask =0; mask<(1<<n);mask++)
 {
     int sum = 0;
     
     for(int i=0;i<n;i++)
      if(mask&(1<<i))
        sum += a[i];
        
     if(sum==target)
      cout<<"YES"<<"\n";
     else
       cout<<"NO"<<"\n";
 }
  
}