#include<iostream>
using namespace std;

const int maxSize = 100;

void inputArray(int arr[][maxSize], int rows, int cols) {
    cout << "Enter the elements of the matrix:" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cin >> arr[i][j];
        }
    }
}

void sumRows(int arr[][maxSize], int rows, int cols) {
    cout << "\nSum of each row:" << endl;
    for (int i = 0; i < rows; i++) {
        int rowSum = 0;
        for (int j = 0; j < cols; j++) {
            rowSum += arr[i][j];
        }
        cout << "Row " << i + 1 << ": " << rowSum << endl;
    }
}

void sumCols(int arr[][maxSize], int rows, int cols) {
    cout << "\nSum of each column:" << endl;
    for (int j = 0; j < cols; j++) {
        int colSum = 0;
        for (int i = 0; i < rows; i++) {
            colSum += arr[i][j];
        }
        cout << "Column " << j + 1 << ": " << colSum << endl;
    }
}

int main() {
    int rows, cols;
    cout << "Enter the number of rows and columns: ";
    cin >> rows >> cols;

    if (rows > maxSize || cols > maxSize) {
        cout << "Matrix size exceeds the maximum allowed size." << endl;
        return 1;
    }

    int arr[maxSize][maxSize];

    inputArray(arr, rows, cols);
    sumRows(arr, rows, cols);
    sumCols(arr, rows, cols);

    return 0;
}
