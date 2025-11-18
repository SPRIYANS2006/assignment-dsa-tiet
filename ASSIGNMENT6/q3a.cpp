#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* prev;
    Node* next;

    Node(int x) {
        data = x;
        prev = next = NULL;
    }
};

void insertEnd(Node*& head, int x) {
    Node* n = new Node(x);
    if (!head) {
        head = n;
        return;
    }
    Node* t = head;
    while (t->next)
        t = t->next;

    t->next = n;
    n->prev = t;
}

int sizeDLL(Node* head) {
    int count = 0;
    Node* t = head;
    while (t) {
        count++;
        t = t->next;
    }
    return count;
}

int main() {
    Node* head = NULL;
    int n, x;

    cout << "Enter number of nodes for DLL: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Size of Doubly Linked List: " << sizeDLL(head) << endl;

    return 0;
}
