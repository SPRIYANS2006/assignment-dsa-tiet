#include<iostream>
#include<queue>
using namespace std;

queue<int> interleave(queue<int> q) {
    int n = q.size();
    int half = n / 2;
    queue<int> temp;
    for (int i = 0; i < half; i++) {
        temp.push(q.front());
        q.pop();
    }
    while (!temp.empty()) {
        q.push(temp.front());
        temp.pop();

        q.push(q.front());
        q.pop();
    }

    return q;
}

int main() {
    queue<int> q;
    int arr[6] = {4, 7, 11, 20, 5, 9};
    int n = 6;

    for (int i = 0; i < n; i++) {
        q.push(arr[i]);
    }
    q = interleave(q); 
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }

    return 0;
}
