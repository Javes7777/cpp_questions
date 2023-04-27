#include<iostream>
#include<string>

using namespace std;

class Person {
    private:
        string name;
    public:
        Person(string name) {
            this->name = name;
        }
        void display() const {
            cout<<"Name: "<<name<<endl;
        }
};

class Student : public Person {
    private:
        string course;
        int marks;
        int year;
    public:
        Student(string name, string course, int marks, int year): Person(name) {
            this->marks = marks;
            this->course = course;
            this->year = year;
        }
        void display() const {
            cout<<"Student ";
            Person::display();
            cout<<"Course :"<<course<<endl;
            cout<<"Year :"<<year<<endl;
            cout<<"Marks :"<<marks<<endl;
        }

};

class Employee : public Person {
private:
        string department;
        int salary;
    public:
        Employee(string name, string department, int salary): Person(name) {
            this->department = department;
            this->salary = salary;
        }
        void display() const {
            cout<<"Employee ";
            Person::display();
            cout<<"Department :"<<department<<endl;
            cout<<"Salary :"<<salary<<endl;
        }

};

int main(int argc, char * argv[]) {
     try {
        Person P1 = Person("Rocket Singh");
        P1.display();
        cout<<endl;
        Student S1 = Student("Pocket Singh", "Science", 10, 2);
        S1.display();
        cout<<endl;
        Employee E1 = Employee("Locket Singh", "Industrial", 30000);
        E1.display();
        cout<<endl;
    }
    catch ( exception &e) {
        cerr<< e.what() <<endl;
        return 1;
    }

    return 0;
}