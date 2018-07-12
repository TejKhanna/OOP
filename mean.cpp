#include "std_lib_facilities.h"

int main()
{
    cout << "Enter recent temperatures and we will calculate their average:\n";

    vector<double> temps;

    for(double temp; cin>>temp; )
        temps.push_back(temp);

    double total = 0.0;

    for(double temp : temps)
        total += temp;

    sort(temps);

    double median;

    for (double temp : temps.size()/2)
        median = temp;

    double mean = total / temps.size();

    cout<<"Your mean temperature for the last "<<temps.size()<<" days was "<<mean<<"\n" << "The median of the temperatures was:" << median;

    keep_window_open();
    return 0;
}