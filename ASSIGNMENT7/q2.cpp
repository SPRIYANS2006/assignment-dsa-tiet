#include <iostream>
using namespace std;

void improvedSelectionSort(int a[], int n) {
    int left = 0;
    int right = n - 1;

    while (left < right) {
        int minIndex = left;
        int maxIndex = right;

    
        if (a[minIndex] > a[maxIndex])
            swap(a[minIndex], a[maxIndex]);

        
        for (int i = left + 1; i < right; i++) {
            if (a[i] < a[minIndex])
                minIndex = i;
            else if (a[i] > a[maxIndex])
                maxIndex = i;
        }

    
        swap(a[left], a[minIndex]);

        if (maxIndex == left)
            maxIndex = minIndex;

        
        swap(a[right], a[maxIndex]);

        left++;
        right--;
    }
}

void printArray(int a[], int n) {
    for (int i = 0; i < n; i++)
        cout << a[i] << " ";
    cout << endl;
}

int main() {
    int n;

    cout << "Enter size: ";
    cin >> n;

    int arr[n];
    cout << "Enter elements: ";
    for (int i = 0; i < n; i++) cin >> arr[i];

    improvedSelectionSort(arr, n);

    cout << "Sorted Array: ";
    printArray(arr, n);

    return 0;
}
