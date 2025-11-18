#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
    Node(int x){ data = x; next = NULL; }
};

void push(Node*& head, int x){
    Node* n = new Node(x);
    n->next = head;
    head = n;
}

Node* reverseList(Node* head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr){
        Node* forwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = forwd;
    }
    return prev;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node* head = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for(int i = 0; i < n; i++){
        cin >> x;
        push(head, x);
    }

    cout << "Original List: ";
    print(head);

    head = reverseList(head);

    cout << "Reversed List: ";
    print(head);

    return 0;
}
