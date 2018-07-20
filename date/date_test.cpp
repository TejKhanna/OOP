#include "std_lib_facilities.h"
#include "date.h"

struct Date{
	int y;
	int m;
	int d;
};

int main(){
	Date today;
	today.m = 7;
	today.d = 20;
	today.y = 2018;
	cout << today.m << '/' << today.d << '/' << today.y << endl;
	return 0;
}