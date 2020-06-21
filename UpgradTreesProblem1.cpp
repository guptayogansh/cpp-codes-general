//Ques: You are given a binary tree and a node, find the path from that node to the root node,
// and print all the nodes present in that path.


#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};


bool Path_check(Node *root, vector<int>& ar, int y){
    
    ar.push_back(root->data);

    if(root->data == y)
      return true;
    
    if(Path_check(root->left, ar, y) || Path_check(root->right, ar, y))
      return true;

    ar.pop_back();
    return false;
}

struct Node* create(){

    int x;
    struct Node *newnode = new Node;

    cout<<"Enter data(-1 for no node):";
    cin>>x;
    if(x==-1)
     return 0;

    newnode->data = x;
    cout<<"Enter left child of "<<x<<": ";
    newnode->left = create();
    cout<<"Enter right child of "<<x<<": ";
    newnode->right = create();

    return newnode;
}

int main(){

  Node *root = new Node;

  root = create();

  int y;

  cout<<"Enter the node to be found: ";
  cin>> y;

  vector<int> ar;

  if(Path_check(root, ar, y)){

    cout<<"Path of y till root: ";
      for(auto it=ar.end()-1;it>=ar.begin();it--)
          cout<< *it<<" ";
  }
    return 0;
}