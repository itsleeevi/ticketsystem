#ifndef TRIP_H_INCLUDED
#define TRIP_H_INCLUDED

#include <iostream>
#include "date.h"


class Trip {
    Date departure;
    Date arrival;
    std::string from;
    std::string to;
public:
    void setDeparture(int y, int mo, int d, int h, int mi);
    void setDeparture(const Date&);
    void setArrival(int y, int mo, int d, int h, int mi);
    void setArrival(const Date&);
    void setFrom(std::istream& is) { is >> from; }
    void setFrom(std::string inp) { from = inp; }
    void setTo(std::istream& is) { is >> to; }
    void setTo(std::string inp) { to = inp; }
    void printDeparture(std::ostream& os = std::cout) const { departure.printForTicket(os); }
    void printArrival(std::ostream& os = std::cout) const { arrival.printForTicket(os); }
    std::string getFrom() const { return from; }
    std::string getTo() const { return to; }
    Date getDeparture() const { return departure; }
    Date getArrival() const { return arrival; }
};


#endif