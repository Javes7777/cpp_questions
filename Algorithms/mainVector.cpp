#include <iostream>
#include "Vector.cpp"
using namespace std;

int main() {
    cout << "Testing... " << endl;
    Vector<int> vec;

    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);

    cout << "Vector elements after push_back: ";
    for (int i = 0; i < vec.size(); i++) {
        cout << vec[i] << " ";
    }
    cout << endl;

    Vector<int> vecCopy(vec);

    cout << "Copy constructor Vector elements: ";
    for (int i = 0; i < vecCopy.size(); i++) {
        cout << vecCopy[i] << " ";
    }
    cout << endl << endl;

    Vector<int> vecAssign = vec;

    cout << "Assigned Vector elements: ";
    for (int i = 0; i < vecAssign.size(); i++) {
        cout << vecAssign[i] << " ";
    }
    cout << endl;
    cout << "Original Vector size after assignment operator: " << vec.size() << endl; 
    cout << "Original Vector capacity after assignment operator: " << vec.capacity() << endl; 
    cout << endl;

    vecAssign.push_back(50);
    vecAssign.push_back(60);
    vecAssign.push_back(70);
    vecAssign.push_back(80);
    vecAssign.push_back(90);
    vecAssign.push_back(100);
    vecAssign.push_back(110);
    vecAssign.push_back(120);

    cout << "Vector elements after more push_back (auto increase capacity): ";
    for (int i = 0; i < vecAssign.size(); i++) {
        cout << vecAssign[i] << " ";
    }
    cout << endl;
    cout << "Current Vector capacity: " << vecAssign.capacity() << endl;
    cout << "Current Vector size: " << vecAssign.size() << endl;

    vecAssign.pop_back();
    vecAssign.pop_back();
    vecAssign.pop_back();
    vecAssign.pop_back();
    vecAssign.pop_back();
    vecAssign.pop_back();
    vecAssign.pop_back();
    vecAssign.pop_back();
    cout << "Vector elements after pop_back: ";
    for (int i = 0; i < vecAssign.size(); i++) {
        cout << vecAssign[i] << " ";
    }
    cout << "Current Vector capacity: " << vecAssign.capacity() << endl;
    cout << "Current Vector size: " << vecAssign.size() << endl;

    cout << endl;
    cout << "Vector capacity after shrink_to_fit: " << vecAssign.capacity() << endl;
    cout << "Vector size: after shrink_to_fit" << vecAssign.size() << endl;

    return 0;
}
