#ifndef ORDER_H_INCLUDED
#define ORDER_H_INCLUDED

#include "railwaystore.h"
#include "date.h"
#include "train.h"
#include "passanger.h"
#include <string>


class Order {
    railwayStore<Passanger> customer;
    std::string orderID;
    Date orderDate;
    railwayStore<Train> trainsOnTicket;
    int car;
    int seat;
public:
    Order() {}
    void addTrain(const Train& rhs) { trainsOnTicket.push_back(rhs); }
    void addPassanger(const Passanger& rhs) { customer.push_back(rhs); }
    void printData();
    void printDataToFile(std::ofstream& file);
    void genOrderID();
    int getTrainsOnTicketSize() { return trainsOnTicket.size(); }
    std::string getCustomerName() const { return customer[0].getName(); }
    Date getCustomerBirth() const { return customer[0].getBirth(); }
    std::string getOrderID() const { return orderID; }
    void printTicketToNewFile();
    void deleteCustomerAndTrains() { 
        customer.popAll();
        trainsOnTicket.popAll();
    }
};


#endif