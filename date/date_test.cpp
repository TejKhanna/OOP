#include "std_lib_facilities.h"
#include "date.h"


int main(){
	Date today(2018,7,25);
	Date today_again(2018,7,25);
	Date someday(2763,9,14);

//	Date user_date(1000,1,1);

	cout << today << endl;
	string yes_no = "";

	cout << "Enter d to incrament the day, m to incrament the month or y to incrament the year. \nPress e to compare dates with todays date or press q to quit.\nPress n to enter a new date and compare it to todays date.\n";
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
			cout << "Checking current date: " << today << " against current date: " << today << " Results printed below:\n";
			if(today == today){
				cout << "The dates match\n";
			}
			else{
				cout << "The dates do not match\n";
			}
			cout << "Checking current date: " << today << " against another date: " << someday << " Results printed below:\n";
			if(today != someday){
				cout << "The dates do NOT match!\n";
			}
			else
				cout << "The dates match\n";

		}

		// else if(yes_no == "n"){ //input testing
		// 	cin >> user_date;
		// 	cout << user_date;
		// }
		
		cout << "Current date: " << today << endl;
	}
	return 0;
}