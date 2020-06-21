#include<bits/stdc++.h>
#define ll long long
#define mod 1e9+7
using namespace std;

int n,k,p;

void solve() {
  cin>>n>>k>>p;
   int values[n][k] ;
   for(int i=0;i<n;i++)
      for(int j=0;j<k;j++)
        cin>>values[i][j];
    
   int sum [n+1][k+1];


   for(int i=0;i<=n;i++)
     sum[i][0] = 0;
    
  for(int j=0;j<=p;j++)
     sum[0][j] = 0;

   for(int i=1;i<=n;i++){
       for(int j=1;j<=k;j++)
         sum[i][j] = sum[i][j-1] + values[i-1][j-1];
   }

   int dp[n+1][p+1];

   for(int i=0;i<=n;i++)
     dp[i][0] = 0;
    
  for(int j=0;j<=p;j++)
     dp[0][j] = 0;
    
   for(int i=1;i<=n;i++){
       for(int j=1;j<=p;j++){
           dp[i][j]=0;
           for(int x=0;x<=min(j,k);x++)
             dp[i][j] = max(dp[i][j], dp[i-1][j-x] + sum[i][x]);
       }
   }
  cout<<dp[n][p]<<"\n";
}


int main(){

   ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i=1;
	cin >> t;
	while(t--) {
		cout << "Case #" << i << ": ";
		solve();
		++i;
	}