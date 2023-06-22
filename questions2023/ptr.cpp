#include <iostream>
using namespace std;


int main() {
//    int  var = 20;   // actual variable declaration.
//    int  *ip;        // pointer variable 
//
//    ip = &var;       // store address of var in pointer variable
//    int *ip2 = ip;
//    cout << "Value of var variable: ";
//    cout << var << endl;
//
//    // print the address stored in ip pointer variable
//    cout << "Address stored in ip variable: ";
//    cout << ip << endl;
//    cout << "Address of ip: ";
//    cout << &ip << endl;
//
//
//    // access the value at the address available in pointer
//    cout << "Value of *ip variable: ";
//    cout << *ip << endl;
//
//
//    cout << "Value and address of ip2: " << *ip2 << " , " << &ip << endl;


    char a = 'a';  
    char *b;  
    char ** c;  
    a = 'g';  
    b = &a;  
    c = &b;


    cout << " value and address of a: " << a << " , " << &a << endl;
    cout << " value, address and address stored in b: " << b << " , " << *b << " , " << &b << endl;

    cout << " value, address and address stored in c: " << c << " , " << *c << " , " << &c << endl;

    return 0;
}



 //value and address of a: g , g
 //value, address and address stored in b: g , g , 0x16d51eed0
 //value, address and address stored in c: 0x16d51eed0 , g , 0x16d51eec8
