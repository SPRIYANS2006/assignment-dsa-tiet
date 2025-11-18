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

int findMiddle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow->data;
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

    cout << "Middle element: " << findMiddle(head);

    return 0;
}
