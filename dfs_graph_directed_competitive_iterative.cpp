#include<bits/stdc++.h>
using namespace std;


void add_edge(vector<int>adj_list[], int u, int v){
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);
}


void dfs_helper(vector<int> adj_list[], int v , int n, vector<bool>& visited){

    stack<int> stack;

    stack.push(n);
    while(!stack.empty()){
        n = stack.top();
        stack.pop();

        if(!visited[n]){
            cout<< n << " ";
            visited[n] = true;
        }

        for(auto i= adj_list[n].begin();i!=adj_list[n].end();i++)
          if(!visited[*i])
            stack.push(*i);
    }

}

void dfs(int v, vector<int> adj_list[]){

      vector<bool> visited(v, false);   
    for (int i = 0; i < v; i++) 
        if (!visited[i]) 
            dfs_helper(adj_list,v,i, visited); 
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
    dfs(v, adj_list);

    return 0;
}

 
