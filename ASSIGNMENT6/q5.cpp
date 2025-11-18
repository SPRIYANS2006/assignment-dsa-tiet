#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int x) { data = x; next = NULL; }
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
}

bool isCircular(Node* head) {
    if (!head) return false;

    Node* t = head->next;

    while (t && t != head)
        t = t->next;

    return (t == head);
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

    int makeCircular;
    cout << "Enter 1 to make it circular, 0 to keep normal: ";
    cin >> makeCircular;

    if (makeCircular == 1) {
        Node* t = head;
        while (t->next)
            t = t->next;
        t->next = head; // make circular
    }

    cout << (isCircular(head) ? "True" : "False");

    return 0;
}
