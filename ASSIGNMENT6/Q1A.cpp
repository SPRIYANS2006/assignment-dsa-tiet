#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;
    Node* prev;

    Node(int x) {
        data = x;
        next = prev = NULL;
    }
};

class DoublyLinkedList {
public:
    Node* head;

    DoublyLinkedList() { head = NULL; }

    void insertFront(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        n->next = head;
        head->prev = n;
        head = n;
    }


    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) { head = n; return; }
        Node* t = head;
        while (t->next) t = t->next;
        t->next = n;
        n->prev = t;
    }

 
    void insertBefore(int x, int target) {
        if (!head) return;

        if (head->data == target) {
            insertFront(x);
            return;
        }

        Node* t = head;
        while (t && t->data != target) t = t->next;

        if (!t) { cout << "Value not found\n"; return; }

        Node* n = new Node(x);
        n->next = t;
        n->prev = t->prev;
        t->prev->next = n;
        t->prev = n;
    }


    void insertAfter(int x, int target) {
        Node* t = head;
        while (t && t->data != target) t = t->next;

        if (!t) { cout << "Value not found\n"; return; }

        Node* n = new Node(x);
        n->next = t->next;
        n->prev = t;

        if (t->next) t->next->prev = n;
        t->next = n;
    }


    void deleteValue(int x) {
        if (!head) return;

        Node* t = head;

        while (t && t->data != x) t = t->next;

        if (!t) { cout << "Value not found\n"; return; }

        if (t->prev) t->prev->next = t->next;
        else head = t->next; 

        if (t->next) t->next->prev = t->prev;

        delete t;
    }

    int search(int x) {
        Node* t = head;
        int i = 0;
        while (t) {
            if (t->data == x) return i;
            t = t->next;
            i++;
        }
        return -1;
    }

    void print() {
        Node* t = head;
        while (t) {
            cout << t->data << " ";
            t = t->next;
        }
        cout << endl;
    }
};


int main() {
    DoublyLinkedList d;
    int ch, x, target;

    while (true) {
        cout << "1. Insert at Front\n2. Insert at End\n3. Insert Before Value\n";
        cout << "4. Insert After Value\n5. Delete Value\n6. Search\n7. Display\n8. Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: cin >> x; d.insertFront(x); break;
            case 2: cin >> x; d.insertEnd(x); break;
            case 3: cin >> x >> target; d.insertBefore(x, target); break;
            case 4: cin >> x >> target; d.insertAfter(x, target); break;
            case 5: cin >> x; d.deleteValue(x); break;
            case 6: cin >> x; cout << d.search(x) << endl; break;
            case 7: d.print(); break;
            case 8: return 0;
        }
    }
}
