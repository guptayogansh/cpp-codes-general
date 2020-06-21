#include<bits/stdc++.h>
#define V 4
using namespace std;


vector<int> adj[V+1];
int ct = 0;

bool visited[V+1] ={0};
void addedge(int u, int v){
    adj[u].push_back(v);
    adj[v].push_back(u);
}

void dfs(int n){
    if(visited[n]) return;
    visited[n] = true;
    for(auto nd:adj[n]) 
       dfs(nd);
}

void count_comp(){
    for(int n=1;n<=V;n++)
     if(!visited[n])
      dfs(n), ct++;
      
    cout<<ct;
}

 int main(){
     
     addedge(1, 0); 
    addedge(2, 3); 
    addedge(3, 4);
     
     count_comp();
     
 }