const char invalid = 'i';
const char number = 'n';
const char quit = 'q';
const char print = ';';
const char name = 'a';


class Token {
    public:
        char kind;
        double val;
        string name;
        Token(char ch) :kind{ch} {}
        Token(char ch, double val) :kind{ch}, val{val} {}
        Token(char ch, string n) :kind{ch}, name{n} {}
};

class Token_stream{
    public:
        Token get();
        void putback(Token t);
        void ignore(char c);
    private:
        Token buffer{invalid};
        bool full = false;
};

