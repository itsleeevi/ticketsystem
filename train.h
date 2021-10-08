#ifndef TRAIN_H_INCLUDED
#define TRAIN_H_INCLUDED

#include "trip.h"
#include <string>
#include <iostream>
#include <fstream>


class Train : public Trip {
    std::string trainID;
    int cars;
public:
    Train() {}
    void trainFromFile(std::ifstream& file);
    void setTrainID(std::string id) { trainID = id; }
    int getCars() const { return cars; }
    void setCars(std::istream& is) { is >> cars; }
    void setCars(int n) { cars = n; }
    std::string genTrainID();
    std::string getTrainID() const { return trainID; }
    void printTrain() const;
};

#endif