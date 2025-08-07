#include<iostream>
using namespace std;
void removeduplicate(int arr[], int n){
    for(int i=0 ; i < n ; i++){
        for(int j=i+1 ; j < n ; j++){
            if(arr[i] == arr[j]){
                for(int k=j ; k < n-1 ; k++){
                    arr[k] = arr[k+1];
                }
                n--;
                j--; 
            }
        }
         
    }
    cout << "Array after deletion";
    for(int i=0 ; i < n ; i++){
        cout << arr[i] << " ";
    }
}
int main() {
    int n =6;
    int arr[] = { 1, 1, 3, 3, 6, 6};
    removeduplicate(arr, n);
    return 0 ;
}