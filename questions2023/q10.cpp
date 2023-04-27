#include<iostream>
#include<string>
#include<stdexcept>
#include<math.h>

using namespace std;


//overloaded functions:
float calculateArea(const int s1, const int s2) {
    return 0.5*s1*s2;
}
float calculateArea(const int s1, const int s2, const int s3) {
    int sum = (s1+s2+s3)/2;
    return sqrt(sum*(sum-s1)*(sum-s2)*(sum-s3));
}

class Triangle {
    private:
        int s1, s2, s3;
        bool right_angled;
    public:
        Triangle(int side1, int side2, int side3, bool right_angled=false) {
            s1 = side1; s2 = side2; s3 = side3;
            if (s1<=0 || s2<=0 || s3<=0) {
                throw std::logic_error("Invalid sides: sides should be greator than 0");
            }
            if( (s1 + s2 < s3) || (s1 + s3 < s2) || (s2 + s3 < s1) ) {
                throw std::logic_error("Invalid sides: sum of any 2 sides should be greater than the third side.");
            }
            this->right_angled = right_angled;
        }
        float Area() const{
            //calls overloaded function
            if(this->right_angled)
                return calculateArea(s1, s2);
            return calculateArea(s1, s2, s3);
        }
};

int main(int argc, char * argv[]) {
    try {
        Triangle T1 = Triangle(1,8,0);
    }
    catch (exception &e) {
        cerr<< e.what() <<endl;
    }
    try {
        Triangle T1 = Triangle(1,8,5);
    }
    catch (exception &e) {
        cerr<< e.what() <<endl;
    }
    Triangle T2 =  Triangle(5,3,4, true);
    cout<<"Area of triangle: "<<T2.Area()<<endl;
    Triangle T3 =  Triangle(10,9,5, false);
    cout<<"Area of triangle: "<<T3.Area()<<endl;
    return 0;
}