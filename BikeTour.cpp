#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ar array

int n;
int h;

vector<int> heights;


void solve() {
    int result=0;
	cin >> n;
    for(int i=0;i<n;i++){
        cin>>h;
        heights.push_back(h);
    }

    for(int i=1;i<=n-2;i++){
        if(heights[i-1]<heights[i] && heights[i+1]<heights[i])
           result++;
    }
   heights.clear();
   cout<<result<<"\n";
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