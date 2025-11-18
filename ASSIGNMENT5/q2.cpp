#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node(int val) { data = val; next = NULL; }
};

void push_back(Node*& head, int val) {
    Node* n = new Node(val);
    if (!head) { head = n; return; }
    Node* t = head;
    while (t->next) t = t->next;
    t->next = n;
}

int countOccurrences(Node* head, int key) {
    int cnt = 0;
    while (head) {
        if (head->data == key) cnt++;
        head = head->next;
    }
    return cnt;
}

Node* deleteAll(Node* head, int key) {
    while (head && head->data == key) {
        Node* t = head;
        head = head->next;
        delete t;
    }

    Node* p = head;
    while (p && p->next) {
        if (p->next->data == key) {
            Node* t = p->next;
            p->next = p->next->next;
            delete t;
        } else {
            p = p->next;
        }
    }
    return head;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {
    Node* head = NULL;
    int n, x, key;

    cout << "Enter number of nodes: ";
    cin >> n;

    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        push_back(head, x);
    }

    cout << "Enter key to delete: ";
    cin >> key;

    int count = countOccurrences(head, key);
    cout << "Count: " << count << endl;

    head = deleteAll(head, key);

    cout << "Updated List: ";
    printList(head);

    return 0;
}
