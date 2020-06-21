#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left, *right;
};

//error!!!!!!! -  Will see later
void bfs(Node *root){

    queue<int> q;

    q.push(root->data);
    while(!q.empty()){
       int n = q.front();
       q.pop();
       cout<< n <<" ";
       if(root->left!=NULL) bfs(root->left);
       if(root->right!=NULL) bfs(root->right);
    }
}

struct Node *create(){

  int x;
    Node *newnode = new Node;

    cout<<"Enter data(-1 for no node): ";
    cin>> x;
    if(x==-1)
      return 0;
    newnode->data = x;
    cout<<"Enter left child for "<< x <<": ";
    newnode->left = create();
    cout<<"Enter right child for "<< x <<": ";
    newnode->right = create();

    return newnode;
}

int main(){

    Node *root ;
    root = create();

    cout<<" BFS traversal: ";

    bfs(root);
    
    return 0;
}