// 4. Write a menu driven program to perform string manipulation (without using inbuilt
// string functions):
// a. Show address of each character in string
// b. Concatenate two strings.
// c. Compare two strings
// d. Calculate length of the string (use pointers)
// e. Convert all lowercase characters to uppercase
// f. Reverse the string
// g. Insert a string in another string at a user specified position

#include<iostream>
using namespace std;

class myString {
    private:
        char* hyperString;
        int size;
    public:
        myString(const int);
        ~myString();
        int compare(const myString B) const;
        bool reverse();
        bool concatenate(const myString B);
        int getSize() const;
        void printAddress() const;
        bool swapCase(const bool casing=false, const bool allLetters=true); // false for lowercase, true for uppercase
        bool insertInto(const myString B, const int index=0);
        void printString() const;
};

myString::myString(const int length) {
    size = abs(length);
    hyperString = new char[size];
}

myString::~myString() {
    delete [] this->hyperString;
}

int myString::compare(const myString B) const {
    // Compares the ascii values of two strings.
    // return -1 if this string is bigger than B
    // return 1 if this string is smaller than B
    // return 0 if they are equal
    // return 2 for some other error reporting
    return 0;
}

bool myString::reverse() {
    // true for successfull reversal
    // false for error reporting.
    return true;
}

int myString::getSize() const {
    return this->size;
}

void myString::printAddress() const {
    // print address of each char in the string.
}

bool myString::swapCase(const bool casing=false, const bool allLetters=true) {
    // false for lowercase, true for uppercase
    // allLetters true for swapping all letters.
    // return true for successfull swap, false for error.
    return true;
}

bool myString::insertInto(const myString B, const int index=0) {
    // inserts string B into this string at index
    // true for successfull insert
    return true;
}

bool myString::concatenate(const myString B) {
    //joins two strings 
    // return true for success.
    return true;
}

void myString::printString() const {
    //print this string
}

void printMenu() {
    cout<<endl;
    cout<<"1. Show address of each character in the string."<<endl;
    cout<<"2. Concatenate two strings."<<endl;
    cout<<"3. Compare two strings."<<endl;
    cout<<"4. Calculate the length of the string."<<endl;
    cout<<"5. Convert casing."<<endl;
    cout<<"6. Reverse a string."<<endl;
    cout<<"7. Insert one string into another."<<endl<<endl;
    cout<<"Enter your choice, press any other character to exit"<<endl;
}

myString getString() {
    //take input and return a string
    myString temp(0);
    return temp;
}

void runMenu() {
    int choice = -1;
    myString A, B;

    while(true) {
        printMenu();
        cin>>choice;
        switch (choice) {
            case 1:
                A = getString();
                break;
            case 2:
                A = getString();
                B = getString();
                A.concatenate(B);
                A.printString();
                break;
            case 3:
                A = getString();
                B = getString();
                A.compare(B);
                break;
            case 4:
                A.getSize();
                break;
            case 5:
                A = getString();
                // get input about how to swap
                A.swapCase();
                break;
            case 6:
                A.reverse();
                break;
            case 7:
                A.insertInto(B);
                break;
            default:
                break;
        }
    }
} 

int main() {
    try {
        runMenu();
    } 
    catch exception {
        cerr<<"Error in main thread."<<endl;
        return 1;
    }
    
    cout<<"Thank you for using this program."
    return 0;
}