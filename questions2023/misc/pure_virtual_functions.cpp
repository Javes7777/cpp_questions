#include <iostream>
using namespace std;

class Shape {
   public:
      virtual void calculateArea() = 0; // pure virtual function
};

class Rectangle : public Shape {
   public:
      void calculateArea() {
         cout << "Area of Rectangle\n";
      }
};

class Circle : public Shape {
   public:
      void calculateArea() {
         cout << "Area of Circle\n";
      }
};

int main() {
   Shape* s1;
   Rectangle r;
   s1 = &r;
   s1->calculateArea(); // Output: Area of Rectangle
   
   Shape* s2;
   Circle c;
   s2 = &c;
   s2->calculateArea(); // Output: Area of Circle
   
   return 0;
}
//Base class Shape has a pure virtual function calculateArea(). 
// Two derived classes Rectangle and Circle that inherit from the Shape base class. 
//Both of these derived classes override the calculateArea() 
//function to provide their own implementation.