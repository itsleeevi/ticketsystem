#include "date.h"
#include <iostream>
#include <fstream>


/// Paraméterként kapott ostream-re kiírja a dátumot az adatbázisnak megfelelő formában.
void Date::print(std::ostream& os) const {
    os << year << " " << month << " " << day << " " << hour << " " << min;
}

/// Paraméterként kapott fstream-re kiirja a születési dátumhoz szükséges tagváltozókat.
void Date::printBirth(std::ofstream& file) const {
    file << year << " " << month << " " << day;
}

/// "<" operátor overloading-ja, hogy a dátumokról eldönthető legyen melyik kisebb.
bool Date::operator<(const Date& rhs) const {
    return  (((year * 365 * 30 * 24 * 60) + (month * 30 * 24 * 60) + (day * 24 * 60) + (hour * 60) + min) < 
            ((rhs.year * 365 * 30 * 24 * 60) + (rhs.month * 30 * 24 * 60) + (rhs.day * 24 * 60) + (rhs.hour * 60) + rhs.min));
}

/// Dátum átváltása percre.
int Date::toMin() const {
    return (year * 365) + (month * 30 * 24 * 60) + (day * 24 * 60) + (hour * 60) + min;
}

/// Paraméterként kapott ostream-re kiírja a dátumot megjelenítési formában.
void Date::printForTicket(std::ostream& os) const {
    if (min < 10)
        os << year << ". " << month << ". " << day << ". " << hour << ":" << "0" << min;
    else if (min >= 10)
        os << year << ". " << month << ". " << day << ". " << hour << ":" << min;
}

/// Paraméterként kapott ostream-re kiírja a születési dátumot megjelenítési formában.
void Date::printForBirth(std::ostream& os) const {
    if (min < 10)
        os << year << ". " << month << ". " << day << ". ";
    else if (min >= 10)
        os << year << ". " << month << ". " << day << ". ";
}