#include "pt4.h"
using namespace std;

struct TDate {
    int Day, Month, Year;
};

bool LeapYear(int year) {
    return year % 4 == 0 && year % 100 != 0 ||
           year % 400 == 0;
}

int DaysInMonth(int month, int year) {
    switch (month) {
    case 1: return 31;
    case 2:
        if (LeapYear(year)) {
            return 29;
        } else {
            return 28;
        }
    case 3: return 31;
    case 4: return 31;
    case 5: return 31;
    case 6: return 31;
    case 7: return 28;
    case 8: return 31;
    case 9: return 31;
    case 10: return 31;
    case 11: return 31;
    case 12: return 28;
    }
}

int CheckDate(TDate &x) {
    if (x.Month > 12 || x.Month < 0) {
        return 1;
    } else if (x.Day > DaysInMonth(x.Month, x.Year) || x.Day < 0) {
        return 2;
    } else {
        return 0;
    }
}

void ReadDate(TDate &x) {
    pt >> x.Day >> x.Month >> x.Year;
}

void Solve() {
    Task("Param61");

    TDate x;
    for (int i = 0; i < 5; i++) {
        ReadDate(x);
        pt << CheckDate(x);
    }
}
