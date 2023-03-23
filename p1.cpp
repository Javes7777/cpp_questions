// Question:
// Q1. Write a program in C++ that provides a user-defined class NewFloat with a data member
// floatData of type float. The class also comprises the following members:
// • default and parameterized constructors
// • an inline member function printData() that prints the details of an object of
// the class
// • a member function deciData() that returns the decimal part of floatData
// • operator overloading to perform the following operations:
// ▪ post increment (++) increments floatData by 1.
// ▪ less than (<) on a pair of objects of the class. The function returns 1 if the
// data member of the object on the LHS of the operator is less than the data
// member of the object on the RHS of the operator and 0 otherwise.
// ▪ int cast to convert the float data member of an object into an integer

#include<iostream>
#include<cmath>
using namespace std;

class newFloat {
    private:
        float floatData; 
    public:
        newFloat(float x);
        void printData();
        float deciData();
        newFloat& operator++();
        newFloat operator++(int DUMMY);
        bool operator<(const newFloat&) const;
        int toInt() const;
};

newFloat::newFloat(float x) {
    floatData = x;
}

// unary operators
newFloat& newFloat::operator++() {
    this->floatData = this->floatData + 1;
	return *this;
}

newFloat newFloat::operator++(int DUMMY) {
    newFloat temp = *this;
    this->floatData = this->floatData + 1;
    return temp;
}

// logical operators
bool newFloat::operator<(const newFloat& x) const{
    if (this->floatData < x.floatData) {
        return false;
    }
    return true;
}

void newFloat::printData() {
    cout<<"float number is: "<<this->floatData<<endl;
}

int newFloat::toInt() const {
    return static_cast<int>(this->floatData);
}

float newFloat::deciData() {
    float whole;
    float temp =  modf(this->floatData, &whole);
    return temp;
}

int main() {
    newFloat t1 = newFloat(12.34);
    newFloat t2 = newFloat(14.34);
    t1.printData();
    cout<<t1.toInt() <<endl;
    cout<<t1.deciData() <<endl;
    cout<< (t2<t1) << endl;
    t2 = t1++;
    t1.printData();
    t2.printData();
    return 0;
}