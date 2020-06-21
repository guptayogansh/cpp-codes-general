#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array
#define mod 1e9+7
 
int n;
ll d,x;
vector<ll> xvalues;

list<int> solutions;

void solve() {
  cin>>n>>d;
  for(int i=0;i<n;i++){
      cin>>x;
      xvalues.push_back(x);
  }
  
  for(ll i=xvalues.size()-1;i>=0;i--){
    d = d-d % xvalues[i];
    xvalues[i] = d;
  }
  cout<<xvalues[0]<<"\n";  
  xvalues.clear();
 }

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t, i=1;
	cin >> t;
	while(t--) {
		cout << "Case #" << i << ": ";
		solve();
		++i;
	}
}