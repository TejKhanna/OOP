#include "std_lib_facilities.h"

struct Reading{
    int first;
    char sep1;
    double second;
    char sep2;
    double third;
};

int main()
{
    cout << "Please enter input file name: ";
    string iname;
    cin >> iname;
    ifstream ist {iname};
    if (!ist) error ("can't open input file ", iname);

    string oname;
    cout << "Please enter name of output file: ";
    cin >> oname;
    ofstream ost {oname};
    if (!ost) error("can't open output file ", oname);

    vector <Reading> temps;
    int first;
    double second;
    double third;
    char sep1;
    char sep2;
    while (ist >> first >> sep1  >> second >> sep2 >> third){
        if (first < 0 || 23 < first) error("first out of range");
        temps.push_back(Reading{first, sep1, second, sep2, third});
    }
    for (int i = 0; i<temps.size(); ++i)
    ost  << temps[i].first << '\t' << temps[i].second << '\t' << temps[i].third <<'\n';}
        


