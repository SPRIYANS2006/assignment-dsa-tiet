// Develop a menu driven program demonstrating the following operations on Circular Queues:
// enqueue(), dequeue(), isEmpty(), isFull(), display(), and peek().
#include <iostream>
using namespace std;

#define SIZE 5 

class CircularQueue {
private:
    int arr[SIZE];
    int front, rear;

public:
    CircularQueue() {
        front = -1;
        rear = -1;
    }
    bool isEmpty() {
        return front == -1;
    }
    bool isFull() {
        return (front == (rear + 1) % SIZE);
    }
    void enqueue(int x) {
        if (isFull()) {
            cout << "Queue is full!\n";
            return;
        }
        if (isEmpty()) {
            front = 0;
        }
        rear = (rear + 1) % SIZE;
        arr[rear] = x;
        cout << x << " enqueued.\n";
    }
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << arr[front] << " dequeued.\n";
        if (front == rear) {
            front = rear = -1;
        } else {
            front = (front + 1) % SIZE;
        }
    }
    void display() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
            return;
        }
        cout << "Queue elements: ";
        int i = front;
        while (true) {
            cout << arr[i] << " ";
            if (i == rear) break;
            i = (i + 1) % SIZE;
        }
        cout << endl;
    }

    
    void peek() {
        if (isEmpty()) {
            cout << "Queue is empty!\n";
        } else {
            cout << "Front element: " << arr[front] << endl;
        }
    }
};

int main() {
    CircularQueue q;
    int choice, value;

    do {
        cout << "\n--- Circular Queue Menu ---\n";
        cout << "1. Enqueue\n";
        cout << "2. Dequeue\n";
        cout << "3. Display\n";
        cout << "4. Peek\n";
        cout << "5. Check if Empty\n";
        cout << "6. Check if Full\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter value to enqueue: ";
                cin >> value;
                q.enqueue(value);
                break;
            case 2:
                q.dequeue();
                break;
            case 3:
                q.display();
                break;
            case 4:
                q.peek();
                break;
            case 5:
                if (q.isEmpty()) cout << "Queue is empty.\n";
                else cout << "Queue is not empty.\n";
                break;
            case 6:
                if (q.isFull()) cout << "Queue is full.\n";
                else cout << "Queue is not full.\n";
                break;
            case 0:
                cout << "Exiting program.\n";
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
