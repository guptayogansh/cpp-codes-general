#include<bits/stdc++.h>
using namespace std;

int main(){

   set<int> s = {0,1,2};
   int n = s.size();
   for(int b=0;b<(1<<n);b++){
	   vector<int> subset;
	   for(int i=0;i<n;i++)
		   if(b&(1<<i)) subset.push_back(i);
	   for(auto it:subset)
		   cout<<it<<" ";
	   cout<<"\n";
   }
}
