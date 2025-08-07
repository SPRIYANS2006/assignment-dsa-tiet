#include<iostream>
using namespace std;

const int maxSize = 100;

void inputarray(int arr1[][maxSize], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr1[i][j];
        }
    }
}

void transposematrix(int arr1[][maxSize], int arr2[][maxSize], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            arr2[j][i] = arr1[i][j];
        }
    }
}

void printarray(int arr[][maxSize], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns of the matrix: ";
    cin >> rows >> cols;

    if (rows > maxSize || cols > maxSize) {
        cout << "Matrix size exceeds allowed limit." << endl;
        return 1;
    }

    int arr1[maxSize][maxSize], arr2[maxSize][maxSize];

    inputarray(arr1, rows, cols);
    transposematrix(arr1, arr2, rows, cols);    
    cout << "Transposed matrix: " << endl;
    printarray(arr2, cols, rows);

    return 0;
}
