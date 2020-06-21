#include<bits/stdc++.h>
#define n 7

using namespace std;

vector<int> g[n];
vector<int> gt[n];

vector<int> in_order;
vector<int> component;

vector<bool> visited1(n,false);
vector<bool> visited2(n, false);

void addedge(int u, int v){
 g[u].push_back(v);
 gt[v].push_back(u);
}

void dfs1(int x){

    visited1[x] = true;

    for(auto i: g[x])
     if(!visited1[i])
      dfs1(i);
    in_order.push_back(x);
}


void dfs2(int x){
    visited2[x] = true;
    component.push_back(x);
    for(auto i:gt[x])
      if(!visited2[i])
        dfs2(i);
}


int main(){


    addedge(1,2);
    addedge(2,1);
    addedge(1,4);
    addedge(2,5);
    addedge(3,2);
    addedge(6,5);
    addedge(6,3);
    addedge(3,7);
    addedge(7,6);

     for(int i=1;i<= n;i++)
      if(!visited1[i])
        dfs1(i);


     for(int i=1;i<=n;++i){
       int x = in_order[n-i];
       if(!visited2[x])
       {
           dfs2(x);
           for(auto i: component)
             cout<<i<<" ";
           cout<<"\n";
           component.clear();
       }
       
     }
    return 0;
}