#include "std_lib_facilities.h"

int main(){

	char c = 'a';
	int i = 19;
	double d = 10.5;

	char* cp = &c;
	int* ip = &i;
	double* dp = &d;

	cout << "cp = " << cp << " and its value is: " << *cp << " its size is: " << sizeof(c) << endl;
	cout << "ip = " << ip << " and its value is: " << *ip <<  " its size is: " << sizeof(i) << endl;
	cout << "dp = " << dp << " and its value is: " << *dp <<  " its size is: " << sizeof(d) << endl;
};
