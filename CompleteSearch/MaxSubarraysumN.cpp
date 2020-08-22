#include<bits/stdc++.h>
using namespace std;

int main(){
   int ar[]={-1,2,4,-3,5,2,-5,2}, best=0, sum=0;
   int n = sizeof(ar)/sizeof(ar[0]);
   for(int k=0;k<n;k++)
	   sum = max(ar[k],sum+ar[k]), best = max(best, sum);
   cout<<best;
}
