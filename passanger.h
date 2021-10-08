#ifndef PASSANGER_H_INCLUDED
#define PASSANGER_H_INCLUDED

#include "date.h"
#include "trip.h"
#include <string>


class Passanger : public Trip {
    std::string name;
    Date birth;
public:
    Passanger() {}
    std::string getName() const { return name; }
    Date getBirth() const { return birth; }
    void setBirth(int y, int mo, int d) {
        birth.year = y;
        birth.month = mo;
        birth.day = d;
    }
    void setName(std::string n) { name = n; }
    ~Passanger() {}
};


#endif