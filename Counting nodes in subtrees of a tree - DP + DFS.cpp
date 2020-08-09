#include<bits/stdc++.h>
using namespace std;

const int mxN = 10;
vector<int> adj[mxN+1];

int ct[mxN+1];

void dfs(int s,int e){
    ct[s]=1;
    for(auto u:adj[s]){
        if(u==e) continue;
        dfs(u,s);
        ct[s]+=ct[u];
    }
}

int main(){
    
    int a,b,n;
    cin>>n;
    while(n--){
        cin>>a>>b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    dfs(1,0);
    
    for(auto it:ct)
        cout<<it<<" "; 
}
