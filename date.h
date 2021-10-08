#ifndef DATE_H_INCLUDED
#define DATE_H_INCLUDED

#include <iostream>


struct Date {
    int year;
    int month;
    int day;
    int hour;
    int min;
    void print(std::ostream& os = std::cout) const;
    void printBirth(std::ofstream& file) const;
    void printForTicket(std::ostream& os = std::cout) const;
    void printForBirth(std::ostream& os = std::cout) const;
    bool operator==(const Date& rhs) const {
        return ((year == rhs.year) && (month == rhs.month) && (day == rhs.day) && (hour == rhs.hour) && (min == rhs.min));
    }
    bool operator<(const Date& rhs) const;
    int toMin() const;
};


#endif
