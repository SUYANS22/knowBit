#include "calendar.h"

#include <iostream>
#include <iomanip>
#include <ctime>

using namespace std;

// LEAP YEAR
bool isLeapYear(int year){

    return (year % 4 == 0 &&
           (year % 100 != 0 ||
            year % 400 == 0));
}

// DAYS IN MONTH
int getDaysInMonth(int month, int year){

    int days[] =
    {31,28,31,30,31,30,31,31,30,31,30,31};

    if(month == 2 && isLeapYear(year))
        return 29;

    return days[month - 1];
}

// MONTH NAME
string getMonthName(int month){

    string m[] =
    {"January","February","March","April",
     "May","June","July","August",
     "September","October","November","December"};

    return m[month - 1];
}

// START DAY OF MONTH
int getStartDay(int month, int year){

    tm time_in = {};

    time_in.tm_year = year - 1900;
    time_in.tm_mon = month - 1;
    time_in.tm_mday = 1;

    mktime(&time_in);

    return time_in.tm_wday;
}

// CHECK TASK ON DATE
bool hasTaskOnDate(int day, int month, int year){

    for(const auto &t : allTasks){

        if(t.dueDay == day &&
           t.dueMonth == month &&
           t.dueYear == year){

            return true;
        }
    }

    return false;
}

// DISPLAY CALENDAR
void displayCalendar(){

    time_t now = time(0);
    tm *ltm = localtime(&now);

    int today = ltm->tm_mday;
    int month = ltm->tm_mon + 1;
    int year = ltm->tm_year + 1900;

    int days = getDaysInMonth(month, year);
    int start = getStartDay(month, year);

    cout << "\n";
    cout << "=====================================================\n";
    cout << "                 " << getMonthName(month)
         << " " << year << "\n";
    cout << "=====================================================\n";

    cout << " Sun Mon Tue Wed Thu Fri Sat\n";
    cout << "-----------------------------------------------------\n";

    for(int i = 0; i < start; i++)
        cout << "    ";

    for(int d = 1; d <= days; d++){

        if(d == today)
            cout << "  (" << d << ")";
        else
            cout << setw(4) << d;

        if((start + d) % 7 == 0)
            cout << "\n";
    }

    cout << "\n\n";
    cout << "( ) = Today\n";

    cout << "\n=====================================================\n";
    cout << "                 UPCOMING DEADLINES\n";
    cout << "=====================================================\n";

    bool found = false;

    for(const auto &t : allTasks){

        if(!t.isCompleted){

            found = true;

            cout << setw(2) << t.dueDay << "/"
                 << setw(2) << t.dueMonth << "/"
                 << t.dueYear
                 << "  ->  "
                 << t.taskName
                 << "\n";
        }
    }

    if(!found){

        cout << "No pending deadlines.\n";
    }

    cout << "=====================================================\n";
}