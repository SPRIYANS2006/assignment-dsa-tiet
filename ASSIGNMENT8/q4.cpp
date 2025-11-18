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
    if(x < root->data) root->left=insertNode(root->left,x);
    else root->right=insertNode(root->right,x);
    return root;
}

bool isBSTUtil(Node* root, int minv, int maxv){
    if(!root) return true;
    if(root->data <= minv || root->data >= maxv) return false;
    return isBSTUtil(root->left,minv,root->data) &&
           isBSTUtil(root->right,root->data,maxv);
}

bool isBST(Node* root){
    return isBSTUtil(root,-1000000,1000000);
}

int main(){
    Node* root=NULL;
    int n,x;
    cin>>n;
    for(int i=0;i<n;i++){
        cin>>x;
        root=insertNode(root,x);
    }
    cout<<(isBST(root) ? "Yes" : "No");
}
