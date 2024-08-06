#include<iostream>

using namespace std;

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    int temp;
    int j=low;

    while(j >= low && j < high) {
        if (arr[j] <= pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
        j++;
    }

    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}

int partition_random(int arr[], int low, int high) {
    int r = rand()%(high-low + 1) + low;
    cout << " random num: " << r << endl;
    int temp;
    temp = arr[r];
    arr[r] = arr[high];
    arr[high] = temp;

    return partition(arr, low, high);
}

void randomized_quicksort(int arr[], int low=0, int high=0, int size=0) {
    //int numComp = 0;
    int pivot_index;
    if (high == 0) {
        high = size -1;
    }

    if (low < high) {
        pivot_index = partition_random(arr, low, high);
        randomized_quicksort(arr, low, pivot_index-1);
        randomized_quicksort(arr, pivot_index+1, high);
    }
    // cout << "Number of comparisons: " << numComp << endl;
}

int main() {
    int arr[10] = {1, 4, 10, 2, 3, 8, 5, 7, 9, 6};
    
    randomized_quicksort(arr, 0, 0, 10);

    for(int i=0; i<10; i++) {
        cout << arr[i] << "  ";
    }
    cout << endl;
    return 0;
}
