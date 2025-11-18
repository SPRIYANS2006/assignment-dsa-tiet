#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int x){ data=x; left=right=NULL; }
};

Node* insertNode(Node* root, int x){
    if(!root) return new Node(x);
    if(x < root->data) root->left = insertNode(root->left, x);
    else root->right = insertNode(root->right, x);
    return root;
}

void preorder(Node* root){
    if(!root) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

void inorder(Node* root){
    if(!root) return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

void postorder(Node* root){
    if(!root) return;
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}

int main(){
    Node* root=NULL; 
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>x; root=insertNode(root,x); }
    preorder(root); cout<<endl;
    inorder(root); cout<<endl;
    postorder(root);
}
