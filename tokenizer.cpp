#include "std_lib_facilities.h"

class Token {
    public:
        char kind;
        double val;
};
 Token get_token();

 vector<Token> tokens;

Token get_token(){
    char ch;
    cin >> ch;
    switch (ch){
        case ';': case 'q': case'(': case')': case'+': case'-': case'*': case'/': case'%': return Token{ch};
        case '0': case '1': case'2':case'3':case'4':case'5':case'6':case'7':case'8':case'9':{
            cin.putback(ch);
            double val;
            cin >> val;
            return Token{'n',val};
        }
    }
};

int main(){

    cout << "Please enter a mathematical expression, followed by the character q to quit.\n";
    for(Token t = get_token(); t.kind != 'q'; t = get_token()){
        tokens.push_back(t);
    }
    for(Token tok : tokens){
        if(tok.kind == 'n'){
            cout << "A number of value " << tok.val << endl;
        }
        else{
            cout << "A token of type " << tok.kind << endl;
        }
    }
}