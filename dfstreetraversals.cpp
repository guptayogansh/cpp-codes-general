#include<bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

// The action defined is just simple printing for a node
void PreOrder(Node *root){
   cout<< root -> data<< " ";
   if(root ->left!= NULL) PreOrder(root->left);
   if(root -> right!= NULL) PreOrder(root->right); 
}

void InOrder(Node *root){
    if(root->left!=NULL) InOrder(root->left);
    cout<<root -> data<<" ";
    if(root->right!=NULL) InOrder(root->right);
}

void PostOrder(Node *root){
    if(root->left!=NULL) PostOrder(root->left);
    if(root->right!=NULL) PostOrder(root->right);
    cout<<root->data<<" ";
}


struct Node* create(){

    int x;
    struct Node *newnode;
    newnode = new Node;

    cout<<"Enter data (-1 for no node): ";
    cin>>x;
    if(x==-1)
     return 0;

    newnode->data = x;
    cout<< "Enter left child of " << x<<": ";
    newnode->left = create();
    cout<< "Enter right child of "<<x<<": ";
    newnode->right = create();

    return newnode;

}
int main(){

 Node *root;

 root = create();

cout<< "PreOrder: ";
 PreOrder(root);

cout<<"\nInOrder: ";
InOrder(root);

cout<<"\nPostOrder: ";
PostOrder(root);

return 0;

}