#include "std_lib_facilities.h"
#include "date.h"

int main(){
	Date today(2018,7,25);
	Date today_again(2018,7,25);
	Date someday(2763,9,14);
	// Date user_date;
	cout << today << endl;
	string yes_no = "";

	int user_day;
	int user_month;
	int user_year;

	cout << "Enter d to incrament the day, m to incrament the month or y to incrament the year. \nPress e to compare dates with todays date or press q to quit.\n";
	while(yes_no != "q"){
		cin >> yes_no;
		if (yes_no == "d"){
			today.add_day(0);
		}
		else if(yes_no == "m"){
			today.add_month();
		}
		else if(yes_no == "y"){
			today.add_year();
		}
		else if(yes_no == "e"){
			cout << "Checking todays date: " << today << " against todays date: " << today_again << " Results printed below:\n";
			if(today == today_again){
				cout << "The dates match\n";
			}
			else{
				cout << "The dates do not match\n";
			}

		}
		// else if(yes_no == "n"){
		// 	cout << "Please enter a year: ";
		// 	cin >> user_day;
		// 	cout << "\nPlease enter a month: ";
		// 	cin >> user_month;
		// 	cout << "\nPlease enter a day: ";
		// 	cin >> user_year;

		// 	user_date.d = user_day;
		// 	user_date.m = user_month;
		// 	user_date.y = user_year;

		// 	Date user_date(user_year,user_month,user_day);

			// if(user_date == today)
			// 	cout << "These are the same dates!\n"
			// else
			// 	cout << "These are not the same dates.\n"
		
		cout << today << endl;
	}
	return 0;
}