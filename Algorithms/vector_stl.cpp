#include<iostream> 
#include<vector> 
using namespace std;


int main() {
    vector<int> v;
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);

    cout << "Initial vector:";
    for (int i : v) {
        cout << " " << i;
    }
    cout << "\nInitial size: " << v.size() << endl;

    v.resize(3);
    cout << "After resize to 3 elements:";
    for (int i : v) {
        cout << " " << i;
    }
    cout << "\nSize after resize: " << v.size() << endl;

    cout << "Is vector empty? " << (v.empty() ? "Yes" : "No") << endl;

    cout << "Maximum size of the vector: " << v.max_size() << endl;

    v.erase(v.begin() + 1);
    cout << "After erasing second element:";
    for (int i : v) {
        cout << " " << i;
    }
    cout << "\nSize after erase: " << v.size() << endl;

    v.shrink_to_fit();
    cout << "Capacity after shrink_to_fit: " << v.capacity() << endl;

    v.clear();
    cout << "Size after clear: " << v.size() << endl;

    return 0;
}
