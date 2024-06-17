#include "euler_utils.h"

struct Date {
    int day, month, year;
    int weekday;

    Date(int day, int month, int year, int weekday = 0) : day(day), month(month), year(year), weekday(weekday) { }

    bool isSunday() const { return weekday == 6; }

    bool operator<(const Date& other)
    {
        return (year < other.year)
            || (year == other.year && month < other.month)
            || (year == other.year && month == other.month && day < other.day);
    }

    Date& operator++()
    {
        weekday = (weekday + 1) % 7;
        if ( day < getDaysInMonth(year, month) ) {
            ++day;
        }
        else {
            if ( month == 12 ) {
                month = 1;
                ++year;
            }
            else {
                ++month;
            }
            day = 1;
        }

        return *this;
    }

    friend std::ostream& operator<<(std::ostream& os, const Date& date)
    {
        switch ( date.weekday ) {
            case 0: os << "Mon. "; break;
            case 1: os << "Tue. "; break;
            case 2: os << "Wed. "; break;
            case 3: os << "Thu. "; break;
            case 4: os << "Fri. "; break;
            case 5: os << "Sat. "; break;
            case 6: os << "Sun. "; break;
            default: os << "WTF. "; break;
        }

        return os << (date.day < 10 ? "0" : "") << date.day << "." << (date.month < 10 ? "0" : "") << date.month << "." << date.year;
    }

    static bool isLeapYear(int year)
    {
        if ( year % 4 == 0 ) {
            if ( year % 100 == 0 ) {
                return (year % 400 == 0);
            }

            return true;
        }

        return false;
    }

    static int getDaysInMonth(int year, int month)
    {
        assert(0 < month && month <= 12 && "month must be in range [1, 12]");

        switch ( month ) {
            case 1:     return 31;
            case 2:     return (isLeapYear(year) ? 29 : 28);
            case 3:     return 31;
            case 4:     return 30;
            case 5:     return 31;
            case 6:     return 30;
            case 7:     return 31;
            case 8:     return 31;
            case 9:     return 30;
            case 10:    return 31;
            case 11:    return 30;
            case 12:    return 31;
            default: return -1;
        }
    }
};

size_t solve_problem_19()
{
    size_t result = 0;

    Date date(1, 1, 1900);
    while ( date.year < 1901 ) {
        ++date;
    }

    while ( date < Date(31, 12, 2000) ) {
        if ( date.isSunday() && date.day == 1 ) {
            ++result;
        }
        ++date;
    }

    ASSERT_EQUAL(result, 171);
    return result;
}

REGISTER_PROBLEM(solve_problem_19, 19)
