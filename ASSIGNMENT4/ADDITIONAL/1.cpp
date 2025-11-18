#include <iostream>
#include <queue>
using namespace std;

void generateBinary(int n) {
    queue<string> q;
    q.push("1"); 

    for (int i = 1; i <= n; i++) {
        string s = q.front();
        q.pop();

        cout << s << " "; // Print current binary number

        // Generate next numbers and push to queue
        q.push(s + "0");
        q.push(s + "1");
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Binary numbers from 1 to " << n << " are:\n";
    generateBinary(n);

    return 0;
}
