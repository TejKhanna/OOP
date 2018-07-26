#include "std_lib_facilities.h"
#include "token.h"

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
        case'=':
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
    default:
    if(isalpha(ch)){
        string s;
        s += ch;
        while(cin.get(ch) && isalpha(ch)) s += ch;
        cin.putback(ch);
        return Token(name,s);
    }
    return Token{invalid, double(ch)};
    }
    return Token{quit};
}


//this main is to test the variable functionality, comment it out if you want to use the calc.
/*
int main()
{
 Token_stream ts;
 vector<Token> tokens;
    // frazzyswizel!
    for(Token t = ts.get(); t.kind != 'q'; t = ts.get()) {
    	tokens.push_back(t);
	}

	for(Token tok : tokens) {
        if(tok.kind == '8')
		    cout << "A number token with val = " << tok.val << '\n';
        else if(tok.kind == 'i')
		    cout << "We received an invalid token of value "
                << char(tok.val) << '\n';
        else if(tok.kind == name)
            cout << "A variable with name " << tok.name;
        else
		    cout << "A token of kind " << tok.kind << '\n';
	}
    return 0;
}
*/

