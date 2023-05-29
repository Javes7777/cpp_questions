#include <iostream>
#include <vector>
using namespace std;
vector<int> mergeArrays(const vector<int>& arr1, const vector<int>& arr2) {
    vector<int> mergedArray;
    int i = 0, j = 0;
    int size1 = arr1.size();
    int size2 = arr2.size();

    while (i < size1 && j < size2) {
        if (arr1[i] < arr2[j]) {
            mergedArray.push_back(arr1[i]);
            i++;
        } else {
            mergedArray.push_back(arr2[j]);
            j++;
        }
    }

    // Append the remaining elements from arr1, if any
    while (i < size1) {
        mergedArray.push_back(arr1[i]);
        i++;
    }

    // Append the remaining elements from arr2, if any
    while (j < size2) {
        mergedArray.push_back(arr2[j]);
        j++;
    }

    return mergedArray;
}

int main() {
    vector<int> arr1 = {1, 3, 5, 7, 9};
    vector<int> arr2 = {2, 4, 6, 8, 10};

    vector<int> mergedArray = mergeArrays(arr1, arr2);

    cout << "Merged Array: ";
    for (int num : mergedArray) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}

