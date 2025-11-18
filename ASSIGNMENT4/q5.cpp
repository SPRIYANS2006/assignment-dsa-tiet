#include<iostream>
#include<stack>
#include<queue>
using namespace std;
class StackUsingOneQueue{
    queue<int> q1;
    public:
    void push(int x){
        int n = q1.size();
        q1.push(x);
        for (int i = 0; i < n; i++)
        {
            q1.push(q1.front());
            q1.pop();
        }  
    }
    int pop(){
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    int top(){
        if (q1.empty()) {
            cout << "Stack is empty!\n";
            return -1;
        }
        return q1.front();
    }
    bool isEmpty(){
        return q1.empty();
    }

};
class stackUsingTwoQueue{
    queue<int> q1,q2;
    public:
    void push(int x){
        while(!q1.empty()){
            q2.push(q1.front());
            q1.pop();
        }
        q1.push(x);
        while(!q2.empty()){
            q1.push(q2.front());
            q2.pop();
        }
    }
    int pop(){
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        int ans = q1.front();
        q1.pop();
        return ans;
    }
    int top(){
        if (q1.empty()) {
            cout << "Stack is empty\n";
            return -1;
        }
        return q1.front();
    }
    bool isEmpty(){
        return q1.empty();
    }
};
int main() {
    StackUsingOneQueue s1;
    stackUsingTwoQueue s;
    s.push(10);
    s.push(20);
    s.push(30);
    cout << "Top: " << s.top() << endl;    
    cout << "Pop: " << s.pop() << endl;    
    cout << "Top: " << s.top() << endl;    
    cout << "Empty: " << s.isEmpty() << endl; 
    s1.push(10);
    s1.push(20);
    s1.push(30);

    cout << "Top element: " << s1.top() << endl;
    s1.pop();
    cout << "Top element: " << s1.top() << endl;
    s1.pop();
    return 0;
}