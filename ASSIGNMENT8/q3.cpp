#include <iostream>
#include <algorithm>
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
    else if(x > root->data) root->right=insertNode(root->right,x);
    return root;
}

Node* findMin(Node* root){
    while(root->left) root=root->left;
    return root;
}

Node* DeleteFromBST(Node* root, int val){
    // base case
    if(root == NULL){
        return root;
    }
    if(root->data == val){
         // 0 child
         if(root->left == NULL && root->right == NULL){
            delete  root;
            return NULL;
         }

         // 1 child 

         // left child 
         if(root->right == NULL && root->left !=NULL){
            Node* temp = root->left;
            delete root;
            return temp;
         }
         // right child

         if(root->right != NULL && root->left == NULL){
            Node* temp = root->right;
            delete root;
            return temp;
         }
         // 2 child
         if(root->right != NULL && root->left != NULL){
            int mini = minValue(root->right)-
            >data;
            root->data = mini;
            root->right = DeleteFromBST(root->right,mini);
            return root;
         }
    }
    else if(root->data> val){
        root->left = DeleteFromBST(root->left, val);

    }
    else{
        root->right = DeleteFromBST(root->right,val);
    }


}

int maxDepth(Node* root){
    if(!root) return 0;
    return 1 + max(maxDepth(root->left), maxDepth(root->right));
}

int minDepth(Node* root){
    if(!root) return 0;
    if(!root->left) return 1 + minDepth(root->right);
    if(!root->right) return 1 + minDepth(root->left);
    return 1 + min(minDepth(root->left), minDepth(root->right));
}

int main(){
    Node* root=NULL;
    int n,x,d;
    cin>>n;
    for(int i=0;i<n;i++){ cin>>x; root=insertNode(root,x); }

    cin>>d;
    root = DeleteFromBST(root,d);

    cout<<maxDepth(root)<<endl;
    cout<<minDepth(root)<<endl;
}
