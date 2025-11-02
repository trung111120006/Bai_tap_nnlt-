#include <bits/stdc++.h>
using namespace std;

struct Date {
    int day;
    int month;
    int year;
};

bool isLeap(int year) {
    return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

Date getTomorrow(Date today) {
    Date next = today;
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // Tháng 2 năm nhuận có 29 ngày
    if (isLeap(today.year)) {
        daysInMonth[2] = 29;
    }

    next.day++;

    if (next.day > daysInMonth[next.month]) {
        next.day = 1;
        next.month++;
        if (next.month > 12) {
            next.month = 1;
            next.year++;
        }
    }

    return next;
}

int main() {
    Date today;
    cout << "Enter today date (dd mm yyyy): ";
    cin >> today.day >> today.month >> today.year;

    Date tmr = getTomorrow(today);

    cout << "Tomorrow date is: ";
    cout << tmr.day << " " << tmr.month << " " << tmr.year << endl;

    return 0;
}
