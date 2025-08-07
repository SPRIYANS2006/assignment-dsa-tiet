#include<iostream>
using namespace std;
void inputarray(int arr[], int size) {
    cout << "Enter " << size << " elements of the array: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }
}
void reverselement(int arr[], int size ){
    
    int end = size - 1;

   
    for (int start = 0; start <= end; start++)
    {
       swap(arr[start], arr[end]);
       end--;
    }
    
}
void printarray(int arr[], int size){
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int size;
    cout << "Enter the size of the array: ";    
    cin >> size;
    int arr[size]; 
    inputarray(arr, size);

    reverselement(arr, size);
    cout << "Reversed array: ";
    printarray(arr, size);
    
    
    return 0;
}
