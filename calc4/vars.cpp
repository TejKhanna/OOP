#include "std_lib_facilities.h"
#include "vars.h"

vector<Variable> var_table;

double get_value(string s)
{
    for(Variable var : var_table)
        if(var.name == s) return var.value;

    return 0.0;
}

void set_value(string s, double d)
{
    for(Variable& var : var_table)
        if(var.name == s) {
            var.value = d;
            return;
        }
    // if var not in table, we choose to add it:
    var_table.push_back(Variable{s, d});
}

void print_vars()
{
    for(Variable var : var_table)
        cout << "Var " << var.name << " = " << var.value << endl;
}

// main for test purposes:
int main()
{
    set_value("foo", 12.2);
    set_value("goo", 16.2);
    set_value("blue", 2.2);
    set_value("foo", 2.9);
    print_vars();
}