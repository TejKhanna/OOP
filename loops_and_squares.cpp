#include "std_lib_facilities.h"

int square( int x){
    return x*x;
}

int main(){

    for(int i = 1; i<101; i++)
        cout << "The square of " << i << " is " << square(i) << "\n";

};