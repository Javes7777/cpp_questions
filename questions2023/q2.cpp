#include<iostream>
using namespace std;

int remove_duplicate(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (arr[i] == arr[j]) {
                for (int k = j; k < size - 1; k++) {
                    arr[k] = arr[k + 1];
                }
                size--; 
                j--; 
            }
        }
    }
    return size;
}

void displayArray(int arr[], int size) {
    for(int i=0; i<size; i++) {
        cout<< arr[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int arr[] = {1,2,1,3,4,4,5,6,4,7,8};
    int size = sizeof(arr) / sizeof(arr[0]);
    
    cout << "Initial Array: " <<endl;
    displayArray(arr, size);

    int new_size = remove_duplicate(arr, size);

    cout << "After removing duplicates: "<<endl;
    displayArray(arr, new_size);
    
    
    return 0;
}
