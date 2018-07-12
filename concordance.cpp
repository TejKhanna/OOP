#include "std_lib_facilities.h"

int main(){
    vector<string> text;

    cout << "Please enter the words in the text one by one below:\n";

    string word;
    for (string word; cin >> word;)
        text.push_back(word);

    cout << "\n";

    sort(text);

    int count = 0;
    string last_word = text[0];

    for (string word : text){

        if (word == last_word){
            count++;
        }

        else{
            cout << last_word << " appears " << count << " time(s)\n";
            count = 1;
        }
        cout << "The word is: " << word << endl;
        last_word = word;

    }

    cout << last_word << " appears " << count << " time(s)/n";

};