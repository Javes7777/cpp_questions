#include<iostream> 

using namespace std;

int factorial(int n=0) {
	if (n == 0) {
		return 1;
	}
	else {
		return n*factorial(n-1);
	}
} 

inline int factorial_inline(int n=0) {
	return factorial(n);
}

int main() {
	int num;
	cout<<"Enter a number: "<<endl; 
	cin>>num;
	cout<<"Factorial of "<<num<<" = "<<factorial_inline(num)<<endl;
	return 0;
}
