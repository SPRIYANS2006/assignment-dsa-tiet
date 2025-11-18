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
        n->next = n; // circular
        return;
    }

    Node* t = head;
    while (t->next != head)
        t = t->next;

    t->next = n;
    n->next = head;
}

int sizeCLL(Node* head) {
    if (!head) return 0;

    int count = 0;
    Node* t = head;

    do {
        count++;
        t = t->next;
    } while (t != head);

    return count;
}

int main() {
    Node* head = NULL;
    int n, x;

    cout << "Enter number of nodes for CLL: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }

    cout << "Size of Circular Linked List: " << sizeCLL(head) << endl;

    return 0;
}
