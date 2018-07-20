#include "std_lib_facilities.h"

const char number = 'n';
const char quit = 'q';
const char print = ';';

class Token {
    public:
        char kind;
        double val;
};

class Token_stream{
    public:
        Token get();
        void putback(Token t);
    private:
        Token buffer;
        bool full = false;
};

void Token_stream::putback(Token t){
    buffer = t;
    full = true;
}

Token Token_stream::get(){
    if(full){
        full = false;
        return buffer;
    }
    char ch;
    cin >> ch;
    switch (ch){
        case ';':
        case quit:
        case'(':
        case')':
        case'+':
        case'-':
        case'*':
        case'/':
        case'%':
            return Token{ch};
        case '0':
        case '1':
        case'2':
        case'3':
        case'4':
        case'5':
        case'6':
        case'7':
        case'8':
        case'9':{
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{number,val};
        }
    }
}

void print_token(Token t){
    if(t.kind == number)
        cout << "Token of kind: " << t.kind << "  " << t.val << endl;
    else
        cout <<"Token of kind: " << t.kind << endl;
}

Token_stream ts;

double expression();
double term();
double primary();

double expression(){
    double left = term();      // read and evaluate a Term
    Token t = ts.get();        // get the next token from token stream
    while(true){

        switch(t.kind) {

        case '+':
            left += term();    // evaluate Term and add
            t = ts.get();
            break;

        case '-':
            left -= term();    // evaluate Term and subtract
            t = ts.get();
            break;

        default:
            ts.putback(t);     // put t back into the token stream
            return left;       // finally: no more + or -: return the answer
        }
    }
}

double term(){
    double left = primary();
    Token t = ts.get();        // get the next token from token stream

    while(true) {
        switch (t.kind) {

        case '*':{
            left *= primary();
            t = ts.get();
            break;
        }

        case '/':{
                double d = primary();
                if (d == 0) error("divide by zero");
                left /= d;
                t = ts.get();
                break;
            }
        case '%':{
            double d = primary();
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

double primary(){
	Token t = ts.get();
    switch (t.kind) {
    case '(':    // handle '(' expression ')'
        {
            double d = expression();
            t = ts.get();
            if (t.kind != ')') error("')' expected");
            return d;
        }
    case number:            // we use 'n' to represent a number
        return t.val;  // return the number's value
    case '-':
        return -primary();
    case '+':
        return primary();
    case quit:
        return 0;
    default:
        error("primary expected");
    }
}

void clean_up_mess(){
    while(true){
        Token t = ts.get();
        if(t.kind == print) return;
    }
}

void calculate(){
    double val = 0.0;
    Token t;

  while(true){
        cout << "> ";
        t = ts.get();
        if(t.kind == quit)
            break;
        if(t.kind == print){
            cout << "= " << val << endl << "> ";
        }
        else
            ts.putback(t);
        val = expression();
    }
/*
    while(cin){
        try {
            cout << "> ";
            Token t = ts.get();
            while(t.kind == print) t = ts.get();
        }
    }
*/

}

int main(){
    try {
        calculate();
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



