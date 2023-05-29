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
#include<string> 
#include <cstdlib>
using namespace std;

void getStringInput(string& str) {
    cout << "Enter a string: ";
    cin>>str;
    cout << "You entered: " << str << endl;
}

void printCharacterAddresses(const string& str) {
    cout << "Character addresses in the string:\n";
    for (const char& c : str) {
        const void* address = static_cast<const void*>(&c);
        cout << "Character '" << c << "': " << address << endl;
    }
}

bool compareStrings(const std::string& str1, const std::string& str2) {
    if (str1.length() != str2.length()) {
        return false;
    }

    for (size_t i = 0; i < str1.length(); ++i) {
        if (str1[i] != str2[i]) {
            return false;
        }
    }

    return true;
}

int calculateStringSize(const string& str) {
    int size = 0;
    while (str[size] != '\0') {
        ++size;
    }
    return size;
}


string convertToLowercase(const string& str) {
    string result = str;
    for (char& c : result) {
        if (c >= 'a' && c <= 'z') {
            c -= 'a' - 'A';
        }
    }
    return result;
}

void printString(const string& str) {
    int index = 0;
    while (str[index] != '\0') {
        cout << str[index];
        ++index;
    }
}

void reverseString(string& str) {
    if (&str == nullptr)
        return;

    int length = 0;
    while (str[length] != '\0') {
        ++length;
    }

    int start = 0;
    int end = length - 1;

    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        ++start;
        --end;
    }
}

void insertString(string& dest, string& src, int index) {
    if (&dest == nullptr || &src == nullptr)
        return;

    int destLength = 0;
    while (dest[destLength] != '\0') {
        ++destLength;
    }

    int srcLength = 0;
    while (src[srcLength] != '\0') {
        ++srcLength;
    }

    if (index < 0 || index > destLength)
        return;

    int totalLength = destLength + srcLength;

    for (int i = totalLength; i >= index + srcLength; --i) {
        dest[i] = dest[i - srcLength];
    }

    for (int i = 0; i < srcLength; ++i) {
        dest[index + i] = src[i];
    }
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

void runMenu() {
    int choice = -1;
    bool allLetters(1), casing(1);
    char input;      
    int index=0;

    string A,B;

    while(true) {
        printMenu();
        cin>>choice;
        switch (choice) {
            case 1:
                getStringInput(A); 
                printCharacterAddresses(A); 
                break;
            case 2:
                cout<<"Enter first string: "<<endl;
                getStringInput(A);
                cout<<"Enter second string: "<<endl;
                getStringInput(B);
                cout<<"Concatinating these strings...."<<endl;
                insertString(A, B, calculateStringSize(A));
                printString(A);
                break;
            case 3:
                cout<<"Enter first string: "<<endl;
                getStringInput(A);
                cout<<"Enter second string: "<<endl;
                getStringInput(B);
                if (compareStrings(A, B)) {
                    cout << "The strings are equal." << endl;
                } else {
                    cout << "The strings are not equal." << endl;
                }
                break;
            case 4:
                getStringInput(A);
                cout<<"Size of string: "<<calculateStringSize(A);
                break;
            case 5:
                cout<<"Enter a string"<<endl;
                getStringInput(A);
                A = convertToLowercase(A);
                printString(A);
                break;
            case 6:
                cout<<"Enter a string"<<endl;
                getStringInput(A);
                reverseString(A);
                printString(A); 
                break;
            case 7:
                cout<<"Enter first string: "<<endl;
                getStringInput(A);
                cout<<"Enter second string: "<<endl;
                getStringInput(B);

                cout<<"Enter index where you want to insert"<<endl;
                cin>>index;
                insertString(A, B, index);
                printString(A);
                break;
            default:
                return;
        }
    }
} 

int main() {
    cout<<"Welcome"<<endl;
    try {
        runMenu();
    } 
    catch (string message) {
        cerr<<message<<endl;
        cerr<<"Error in main thread."<<endl;
        return 1;
    }
 
    cout<<"Thank you for using this program."<<endl;
    return 0;
}