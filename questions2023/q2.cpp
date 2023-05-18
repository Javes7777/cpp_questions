#include<iostream>
using namespace std;

int[] remove_duplicate(const int arr[]) {
    int arr2[sizeof(arr)];
    int temp = arr[0];
    int k = 0;
    for(int i=1;i<sizeof(arr);i++) {
        int j=i;
        for(;j<sizeof(arr);j++) {
            if(arr[j] == temp) 
                break;
        }
        if(j == sizeof(arr)) {
            arr2[k] = arr[i];
            k++;
        }
    }
    return arr2;
}

int main() {
    int arr[] = {1,2,3,4,5,6,7,8};
    int arr2[] = remove_duplicate(arr);
    for(int i=0;i<sizeof(arr2);i++) {
        cout<< arr2[i]<<" ";
    }
    return 0;
}
