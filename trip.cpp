#include "trip.h"


void Trip::setDeparture(int y, int mo, int d, int h, int mi) {
    departure.year = y;
    departure.month = mo;
    departure.day = d;
    departure.hour = h;
    departure.min = mi;
}

void Trip::setArrival(int y, int mo, int d, int h, int mi) {
    arrival.year = y;
    arrival.month = mo;
    arrival.day = d;
    arrival.hour = h;
    arrival.min = mi;
}

void Trip::setDeparture(const Date& rhs) {
    departure.year = rhs.year;
    departure.month = rhs.month;
    departure.day = rhs.day;
    departure.hour = rhs.hour;
    departure.min = rhs.min;
}

void Trip::setArrival(const Date& rhs) {
    arrival.year = rhs.year;
    arrival.month = rhs.month;
    arrival.day = rhs.day;
    arrival.hour = rhs.hour;
    arrival.min = rhs.min;
}