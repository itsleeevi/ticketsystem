#include "train.h"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

/// A vonatok megkülönböztetése céljából generál egy egyedi azonosítót.
std::string Train::genTrainID() {
    std::string str;
    srand(time(0));
    int n;
    n = rand()%10000+100;
    std::ostringstream temp;
    temp << n;
    str = "TR_" + temp.str();
    return str;
}

/// Felhasználói szemnek megfelelő módon szabványos kimenetre kiírja a vonat adatait.
void Train::printTrain() const {
    std::cout << "Vonat neve: " << getTrainID() << std::endl;
    std::cout << "Indulas datuma: ";
    printDeparture();
    std::cout << std::endl;
    std::cout << "Erkezes datuma: ";
    printArrival();
    std::cout << std::endl;
    std::cout << "Honnan: " << getFrom() << std::endl;
    std::cout << "Hova: " << getTo() << std::endl;
}