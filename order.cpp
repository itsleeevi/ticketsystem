#include "order.h"
#include <sstream>


/// Megjelenítési formában kiírja az aktuálisan megadott felhasználó adatait, illetve ezeknek az adatoknak megfelelő vonatot vagy átszállás esetén vonatokat.
void Order::printData() {
    std::cout << std::endl << "SZEMELYES ADATOK" << std::endl;
    std::cout << "Nev: " << customer[0].getName() << std::endl;
    std::cout << "Szuletesi datum: ";
    customer[0].getBirth().printForBirth();
    std::cout << "\nIndulasi hely: " << customer[0].getFrom();
    std::cout << "\nUticel: " << customer[0].getTo();
    std::cout << "\nMegadott indulasi idopont: ";
    customer[0].getDeparture().printForTicket();
    std::cout << std::endl;
    if (trainsOnTicket.size() == 1) {
        std::cout << std::endl << "A MEGADOTT INDULASI IDOPONTHOZ KEPEST LEGHAMARABB INDULO VONAT:" << std::endl;
        trainsOnTicket[0].printTrain();
    }
    else if (trainsOnTicket.size() > 1) {
        std::cout << std::endl << "A MEGADOTT INDULASI IDOPONTHOZ KEPEST LEGHAMARABB INDULO VONATOK:" << std::endl;
        trainsOnTicket[0].printTrain();
        std::cout << "***** ATSZALLAS *****" << std::endl;
        trainsOnTicket[1].printTrain();
    }
    else if (trainsOnTicket.size() == 0) {
           std::cout << std::endl << "Sajnos, a megadott allomasok kozott nem kozlekednek vonatok! :(" << std::endl;
    }
}

/// A rendelések megkülönböztetéséhez generál azonosítót.
void Order::genOrderID() {
    srand(time(0));
    int n;
    n = rand()%10000+100;
    std::ostringstream temp;
    temp << n;
    orderID = "OR_" + temp.str();
}

/// Az adatbázisnak megfelelő formában kiírja a paraméterként adott file-ba (ami az adatbázis, data.txt) a rendelés adatait.
void Order::printDataToFile(std::ofstream& file) {
    if (trainsOnTicket.size() == 1) {
        // SZEMELYES ADATOK
        file << orderID << " " << customer[0].getName() << " ";
        customer[0].getBirth().printBirth(file);
        // VONAT ADATAI
        file << " " << trainsOnTicket[0].getTrainID() << " "; 
        trainsOnTicket[0].getDeparture().print(file);
        file << " ";
        trainsOnTicket[0].getArrival().print(file);
        file << " ";
	    file << trainsOnTicket[0].getFrom() << " " << trainsOnTicket[0].getTo() << std::endl;
    }
    else if (trainsOnTicket.size() > 1) {
        // SZEMELYES ADATOK
        file << orderID << " " << customer[0].getName() << " ";
        customer[0].getBirth().printBirth(file);
        // VONAT1 ADATAI
        file << " " << trainsOnTicket[0].getTrainID() << " "; 
        trainsOnTicket[0].getDeparture().print(file);
        file << " ";
        trainsOnTicket[0].getArrival().print(file);
        file << " ";
	    file << trainsOnTicket[0].getFrom() << " " << trainsOnTicket[0].getTo();
        // VONAT2 ADATAI
        file << " " << trainsOnTicket[1].getTrainID() << " "; 
        trainsOnTicket[1].getDeparture().print(file);
        file << " ";
        trainsOnTicket[1].getArrival().print(file);
        file << " ";
	    file << trainsOnTicket[1].getFrom() << " " << trainsOnTicket[1].getTo() << std::endl;
    }
}

/// Az elkészült rendelésnek létrehoz a generált egyedi azonosítóval megnevezve egy .txt file-t, amibe kiírja a rendelés adatait (elkészíti a jegyet).
void Order::printTicketToNewFile() {
    std::string fileName = orderID + ".txt";
    std::ofstream file;
    file.open(fileName, std::ofstream::app);
    if (trainsOnTicket.size() == 1) {
        file << "************************* JEGY *************************" << std::endl;
        file << std::endl << " Nev: " << customer[0].getName() << std::endl;
        file << " Szuletesi datum: ";
        customer[0].getBirth().printForBirth(file);
        file << std::endl;
        file << std::endl << " Vonat neve: " << trainsOnTicket[0].getTrainID() << std::endl;
        file << " Indulas: ";
        trainsOnTicket[0].getDeparture().printForTicket(file);
        file << std::endl;
        file << " Erkezes: ";
        trainsOnTicket[0].getArrival().printForTicket(file);
        file << std::endl;
        file << " Honnan: " << trainsOnTicket[0].getFrom() << std::endl;
        file << " Hova: "  << trainsOnTicket[0].getTo() << std::endl << std::endl;
        file << "********************************************************";
    }
    else if (trainsOnTicket.size() > 1) {
        file << "************************* JEGY *************************" << std::endl;
        file << std::endl << " Nev: " << customer[0].getName() << std::endl;
        file << " Szuletesi datum: ";
        customer[0].getBirth().printForBirth(file);
        file << std::endl;
        file << std::endl <<  " Vonat neve: " << trainsOnTicket[0].getTrainID() << std::endl;
        file << " Indulas: ";
        trainsOnTicket[0].getDeparture().printForTicket(file);
        file << std::endl;
        file <<  " Erkezes: ";
        trainsOnTicket[0].getArrival().printForTicket(file);
        file << std::endl;
        file << " Honnan: " << trainsOnTicket[0].getFrom() << std::endl;
        file << " Hova: "  << trainsOnTicket[0].getTo() << std::endl;
        file << " ***** ATSZALLAS *****";
        file << std::endl << " Vonat neve: " << trainsOnTicket[1].getTrainID() << std::endl;
        file << " Indulas: ";
        trainsOnTicket[1].getDeparture().printForTicket(file);
        file << std::endl;
        file << " Erkezes: ";
        trainsOnTicket[1].getArrival().printForTicket(file);
        file << std::endl;
        file << " Honnan: " << trainsOnTicket[1].getFrom() << std::endl;
        file << " Hova: "  << trainsOnTicket[1].getTo() << std::endl << std::endl;
        file << "********************************************************";
    }
}