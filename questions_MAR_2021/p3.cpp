// Q3. Write a program in C++ that reads some text entered through the keyboard till the end of
// file (eof) character is entered. The words in the text are written to different text files as per
// the following conditions:
// • The words beginning with any of the lowercase vowels (a, e, i, o, u) are written to
// a file fileV.txt.
// • The words beginning with a digit (0 – 9) are written to a file fileD.txt.
// • All other words are written to a file fileRest.txt.
// Sample input:
// Buy 1 kg apples And 17 oranges immediately
// ^Z
// Sample output:
// fileV.txt: apples oranges immediately
// fileD.txt: 1 17
// fileRest.txt: Buy kg And

#include<iostream>
#include <typeinfo>
#include<fstream>
using namespace std;

bool checkVowel(char ch) {
    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
        return true;
    }
    return false;
}

bool checkDigit(char ch) {
    int temp = static_cast<int>(ch);
    if(temp >= 48 && temp <= 57) {
        return true;
    }
    return false;
}

void writeWord(ifstream& fin, ofstream& fout) {
    char ch;
    while(!fin.eof()) {
        fin>>noskipws>>ch;
        fout<<ch;
        if(ch == ' ') {
            break;
        }
    }   
}

bool separateFiles(string fileName, string current_path) {
    string file_abs = current_path + fileName;
    ifstream fin;
    fin.open(file_abs);
    if (fin.fail()) {
        cout<<"Not able to find file: "<<file_abs<<endl;
        return false;
    }

    ofstream foutV, foutD, foutRest;
    foutV.open(current_path + "fileV.txt");
    foutD.open(current_path + "fileD.txt");
    foutRest.open(current_path + "fileRest.txt");

    char ch;
    while(!fin.eof()) {
        fin>>noskipws>>ch;
        if (checkVowel(ch) == true) {
            foutV<<ch;
            writeWord(fin, foutV);
        }
        else if(checkDigit(ch) == true) {
            foutD<<ch;
            writeWord(fin, foutD);
        }
        else {            
            foutRest<<ch;
            writeWord(fin, foutRest);
        }
    }
    return true;
}


int main(int argc, char * argv[]) {
    string file = argv[0];
    int index = file.find_last_of('/'); // change to '\' for windows workspace.
    string current_path = file.substr(2,index-1);
    string fileName;
    cout<<"Welcome to file separator! "<<endl;
    cout<<"Enter file name: "<<endl;
    cin>>fileName;

    if (separateFiles(fileName, current_path)) {
        cout<<"Files separated successfully."<<endl;
        return 0;
    }
    cout<<"Error while separating files."<<endl;
    return 1;
}