#pragma once

class Date{
	public:
		Date(int y, int m, int d);
		class Invalid{};
		void add_day(int n);
		void add_month();
		void add_year();
		int month();
		int day();
		int year();
		bool is_valid();
		int year() const{return y;}
		int month() const{return m;}
		int day() const{return d;}
		
	private:
		bool leap_year();
		int y,m,d;
};

ostream& operator << (ostream& os, const Date d);
istream& operator >> (istream& is, const Date d);
bool operator == (const Date& d1, const Date d2);
bool operator != (const Date& d1, const Date d2);
