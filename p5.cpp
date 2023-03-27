// Define an abstract class Human comprising sthe following members- name and age (with
// appropriate data types), a parameterized constructor and a pure virtual function
// printDetails().
// The program also defines two concrete classes- Adult and Child inheriting publicly
// from the class Human.
// Class Adult has a data member- voterID (with appropriate data type).
// Class Child has a data member- schoolName (with appropriate data type).
// Define parameterized constructors for both the classes Adult and Child. The
// constructors should also have following validation check for the age input.
// • The age of an adult should be more than or equal to 18 years.
// • The age of a child should be in the range 0 to 18 (excluding both numbers).
// Override printDetails()function for both the derived classes.
// Define main()function to declare one object each for classes Adult and Child
// respectively and print the details of the objects.

#include<iostream>
using namespace std;

class Human {
    private:
        string name;
        int age;
    public: 
        Human(const string Name, const int Age) {
            name = Name;
            age = Age;
        }
        string getName() const {
            return name;
        }
        int getAge() const {
            return age;
        }
        virtual void PrintDetails() = 0;
};

class Adult: public Human {
    private:
        int voterID;
    public:
        Adult(string name, int age, int voterID) : Human(name, age) {
            if (age < 18) {
                throw runtime_error("Adults should be of at least 18 years of age.");
            }
            voterID = voterID;
        }
        void PrintDetails();
};

void Adult::PrintDetails() {
    cout<<"Name:    "<<this->getName()<<endl;
    cout<<"Age:     "<<this->getAge()<<endl;
    cout<<"voterId: "<<this->voterID<<endl;
}

class Child: public Human {
    private:
        string schoolName;
    public:
        Child(string name, int age, string school) : Human(name, age) {
            if (age >= 18) {
                throw runtime_error("Children should be less than 18 years of age.");
            }
            this->schoolName = school;
        }
        void PrintDetails();
};

void Child::PrintDetails() {
    cout<<"Name:        "<<this->getName()<<endl;
    cout<<"Age:         "<<this->getAge()<<endl;
    cout<<"School Name: "<<this->schoolName<<endl;
}

int main() {
    try {
        Adult A1 = Adult("Piyush", 22, 12345);
        A1.PrintDetails();
        Child C1 = Child("Riz", 2, "Aryabhatta" );
        C1.PrintDetails();
    }
    catch ( exception &e) {
        cerr<< e.what() <<endl;
        return 1;
    }
    return 0;
}