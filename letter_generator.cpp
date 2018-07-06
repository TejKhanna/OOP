#include "std_lib_facilities.h"

int main(){
    string name;
    string friendName;
    int age;

    cout << "Please enter your name:\n";
    cin >> name;

    cout << "Please enter your age:\n";
    cin >> age;

    cout <<"Please enter a friend's name:\n";
    cin >> friendName;
    cout << "\n";

    cout << "Dear " << name << ",\nI hope you are well. \nI hear you had a birthday and are now " << age << " years old!\n" ;

    if (age<17)
        cout << "You are too young to be at NYU!";

    if (age>65)
        cout << "It is great to see senior students at NYU.\n";

    cout << "I am writing because my OOP Professor told me to.\nHave you seen " << friendName << " in a while?\nBest regards\nTej Khanna\n"  ;

}