#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) {
        data = x;
        next = NULL;
    }
};

void insertEnd(Node*& head, int x) {
    Node* n = new Node(x);

    if (!head) {
        head = n;
        n->next = head;
        return;
    }

    Node* t = head;
    while (t->next != head)
        t = t->next;

    t->next = n;
    n->next = head;
}

void displayCLL(Node* head) {
    if (!head) return;

    Node* t = head;
    do {
        cout << t->data << " ";
        t = t->next;
    } while (t != head);

    cout << head->data; 
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, x;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Circular List: ";
    displayCLL(head);

    return 0;
}
