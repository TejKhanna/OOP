#include "std_lib_facilities.h"
#include "date.h"

Date::Date (int yy, int mm, int dd)
:y{yy}, m{mm}, d{dd}
{
	if(!is_valid())
		throw Invalid{};
}

const Date& default_date()
{
	static Date d {2001,1,1};
	return d;
}

// Date::Date()
// 	:y{default_date().y},
// 	m{default_date().m},
// 	d{default_date().d}
// {}

bool Date::leap_year(){
	if(y%4 == 0)
		return true;
	else
		return false;
}

// The next three functions are operator overloads. They allow us to use == != and cout with the date type.



ostream& operator << (ostream& os, const Date d){
//	Vector 

	return os << '(' << d.year() << ',' << d.month() << ',' << d.day() << ')';
}

// istream& operator >> (istream& is, const Date& d){
// 	int user_year, user_month, user_day;
// 	char ch1, ch2, ch3, ch4;
// 	is >> ch1 >> user_year >> ch2 >> user_month >> ch3 >> user_day >> ch4;
// 	// if(!is_valid()) return is_valid;
// 	if(ch1!='(' || ch2!=',' || ch3!=',' || ch4!=')')
// 	{
// 		cout << "There seems to be an error with your input.";
// 	}

// 	d = Date{user_year,user_month,user_day};
// 	return is;
// }

bool operator == (const Date& d1, const Date d2){
	if (d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year())
		return true;
	else
		return false;
}

bool operator != (const Date& d1, const Date d2){
	if (d1.day() == d2.day() && d1.month() == d2.month() && d1.year() == d2.year())
		return false;
	else
		return true;
}

//This function validates the date, and can be used to throw an exception in the main.

bool Date::is_valid(){
	// cout << "The month is " << m << endl;
	if(y<0)
		return false;

	if(m<1 || m>12)
		return false;

	switch (m){
		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		case 12:
			if(d<1 || d> 31)
				return false;
		case 4:
		case 6:
		case 9:
		case 11:
			if(d<1 || d>30)
				return false;
		case 2:
			if(leap_year()){
				if (d<1 || d>29)
					return false;
			}
			else{
				if(d<1 || d>28)
					return false;
			}

	}

	return true;
}

void Date::add_day(int n)
{
	switch (m){
		case 12:
		{
			if(d==31){
				y++;
				m = 1;
				d = 1;
				return;
			}
			else{
				d++;
				return;
			}
		}

		case 1:
		case 3:
		case 5:
		case 7:
		case 8:
		case 10:
		{
			if(d==31){
				m++;
				d = 1;
				return;
			} 
			else{
				//cout << "added a day in the 31 category\n"; //uncomment for debugging
				d++;
				return;
			}
		}

		case 4:
		case 6:
		case 9:
		case 11:
		{
			if(d==30){
				m++;
				d = 1;
				return;
			}
			else {
				//cout << "added a day in the 30 category\n"; //uncomment for debugging
				d++;
				return;
			}
		}
		case 2:
		{
			if(leap_year())
				if(d==29){
					m++;
					d=1;
					return;
				}
				else{
					//cout << "added a day in the 39 category\n"; //uncomment for debugging
					d++;
					return;
				}	
			else{
				if(d==28){
					m++;
					d=1;
					return;
				}
				else{
					// cout << "added a day in the 28 category\n"; //uncomment for debugging
					d++;
					return;
				}
			}
		}
	}

}

void Date :: add_month()
{
	switch(m){
		case 1:
		case 2:
		case 3:
		case 4:
		case 5:
		case 6:
		case 7:
		case 8:
		case 9:
		case 10:
		case 11:
			{
				m++;
				return;
			}
		case 12:
			{
				y++;
				m=1;
				return;
			}
	}
}

void Date :: add_year()
{
	y++;
	return;
}

int Date::month(){
	return m;
}

int Date::day(){
	return d;
}

int Date::year(){
	return y;
}

//for adding custom function later, potential scheduler using date object and TIME object
//an age calculator
//enter a year and it returns the x fact of that year