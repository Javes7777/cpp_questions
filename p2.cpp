// Q2. Write a program in C++ that defines an m x n two dimensional array containing integer
// elements, where m and n represent the numbers of rows and columns respectively. The
// numbers of rows and columns should be defined as constants. The program should provide
// the following user-defined functions with appropriate parameters:
// • setArrData(...): The function accepts elements from the keyboard and
// stores them into the array.
// • printArrData(...): The function prints the array values on the screen.
// • getAverage(...): The function accepts the array, number of rows and number
// of columns as parameters and returns the average of all values in the array.
// • findMax(...): The function accepts the array, number of rows and number of
// columns as parameters and prints the greatest element from each column of the
// array.

#include<iostream>
using namespace std;

class Array {
    private:
        int row;
        int col; 
        int **arr;
    public:
        Array(int, int);
        Array(const Array&);
        ~Array();
        void setArrData();
        void printArrData() const;
        float getAverage() const;
        int findMax() const;
};

Array::Array(int m, int n) {
    row = m;
    col = n;
    arr = new int*[this->row];
    for (int i = 0; i < this->row; ++i) {
        arr[i] = new int[this->col];
    }
}

Array::Array(const Array& A1) {
    row = A1.row;
    col = A1.col;
    arr = new int*[this->row];
    for (int i = 0; i < this->row; ++i) {
        arr[i] = new int[this->col];
    }
    for(int i=0; i<this->row; i++) {
        for(int j=0; j<this->col; j++) {      
            this->arr[i][j] = A1.arr[i][j];
        }        
    }
}

Array::~Array() {
    for (int i = 0; i < this->row; ++i) {
        delete[] arr[i];
    }
    delete[] arr;
}

void Array::setArrData() {
    cout<<"Enter the elements of the array row wise."<<endl;
    for(int i=0; i<this->row; i++) {
        for(int j=0; j<this->col; j++) {      
            cout<<"Element at ["<<i+1<<"]["<<j+1<<"] : ";
            cin>>arr[i][j];
        }
        cout<<endl;
    }
}

void Array::printArrData() const {
    cout<<endl<<"Array is: "<<endl;
    for(int i=0; i<this->row; i++) {
        for(int j=0; j<this->col; j++) {      
            cout<<this->arr[i][j]<<"\t";
        }
        cout<<endl;
    }
    cout<<endl;
}

float Array::getAverage() const {
    int sum=0;
    for(int i=0; i<this->row; i++) {
        for(int j=0; j<this->col; j++) {
            sum+=this->arr[i][j];
        }   
    }
    return sum/(this->row*this->col);
}

int Array::findMax() const {
    int max=0;
    for(int i=0; i<this->row; i++) {
        for(int j=0; j<this->col; j++) {
            if (this->arr[i][j] > max) 
                max = this->arr[i][j];
        }   
    }
    return max;
}

int main() {
    Array a = Array(2,3);
    a.setArrData();
    a.printArrData();
    cout<<"average is "<<a.getAverage();
    cout<<"max is "<<a.findMax();

    Array a2 = a;
    a2.printArrData();

    a2.setArrData();
    cout<<"a is: "<<endl;
    a.printArrData();
    cout<<"a2 is: "<<endl;
    a2.printArrData();

    return 0;
}