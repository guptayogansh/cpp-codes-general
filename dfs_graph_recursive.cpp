/*
pseudocode:

Visited = {}
n is a node and visited is an empty set
dfs(n)

for all n' E neighbours(n) do
  if n' not in Visited
    dfs(n')
  end if
end for
end function

*/

#include<bits/stdc++.h>
using namespace std;

class Graph{

    int v;
    list<int> *adj_list;
    void dfs_helper(int n, bool visited[]);

    public:
    Graph(int v);
    void add_edge(int u, int v);
    void dfs(int n);
};

Graph::Graph(int v){
    this->v = v;
    adj_list = new list<int>[v];
}

void Graph::add_edge(int u , int v){
    adj_list[u].push_back(v);
}



void Graph::dfs_helper(int n, bool visited[]){
    visited[n] = true;
    cout<<n << " ";

    for(auto i = adj_list[n].begin(); i!=adj_list[n].end();i++)
      if(!visited[*i])
        dfs_helper(*i, visited);
}
// I could've used a set but the find function in set would've had a complexity 
// of O(logn) and access a boolean array is constant time
void Graph::dfs(int n){

   bool *visited = new bool[v];
   for(int i=0;i<v;i++)
     visited[i] = false;

     dfs_helper(n, visited); /// This will not work in case of a disconnected graph.
   
}

int main(){

    Graph g(4); 
    g.add_edge(0, 1); 
    g.add_edge(0, 2); 
    g.add_edge(1, 2); 
    g.add_edge(2, 0); 
    g.add_edge(2, 3); 
    g.add_edge(3, 3); 
  
    cout << "Following is Depth First Traversal"
            " (starting from vertex 2) \n"; 
    g.dfs(2); 
    return 0; 

}