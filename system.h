#ifndef SYSTEM_H_INCLUDED
#define SYSTEM_H_INCLUDED
 
#include "railwaystore.h"
#include "train.h"
#include "order.h"
#include "passanger.h"
#include <string>

class System {
    std::string pass;
    railwayStore<Train> trains;
    railwayStore<Train> trainsForOrder;
    railwayStore<Train> potentialTrainsOne;
    railwayStore<Train> potentialTrainsTwo;
    Order ticket;
public:
    System(std::string p = "12345") : pass(p) {}
    void menu();
    void orderSubMenu();
    void addOrder(const Passanger&);
    void addTrain();
    void addTrainToFile(const Train&);
    void fillTrainsFromFile();
    int amountOfTrainsInFile();
    void askPassanger();
    void findTrains(const Passanger&);
    void checkData();
    void subMenu();
    void password();
    void deleteTrainsFromStore() {
        trains.popAll();
        trainsForOrder.popAll();
        potentialTrainsOne.popAll();
        potentialTrainsTwo.popAll();
    }
    ~System() {}
};

#endif