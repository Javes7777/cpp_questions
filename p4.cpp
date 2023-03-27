// Write C++ statements for the following tasks:
// a. Write the prototype of a function funP that accepts two arguments- a constant one
// dimensional array of integers and a float; and returns a pointer to a double.
// b. Accept three strings through command line arguments. If the number of integers
// entered is less than or greater than three, the program exits after displaying the
// message "Wrong number of inputs!".
// c. Interchange values of two integer variables using pointers.
// d. An anonymous object of a derived class Derv is to be pointed to by a reference of
// its base class Base.
// e. Write the prototype of a friend function funObjs(...) having references to two
// objects of a class MyClassOne as parameters and an object of a class
// MyClassTwo as return type.


#include<iostream>
using namespace std;

//part a
double* funP(const int **Arr, float x);

//part b
// int main(int argc, char * argv[]) {
//     if (argc < 4) {
//         cout<<"Wrong Number of Inputs"<<endl;
//         return 1;
//     }
//     for (int i=1; i<argc; i++) {
//         cout<<"Argument "<< i << " " << argv[i]<<endl;
//     }
//     return 0;
// }

// part c
// void swap(int *r, int *s)
// {
//    int temp = *r;
//    *r = *s;
//    *s = temp;
//    return;
// } 


// int main() {
//     int num1, num2;

//     cout<<"Enter first number: ";
//     cin>>num1;
//     cout<<"Enter second number: ";
//     cin>>num2;

//     swap(num1, num2);
//     cout<<"First number: "<<num1<<endl;
//     cout<<"Second number: "<<num2<<endl;
//     return 0;
// }

//part d:

// class Base {
//     private:
//         int base;
//     public:
//         Base(const int some) {
//             base = some;
//         }
//         int getBase() {
//             return base;
//         }
// };

// class Derv: public Base {
//     private:
//         int derv;
//     public:
//         Derv(const int some, const int other) : Base(some)  {
//             derv = other
//         }
//         int getDerv() {
//             return derv;
//         }
// }

// // better learn from here:
// // https://www.learncpp.com/cpp-tutorial/pointers-and-references-to-the-base-class-of-derived-objects/

// int main() {
//     Derived d;
//     ptr = &d;
//     return 0;
// }

// // part e:
// class myClass {    
//     friend myClassTwo funObjs(const MyClassOne, const MyClassOne); // syntax of friend function.  
// };    
