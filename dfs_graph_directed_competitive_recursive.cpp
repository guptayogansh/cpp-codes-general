#include<bits/stdc++.h>
using namespace std;


void add_edge(vector<int>adj_list[], int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}


void dfs_helper(int n, vector<int> adj_list[], vector<bool> &visited){
    visited[n] = true;
    cout<< n << " ";

    for(auto i=adj_list[n].begin();i!=adj_list[n].end();i++)
       if(!visited[*i])
         dfs_helper(*i, adj_list, visited);
}

void dfs(vector<int> adj_list[], int v ){

    vector<bool> visited(v, false);
    for(int n=0;n<v;n++)
      if(!visited[n])
        dfs_helper(n, adj_list, visited);
}

int main(){


     int v = 5;
     vector<int>adj_list[v]; // array of vectors

     add_edge(adj_list, 0, 1); 
    add_edge(adj_list, 0, 4); 
    add_edge(adj_list, 1, 2); 
    add_edge(adj_list, 1, 3); 
    add_edge(adj_list, 1, 4); 
    add_edge(adj_list, 2, 3); 
    add_edge(adj_list, 3, 4); 
    dfs(adj_list, v);

    return 0;
}

 
