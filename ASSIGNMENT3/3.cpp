
// Write a program that checks if an expression has balanced parentheses.
// time complexity O(n)
// space complexity O(n)
#include <iostream>
#include <stack>
using namespace std;

bool isBalanced(string str) {
    stack<char> s;
    for(int i=0 ;i< str.length(); i++){
        char c = str[i];
        if (c == '(' || c == '{' || c == '[')
            s.push(c);
        else if (c == ')' || c == '}' || c == ']') {
            if (s.empty()) return false;
            char top = s.top(); 
            s.pop();
            if ((c == ')' && top != '(') ||
                (c == '}' && top != '{') ||
                (c == ']' && top != '['))
                return false;
        }
    }
    return s.empty();
}

int main() {
    string str;
    cout << "Enter expression: ";
    cin >> str;

    cout << (isBalanced(str) ? "Balanced" : "Not Balanced") << endl;
    return 0;
}
