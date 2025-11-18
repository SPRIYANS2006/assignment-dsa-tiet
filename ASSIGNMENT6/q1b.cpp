#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node(int x) { data = x; next = NULL; }
};

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() { head = NULL; }


    void insertFront(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = n; 
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;

        n->next = head;
        t->next = n;
        head = n;
    }

    void insertEnd(int x) {
        Node* n = new Node(x);
        if (!head) {
            head = n;
            n->next = n;
            return;
        }
        Node* t = head;
        while (t->next != head) t = t->next;
        t->next = n;
        n->next = head;
    }

    void insertBefore(int x, int target) {
        if (!head) return;

        if (head->data == target) {
            insertFront(x);
            return;
        }

        Node* t = head;
        while (t->next != head && t->next->data != target)
            t = t->next;

        if (t->next == head) { cout << "Not found\n"; return; }

        Node* n = new Node(x);
        n->next = t->next;
        t->next = n;
    }

    void insertAfter(int x, int target) {
        if (!head) return;

        Node* t = head;
        do {
            if (t->data == target) {
                Node* n = new Node(x);
                n->next = t->next;
                t->next = n;
                return;
            }
            t = t->next;
        } while (t != head);

        cout << "Not found\n";
    }


    void deleteValue(int x) {
        if (!head) return;

        Node* t = head;
        Node* prev = NULL;


        if (head->data == x) {
            if (head->next == head) { delete head; head = NULL; return; }

            Node* last = head;
            while (last->next != head) last = last->next;

            last->next = head->next;
            Node* temp = head;
            head = head->next;
            delete temp;
            return;
        }

        do {
            prev = t;
            t = t->next;
        } while (t != head && t->data != x);

        if (t == head) { cout << "Not found\n"; return; }

        prev->next = t->next;
        delete t;
    }

    int search(int x) {
        if (!head) return -1;

        Node* t = head;
        int idx = 0;

        do {
            if (t->data == x) return idx;
            t = t->next;
            idx++;
        } while (t != head);

        return -1;
    }

    void print() {
        if (!head) return;

        Node* t = head;
        do {
            cout << t->data << " ";
            t = t->next;
        } while (t != head);

        cout << endl;
    }
};

int main() {
    CircularLinkedList c;
    int ch, x, target;

    while (true) {
        cout << "\n--- CIRCULAR LINKED LIST MENU ---\n";
        cout << "1. Insert at Front\n2. Insert at End\n3. Insert Before\n";
        cout << "4. Insert After\n5. Delete\n6. Search\n7. Display\n8. Exit\n";

        cin >> ch;

        switch (ch) {
            case 1: cin >> x; c.insertFront(x); break;
            case 2: cin >> x; c.insertEnd(x); break;
            case 3: cin >> x >> target; c.insertBefore(x, target); break;
            case 4: cin >> x >> target; c.insertAfter(x, target); break;
            case 5: cin >> x; c.deleteValue(x); break;
            case 6: cin >> x; cout << c.search(x) << endl; break;
            case 7: c.print(); break;
            case 8: return 0;
        }
    }
}
