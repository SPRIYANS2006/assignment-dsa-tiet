#include <iostream>
#include <queue>
using namespace std;

class Solution {
public:
    int countStudents(int students[], int sandwiches[], int n) {
        queue<int> q;

       
        for (int i = 0; i < n; i++) {
            q.push(students[i]);
        }

        int idx = 0;

        while (!q.empty()) {
            int size = q.size();
            bool someoneAte = false;

            for (int i = 0; i < size; i++) {
                int student = q.front();
                q.pop();

                if (student == sandwiches[idx]) {
                    idx++;
                    someoneAte = true;
                    break;
                } else {
                    q.push(student);
                }
            }

            if (!someoneAte) {
                break;
            }
        }

        return q.size(); 
    }
};

int main() {
    int students[4] = {1, 1, 0, 0};
    int sandwiches[4] = {0, 1, 0, 1};

    Solution s;
    int unableToEat = s.countStudents(students, sandwiches, 4);

    cout << "Students unable to eat: " << unableToEat << endl;

    return 0;
}
