#include <iostream>
#include <queue>
#include <stack>
using namespace std;

bool canSortQueue(queue<int> q1, int n) {
    stack<int> s;
    queue<int> q2;
    int expected = 1;
 
    while (!q1.empty() || !s.empty()) {
        if (!q1.empty() && q1.front() == expected) {
            q1.pop();
            q2.push(expected);
            expected++;
        } else if (!s.empty() && s.top() == expected) {
            s.pop();
            q2.push(expected);
            expected++;
        } else if (!q1.empty()) {
            s.push(q1.front());
            q1.pop();
        } else {
           
            return false;
        }
    }

    return true;
}

int main() {
    queue<int> q;
    int arr[] = {5, 1, 2, 3,4};
    int n = 5;

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }

    if (canSortQueue(q, n)) {
        cout << "Yes, queue can be sorted using a stack.\n";
    } else {
        cout << "No, queue cannot be sorted using a stack.\n";
    }

    return 0;
}
