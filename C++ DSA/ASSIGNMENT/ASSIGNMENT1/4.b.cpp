#include <iostream>
using namespace std;

const int MAX = 100;

void inputMatrix(int A[][MAX], int B[][MAX], int m, int n, int p) {
    cout << "Enter elements of Matrix A (" << m << " x " << n << "):\n";
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> A[i][j];

    cout << "Enter elements of Matrix B (" << n << " x " << p << "):\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < p; j++)
            cin >> B[i][j];
}

void multiplyMatrix(int A[][MAX], int B[][MAX], int C[][MAX], int m, int n, int p) {
   
    for (int i = 0; i < m; i++){
        for (int j = 0; j < p; j++){
            C[i][j]= 0;
            for (int k = 0; k < n; k++){
                C[i][j] += A[i][k] * B[k][j];
        }}}
}

void printMatrix(int A[][MAX], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            cout << A[i][j] << " ";
        cout << endl;
    }
}

int main() {
    int m, n, p;

    cout << "Enter rows and columns of Matrix A: ";
    cin >> m >> n;

    cout << "Enter number of columns of Matrix B: ";
    cin >> p;

    int A[MAX][MAX], B[MAX][MAX], C[MAX][MAX];

    inputMatrix(A, B, m, n, p);
    multiplyMatrix(A, B, C, m, n, p);
   cout << "\nMatrix A:\n";
    printMatrix(A, m, n);

    cout << "\nMatrix B:\n";
    printMatrix(B, n, p);

    cout << "\nMatrix C (Result of A x B):\n";
    printMatrix(C, m, p);
    

    return 0;
}
