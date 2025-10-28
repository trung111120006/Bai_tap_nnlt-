#include <bits/stdc++.h>

using namespace std;
struct day
{
    int date;
    int month;
    int year;
};
struct tomorrow
{
    day today;
    int days_after;
};
int main (){
    tomorrow t;
    cout << "Enter day, month, year: ";
    cin >> t.today.date >> t.today.month >> t.today.year;
    cout << "Enter number of days to add: ";
    cin >> t.days_after;

    // Simple addition without considering month/year overflow
    t.today.date += t.days_after;

    cout << "New date after adding " << t.days_after << " days is: "
         << t.today.date << "/" << t.today.month << "/" << t.today.year << endl;

    return 0;
}