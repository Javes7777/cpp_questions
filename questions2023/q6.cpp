#include<iostream>
#include<vector>
#include<string>
using namespace std;

vector<int> findNum(int arr[] , int size, int Num) {
    vector<int> found;
    for(int i=0; i<size; i++) {
        if(arr[i] == Num) {
            found.push_back(i);
        }
    }
    return found;
}

void getArrInput(int arr[], int size) {
    // return size;
    for(int i=0;i<size;i++) {
        cout<<"Enter the [ "<<i<<" ] element: ";
        cin>>arr[i];
    }
    cout<<endl<<"Array recieved: "<<endl;
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<"\t";
    }
    cout<<endl;
}

int main() {
    while (true) {
        int size=0, Num;
        cout<<"Enter the size of array: ";
        cin>>size;
        int arr[size];

        getArrInput(arr, size);

        cout<<"Enter the integer to be found: ";
        cin>>Num;
        cout<<endl;

        vector<int> found = findNum(arr, size, Num);

        if (found.size() == 0) {
            cout<<"not found"<<endl;
        }
        else {
            cout<<"found at indexes:"<<endl;
            for(auto it = found.begin(); it<found.end(); ++it){
                cout<<*it<<endl;
            }
        }
        char choice;
        cout<<"Do you want to try again? (Y/N)"<<endl;
        cin>>choice;
        if (tolower(choice) == 'n') {
            break;
        }
    }
    return 0;
}