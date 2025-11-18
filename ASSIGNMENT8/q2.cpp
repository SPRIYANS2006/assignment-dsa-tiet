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

Node* searchRec(Node* root, int key){
    if(!root || root->data==key) return root;
    if(key < root->data) return searchRec(root->left,key);
    return searchRec(root->right,key);
}

Node* searchIter(Node* root, int key){
    while(root){
        if(key == root->data) return root;
        else if(key < root->data) root=root->left;
        else root=root->right;
    }
    return NULL;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* findMax(Node* root){
    while(root->right) root=root->right;
    return root;
}

Node* inorderSuccessor(Node* root, Node* x){
    if(x->right) return findMin(x->right);
    Node* succ=NULL;
    while(root){
        if(x->data < root->data){ succ=root; root=root->left; }
        else if(x->data > root->data) root=root->right;
        else break;
    }
    return succ;
}

Node* inorderPredecessor(Node* root, Node* x){
    if(x->left) return findMax(x->left);
    Node* pre=NULL;
    while(root){
        if(x->data > root->data){ pre=root; root=root->right; }
        else if(x->data < root->data) root=root->left;
        else break;
    }
    return pre;
}

int main(){
    Node* root=NULL;
    int n,x,key;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>x; root=insertNode(root,x); }

    cin>>key;
    Node* f = searchIter(root,key);
    if(f) cout<<"Found"<<endl; else cout<<"Not Found"<<endl;

    cout<<findMin(root)->data<<endl;
    cout<<findMax(root)->data<<endl;

    Node* s = inorderSuccessor(root, searchRec(root,key));
    Node* p = inorderPredecessor(root, searchRec(root,key));

    if(s) cout<<s->data<<endl; else cout<<"No successor"<<endl;
    if(p) cout<<p->data<<endl; else cout<<"No predecessor"<<endl;
}
