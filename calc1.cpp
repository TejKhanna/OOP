#include "std_lib_facilities.h"

int showResult(int result){
    cout << result << endl;
};

int main(){
    cout << "Welcome to Calculator V1.0\nPlease enter an expression for me to solve:\n";
    int lval;
    int rval;
    char op;
    int res;
    cin >> lval >> op >> rval;
    cout << endl;

    if(op == '+'){
        res = lval + rval;
    };

    if(op == '-'){
        res = lval - rval;
    };

    if(op == '*'){
        res = lval * rval;
    };

    if(op == '/'){
        res = lval / rval;
    };

    showResult(res);


}