#include <iostream>
#include <queue>
using namespace std;

void firstNonRepeating(string str)
{
    queue<char> q;

    for (int i=0; i< str.length();i++)
    {
        char ch = str[i];
        int size = q.size();
        bool found = false;

        queue<char> temp;
        while (!q.empty())
        {
            if (q.front() == ch)
            {
                found = true;
            }
            else
            {
                temp.push(q.front());
            }
            q.pop();
        }

        q = temp;

        if (!found)
        {
            q.push(ch);
        }

        if (!q.empty())
        {
            cout << q.front() << " ";
        }
        else
        {
            cout << "-1 ";
        }
    }
    cout << endl;
}

int main()
{
    string str;
    cout << "Enter string (no spaces): ";
    cin >> str;

    cout << "First non-repeating characters: ";
    firstNonRepeating(str);

    return 0;
}
