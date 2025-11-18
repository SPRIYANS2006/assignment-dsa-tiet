 #include <iostream>
using namespace std;

class Node {
public:
    char data;
    Node* next;
    Node* prev;

    Node(char x) {
        data = x;
        next = prev = NULL;
    }
};

void insertEnd(Node*& head, char x) {
    Node* n = new Node(x);

    if (!head) {
        head = n;
        return;
    }

    Node* t = head;
    while (t->next) t = t->next;

    t->next = n;
    n->prev = t;
}

bool isPalindrome(Node* head) {
    if (!head) return true;

    Node* left = head;
    Node* right = head;

    while (right->next)
        right = right->next;

    while (left != right && right->next != left) {
        if (left->data != right->data)
            return false;

        left = left->next;
        right = right->prev;
    }
    return true;
}

int main() {
    Node* head = NULL;
    int n;
    char x;

    cout << "Enter number of characters: ";
    cin >> n;

    cout << "Enter characters: ";
    for (int i = 0; i < n; i++) {
        cin >> x;
        insertEnd(head, x);
    }

    if (isPalindrome(head))
        cout << "True";
    else
        cout << "False";

    return 0;
}
