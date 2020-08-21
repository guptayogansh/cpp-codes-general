#include<bits/stdc++.h>
using namespace std;

int main(){
     vector<int> ar={0,1,2}, permutation;
     int n = ar.size();
	 for(int i=0;i<n;i++) permutation.push_back(i);
	 do{
		 for(auto it: permutation)
			 cout<<it<<" ";
		 cout<<"\n";
	 }while(next_permutation(permutation.begin(), permutation.end()));
}
