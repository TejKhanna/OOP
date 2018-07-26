#include "std_lib_facilities.h"
#include "token.h"
#include "vars.h"


void print_token(Token t){
    if(t.kind == number)
        cout << "Token of kind: " << t.kind << "  " << t.val << endl;
    else
        cout <<"Token of kind: " << t.kind << endl;
}

//Token_stream ts;

double expression(Token_stream& ts);
double term(Token_stream& ts);
double primary(Token_stream& ts);

double expression(Token_stream& ts){
    double left = term(ts);      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream
    while(true){

        switch(t.kind) {

        case '+':
            left += term(ts);    // evaluate Term and add
            t = ts.get();
            break;

        case '-':
            left -= term(ts);    // evaluate Term and subtract
            t = ts.get();
            break;

        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double term(Token_stream& ts){
    double left = primary(ts);
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {

        case '*':{
            left *= primary(ts);
            t = ts.get();
            break;
        }

        case '/':{
                double d = primary(ts);
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        case '%':{
            double d = primary(ts);
            if(d==0) error("mod by zero");
            left = fmod(left,d);
            t=ts.get();
            break;
        }

        default:{
            ts.putback(t);     // put t back into the token stream
            return left;
        }
    }

    }

}

double primary(Token_stream& ts){
	Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {
            double d = expression(ts);
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:            // we use 'n' to represent a number
        return t.val;  // return the number's value
    case '-':
        return -primary(ts);
    case '+':
        return primary(ts);
    case quit:
        return 0;
    default:
        error("primary expected");
    }
return 0;
}

double statement(Token_stream& ts)
{ //this is where the logic for variables will go
    Token t = ts.get();
    if(t.kind == name){
        Token var =t;
        t = ts.get();
        if(t.kind == '='){
            double d = expression(ts);
            set_value(var.name, d);
            return d;
            }
        else if(t.kind == print){
            ts.putback(t);
            return get_value(var.name);
        }
        ts.putback(t);
        ts.putback(var);
        return expression(ts);
        }
        ts.putback(t);
        return expression(ts);
}

void clean_up_mess(Token_stream& ts){
    while(true){
        Token t = ts.get();
        if(t.kind == print) return;
    }
}

void calculate(Token_stream& ts){
    double val = 0.0;

  while(true){
        cout << "> ";
        Token t = ts.get();
        if(t.kind == quit)
            break;
        if(t.kind == print){
            cout << "= " << val << endl << "> ";
        }
        else
            ts.putback(t);

        if(t.kind != quit)
            val = expression(ts);

    }

}

int main(){
    Token_stream ts;
    try {
        calculate(ts);
    }
    catch(exception& e) {
        cerr << e.what() << '\n';
        return 1;
    }
    catch(...) {
        cerr << "exception \n";
        return 2;
    }
}


