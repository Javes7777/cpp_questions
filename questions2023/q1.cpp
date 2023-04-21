#include<iostream>
#include<cmath>

using namespace std;

int main(int argc, char * argv[]) {
    int input;
    if (argc < 2) {
        cout<<"Enter a number: ";
        cin>>input;
    }
    else{
        string temp = argv[1];
        input = stoi(temp);
    }
    float sum=0;
    for(int i=1; i<=input; i++) {
        if(i%2==0) {
            sum = sum - i/pow(i,2);
        }
        else {
            sum = sum + i/pow(i,2);
        }
    }
    cout<<"Series Evaluate to: "<<sum<<endl;
    return 0;
}