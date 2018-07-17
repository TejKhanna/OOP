#include "std_lib_facilities.h"

int main(){

{
//double to int to double
    double a = 12.3456;
    cout << a << endl;
    int b = a;
    cout << b << endl;
    double c = b;
    cout << c << endl << endl;
}
{

//double to char to double
    double a = 12.3456;
    cout  << "double: " << a << endl;
    char b = a;
    cout << "char: " <<  b << endl;
    double c = b;
    cout << "double: " << c << endl << endl;
}
}