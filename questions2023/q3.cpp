// Write a program that prints a table indicating the number of occurrences of each
// alphabet in the text entered as command line arguments

#include<iostream>
#include<vector>
using namespace std;

struct dictionary {
    char alphabet;
    int count;
};

vector<dictionary> map_text_dict(vector<dictionary> dict, string text){
    vector<dictionary>::iterator it;
    bool found;
    for(int i=0; i<text.length(); i++){
        found = false;
        for(it=dict.begin(); it!=dict.end(); ++it) {
            if(it->alphabet == text[i]) {
                it->count += 1;
                found = true;
                break;
            }
        }
        if (found == false)  {
            dictionary d1 = dictionary();
            d1.alphabet = text[i];
            d1.count = 1;
            dict.push_back(d1);
        }
    }
    return dict;
}


int main(int argc, char * argv[]) {
    string text = "";
    for (int i=1; i<argc; i++) {
        text += argv[i];
    }

    cout<<"Entered text is: "<<text<<endl;

    vector <dictionary> dict;

    dict = map_text_dict(dict, text);

    cout<<"Characters in text are:"<<endl;
    vector<dictionary>::iterator it;
    for(it = dict.begin(); it != dict.end(); ++it) {
        cout<<it->alphabet<<" occured "<<it->count;
        it->count == 1 ? cout<<" time." : cout<<" times.";
        cout<<endl;
    }

    return 0;
}