#include<bits/stdc++.h>
using namespace std;


int main(){
	int ar[] ={-1,2,4,-3,5,2,-5,2}, best=0;
	int n = sizeof(ar)/sizeof(ar[0]);
	for(int a=0;a<n;a++){
		for(int b=a;b<n;b++){
			int sum=0;
			for(int k=a;k<=b;k++){
				sum+=ar[k];
			}
			best = max(best,sum);
		}	
	}
	cout<<best;
}
