// Q6. Write a C++ program that prompts a user for three integers- the first denoting a month (1
// to 12), the second denoting a day (1 to 31) and the third denoting a year. The output is
// displayed as "month day, year" string where month represents the name of the month.
// For example, if inputs are 12, 15 and 2020 respectively, the output is December 15,
// 2020.
// A parameterized function convertDate(...) is defined to accept above three integers
// as arguments and return the appropriate string.
// If the user enters any number other than a valid month number (integers from 1 to 12) as a
// first input, then the program throws an error (exception) of the type string. Write an
// exception handler that handles the exception by displaying a message "Not a valid
// month" and exits.
// If the user enters any number other than a valid day number (integers from 1 to either 28,
// 30, or 31, depending on the month) as second input, then the program throws an error
// (exception) of the type integer. Write an exception handler that handles the exception by
// displaying a message "Not a valid day" and exits.
// If the user enters month value 2, day value 29 and a non-leap year as third input, then the
// program throws an error (exception) of the type double. Write an exception handler that
// handles the exception by displaying a message "Not a leap year" and exits.

#include<iostream>
#include <stdexcept>
#include <string>
using namespace std;

void checkMonth(const int input) {
    if(input < 1 || input > 12) 
        throw runtime_error("Not a valid Month!");
}

void checkDay(const int month, const int input) {
    int high;
    if (month==2){
        high = 29;
    }
    else if(month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || month==12){
        high = 31;
    }
    else if(month==4 || month==6 || month==9 || month==11){
        high = 30;
    }
    if ( input < 1 || input > high)
        throw runtime_error("Not a valid Day!");
}

void checkYear(const int day, const int month, const int year) {
    if (month == 2 && day == 29) 
        if (year % 400 != 0 || year%100 !=0 || year%4 != 0) 
            throw runtime_error("Not a leap Year!");
}

string convertDate(const int day, const int month, const int year) {
    string Month = "";

    switch(month) {
        case 1:
            Month = "January";
            break;
        case 2:
            Month = "Febraury";
            break;
        case 3:
            Month = "March";
            break;
        case 4:
            Month = "April";
            break;
        case 5:
            Month = "May";
            break;
        case 6:
            Month = "June";
            break;
        case 7:
            Month = "July";
            break;
        case 8:
            Month = "August";
            break;
        case 9:
            Month = "September";
            break;
        case 10:
            Month = "October";
            break;
        case 11:
            Month = "November";
            break;
        case 12:
            Month = "December";
            break;
        default:
            Month = "Invalid Month";
            break;
    }

    string date = Month + " " + to_string(day) + ", " + to_string(year);
    return date;
}


int main() {
    int month, day, year;

    try {
        cout<<"Month: ";
        cin>>month;
        checkMonth(month);

        cout<<"Day: ";
        cin>>day;
        checkDay(month, day);

        cout<<"Year: ";
        cin>>year;
        checkYear(day, month, year);
    }
    catch( exception& e) {
        cerr<<"ERROR OCCURED " << e.what()<<endl;
        exit(1);
    }

    cout<<"Converted Date: "<<convertDate(day, month, year)<<endl;
    return 0;
}