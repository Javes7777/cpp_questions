#include <iostream>
using namespace std;

class Shape {
   protected:
      double area;
   public:
      virtual void calculateArea() = 0; // Pure virtual function
      void displayArea() {
         cout << "Area: " << area << endl;
      }
};


class Rectangle : public Shape {
   private:
      double length;
      double breadth;
   public:
      Rectangle(double l, double b) {
         length = l;
         breadth = b;
      }
      void calculateArea() {
         area = length * breadth;
      }
};


class Circle : public Shape {
   private:
      double radius;
   public:
      Circle(double r) {
         radius = r;
      }
      void calculateArea() {
         area = 3.14 * radius * radius;
      }
};

int main() {
   // Creating objects of derived classes
   Rectangle rect(5, 3);
   Circle cir(7);

   // Creating pointers of base class type
   Shape* s1 = &rect;
   Shape* s2 = &cir;

   // Calling virtual function to calculate area
   s1->calculateArea();
   s2->calculateArea();

   s1->displayArea();
   s2->displayArea();

   return 0;
}

//  Base class Shape that has a pure virtual function calculateArea().
// This makes the Shape class an abstract class because it cannot be instantiated on its own,
// and any class that derives from it must implement the calculateArea() function.
// rest is same as pure_virtual_function program.