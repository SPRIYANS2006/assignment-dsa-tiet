#include<iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class List{
    Node* head;
    Node* tail;

public:
    List(){
        head = tail = NULL;
    }

    void push_front(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        newNode->next = head;
        head = newNode;
    }

    void push_back(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = tail = newNode;
            return;
        }
        tail->next = newNode;
        tail = newNode;
    }

    void insertBefore(int val, int target){
        if(head == NULL) return;

        if(head->data == target){
            push_front(val);
            return;
        }

        Node* temp = head;
        while(temp->next && temp->next->data != target)
            temp = temp->next;

        if(temp->next == NULL){
            cout << "Value not found!\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;
    }

    void insertAfter(int val, int target){
        Node* temp = head;
        while(temp && temp->data != target)
            temp = temp->next;

        if(temp == NULL){
            cout << "Value not found!\n";
            return;
        }

        Node* newNode = new Node(val);
        newNode->next = temp->next;
        temp->next = newNode;

        if(temp == tail)
            tail = newNode;
    }

    void pop_front(){
        if(head == NULL) return;

        Node* temp = head;
        head = head->next;

        if(head == NULL) tail = NULL;

        delete temp;
    }

    void pop_back(){
        if(head == NULL) return;

        if(head->next == NULL){
            delete head;
            head = tail = NULL;
            return;
        }

        Node* temp = head;
        while(temp->next != tail)
            temp = temp->next;

        delete tail;
        tail = temp;
        tail->next = NULL;
    }

    void deleteValue(int key){
        if(head == NULL) return;

        if(head->data == key){
            pop_front();
            return;
        }

        Node* temp = head;
        while(temp->next && temp->next->data != key)
            temp = temp->next;

        if(temp->next == NULL){
            cout << "Value not found!\n";
            return;
        }

        Node* del = temp->next;
        temp->next = del->next;

        if(del == tail)
            tail = temp;

        delete del;
    }

    int search(int key){
        Node* temp = head;
        int idx = 0;

        while(temp){
            if(temp->data == key)
                return idx;
            temp = temp->next;
            idx++;
        }
        return -1;
    }

    void printll(){
        Node* temp = head;
        while(temp){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main(){
    List ll;
    int choice, x, val, target;

    while(true){
        cout << "\n--- MENU ---\n";
        cout << "1. Insert at Beginning\n";
        cout << "2. Insert at End\n";
        cout << "3. Insert BEFORE a value\n";
        cout << "4. Insert AFTER a value\n";
        cout << "5. Delete from Beginning\n";
        cout << "6. Delete from End\n";
        cout << "7. Delete Specific Value\n";
        cout << "8. Search Value\n";
        cout << "9. Display List\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch(choice){
            case 1:
                cout << "Enter value: ";
                cin >> x;
                ll.push_front(x);
                break;

            case 2:
                cout << "Enter value: ";
                cin >> x;
                ll.push_back(x);
                break;

            case 3:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert before which value? ";
                cin >> target;
                ll.insertBefore(val, target);
                break;

            case 4:
                cout << "Enter value to insert: ";
                cin >> val;
                cout << "Insert after which value? ";
                cin >> target;
                ll.insertAfter(val, target);
                break;

            case 5:
                ll.pop_front();
                break;

            case 6:
                ll.pop_back();
                break;

            case 7:
                cout << "Enter value to delete: ";
                cin >> x;
                ll.deleteValue(x);
                break;

            case 8:
                cout << "Enter value to search: ";
                cin >> x;
                cout << "Found at index: " << ll.search(x) << endl;
                break;

            case 9:
                ll.printll();
                break;

            case 10:
                return 0;

            default:
                cout << "Invalid choice!\n";
        }
    }
}
