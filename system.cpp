#include "system.h"
#include <iostream>
#include <sstream>


//////////////////////////////////////////////////// Új vonat hozzáadása ///////////////////////////////////////////////////////

/// A START Menu.
void System::menu() {
    int choice = 0;
	std::cout << "************************* BME-VASUTAK START *************************" << std::endl;
	std::cout << std::endl << "(1): Jegyvasarlas" << std::endl;
	std::cout << "(2): Uj vonat hozzaadasa" << std::endl;
	std::cout << "(3): Kilepes" << std::endl;
	std::cin >> choice;
	switch(choice) {
	case 1:
		askPassanger();
		break;
	case 2:
		password();
		break;
    case 3:
        return;
        break;
	default:
		std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
		//menu();
		break;
	}
}

/// Jelszót kezel új vonat hozzáadása előtt.
void System::password() {
    //std::system("clear");
	std::cout << "************************* UJ VONAT HOZZAADASA *************************" << std::endl;
    std::cout << std::endl << "Jelszo: ";
    std::cin >> pass;
    do {
        if (pass.compare(pass) == 0) {
            addTrain();
        }
        else {
            int choice = 0;
            //std::system("clear");
            std::cout << "************************* HIBAS JELSZO! *************************" << std::endl;
            std::cout << std::endl << "(1): Ujraprobalkozas" << std::endl;
            std::cout << "(2): START Menu" << std::endl;
            std::cout << "(3): Kilepes" << std::endl;
            std::cin >> choice;
            switch(choice) {
            case 1:
                password();
                break;
            case 2:
                menu();
                break;
            case 3:
                return;
                break;
            default:
                std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
                break;
            }
        }
    } while (pass.compare(pass) != 0);
}

/// Bekéri az újonnan hozzáadni kívánt vonat adatait.
void System::addTrain() {
    //std::system("clear");
    Train result;
	std::cout << "************************* UJ VONAT HOZZAADASA *************************" << std::endl;
    std::cout << std::endl << "Indulas datuma: \nEv(eeee): ";
    int departureDate[4];
    std::cin >> departureDate[0];
    std::cout << "Honap(hh): ";
    std::cin >> departureDate[1];
    std::cout << "Nap(nn): ";
    std::cin >> departureDate[2];;
    std::cout << "Ora(oo): ";
    std::cin >> departureDate[3];
    std::cout << "Perc(pp): ";
    std::cin >> departureDate[4];
    result.setDeparture(departureDate[0], departureDate[1], departureDate[2], departureDate[3], departureDate[4]);
    //std::system("clear");
    std::cout << "************************* UJ VONAT HOZZAADASA *************************" << std::endl;
    std::cout << std::endl << "Erkezes datuma: \nEv: ";
    int arrivalDate[4];
    std::cin >> arrivalDate[0];
    std::cout << "Honap(hh): ";
    std::cin >> arrivalDate[1];
    std::cout << "Nap(nn): ";
    std::cin >> arrivalDate[2];
    std::cout << "Ora(oo): ";
    std::cin >> arrivalDate[3];
    std::cout << "Perc(pp): ";
    std::cin >> arrivalDate[4];
    result.setArrival(arrivalDate[0], arrivalDate[1], arrivalDate[2], arrivalDate[3], arrivalDate[4]);
    std::cout << std::endl << "Indulas helye: ";
    result.setFrom(std::cin);
    std::cout << std::endl << "Erkezes helye: ";
    result.setTo(std::cin);
    std::cout << std::endl << "Kocsik szama: ";
    result.setCars(std::cin);
    result.setTrainID(result.genTrainID());
    addTrainToFile(result);
}

/// A megadott, új vonat adatait kiírja az adatbázisba (data.txt).
void System::addTrainToFile(const Train& rhs) {
    //std::system("clear");
    std::ofstream file;
    file.open("data.txt", std::ofstream::app);
    if (!file) {
        throw std::runtime_error("Hiba tortent a fajl megnyitasakor!");
    }
    std::cout << "************************* UJ VONAT HOZZAADASA *************************" << std::endl;
    std::cout << std::endl << "(1): Mentes" << std::endl;
    std::cout << "(2): Uj vonat mentes nelkul" << std::endl;
    std:: cout << "(3): START Menu" << std::endl;
    int choice = 0;
    std::cin >> choice;
	switch(choice) {
	case 1:
		file << rhs.getTrainID() << " ";
        rhs.getDeparture().print(file);
        file << " ";
        rhs.getArrival().print(file);
        file << " " << rhs.getCars() << " " << rhs.getFrom() << " " << rhs.getTo() << std::endl;
        file.close();
        subMenu();
		break;
	case 2:
        file.close();
	    addTrain();
		break;
    case 3:
        file.close();
        menu();
        break;
	default:
		std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
        //addTrainToFile(rhs);
		break;
	}
}

/// Egy menüt valósít meg, ami az új vonat data.txt file-ba kiírása után jelenik meg.
void System::subMenu() {
    //std::system("clear");
    std::cout << "************************* A VONAT SIKERESEN ELMENTVE! *************************" << std::endl;
    std::cout << std::endl << "(1): Uj vonat" << std::endl;
    std::cout << "(2): START Menu" << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch(choice) {
	case 1:
		addTrain();
		break;
	case 2:
	    menu();
		break;
	default:
		std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
		break;
	}
}

//////////////////////////////////////////////////// Jegyvasarlas ///////////////////////////////////////////////////////

/// A jegyvásárlás esetén használt függvényeket hívja meg, a működéshez megfelelő futási sorrendben.
void System::addOrder(const Passanger& user) {
    //std::system("clear");
    fillTrainsFromFile();
    findTrains(user);
    checkData();
}

/// Bekéri a felhasználótól a személyes adatokat, illetve az utazás időpontját.
void System::askPassanger() {
    Passanger user;
    //std::system("clear");
    std::cout << "************************* JEGYVASARLAS *************************" << std::endl;
    //SZEMÉLYES ADATOK
    std::cout << std::endl << "Nev: " ;
    std::cin.ignore();
    std::string name;
    std::getline(std::cin, name);
    user.setName(name);
    std::cout << std::endl << "Szuletesi datum: \nEv(eeee): ";
    int birthDate[2];
    std::cin >> birthDate[0];
    std::cout << "Honap(hh): ";
    std::cin >> birthDate[1];
    std::cout << "Nap(nn): ";
    std::cin >> birthDate[2];
    user.setBirth(birthDate[0], birthDate[1], birthDate[2]);
    //UTAZÁS ADATAI
    std::cout << std::endl << "Indulas datuma: \nEv(eeee): ";
    int departureDate[4];
    std::cin >> departureDate[0];
    std::cout << "Honap(hh): ";
    std::cin >> departureDate[1];
    std::cout << "Nap(nn): ";
    std::cin >> departureDate[2];;
    std::cout << "Ora(oo): ";
    std::cin >> departureDate[3];
    std::cout << "Perc(pp): ";
    std::cin >> departureDate[4];
    user.setDeparture(departureDate[0], departureDate[1], departureDate[2], departureDate[3], departureDate[4]); 
    std::cout << std::endl << "Honnan: ";
    user.setFrom(std::cin);
    std::cout << std::endl << "Hova: ";
    user.setTo(std::cin);
    ticket.addPassanger(user);
    addOrder(user);
}

/// Megszámolja, hogy az adatbázisban (data.txt) hány darab vonat van.
int System::amountOfTrainsInFile() {
    std::ifstream file;
    file.open("data.txt", std::ifstream::app);
    if (!file) {
        throw std::runtime_error("Hiba tortent a fajl megnyitasakor!");
    }
    std::string ID, line;
    int cnt = 0;
    while (std::getline(file, line)) {
        std::istringstream iline(line);
        std::getline(iline, ID, '_');
        if (ID.compare("TR") == 0)
            cnt++;
    }
    file.close();
    return cnt;
}

/// Az adatbázisban található összes vonatot betölti egy dinamikus memóriakezelést használó, railwayStore tárolóba - "railwayStore<Train> trains".
void System::fillTrainsFromFile() {
    std::ifstream file;
    file.open("data.txt", std::ifstream::app);
    if (!file) {
        throw std::runtime_error("Hiba tortent a fajl megnyitasakor!");
    }
    std::string dataOfTheLine[14]; 
    /*
    dataOfTheLine[] tomb tartalma
        dataOfTheLine[0]: trainID
        dataOfTheLine[1]: departureYear
        dataOfTheLine[2]: departureMonth
        dataOfTheLine[3]: departureDay
        dataOfTheLine[4]: departureHour
        dataOfTheLine[5]: departureMin
        dataOfTheLine[6]: arrivalYear
        dataOfTheLine[7]: arrivalMonth
        dataOfTheLine[8]: arrivalDay
        dataOfTheLine[9]: arrivalHour
        dataOfTheLine[10]: arrivalMin
        dataOfTheLine[11]: cars
        dataOfTheLine[12]: from
        dataOfTheLine[13]: to
    */
    int inInteger[10]; //dataOfTheLine tartalma 1-11-ig, integerkent
    std::string line;
    std::string ID;
    Train train;
    while (std::getline(file, line)) {
        std::istringstream iline(line);
        std::istringstream otherLine(line);
        std::getline(iline, ID, '_');
        if (ID.compare("TR") == 0) {
            int j = 0;
            for (int i = 0; i < 14; ++i) {
                std::getline(otherLine, dataOfTheLine[i], ' ');
                if (i > 0 && i < 12) {
                    std::stringstream fromString(dataOfTheLine[i]);
                    fromString >> inInteger[j++];
                }
            }
            train.setTrainID(dataOfTheLine[0]);
            train.setDeparture(inInteger[0], inInteger[1], inInteger[2], inInteger[3], inInteger[4]);
            train.setArrival(inInteger[5], inInteger[6], inInteger[7], inInteger[8], inInteger[9]);
            train.setCars(inInteger[10]);
            train.setFrom(dataOfTheLine[12]);
            train.setTo(dataOfTheLine[13]);
            trains.push_back(train);
        }
    }
}

/// A "trains" tárolóba betöltött vonatok közül megkeresi a felhasználótól bekért utazás időpontjához legközelebb álló vonatot vagy átszállás esetén vonatokat.
void System::findTrains(const Passanger& user) {
    for (int i = 0; i < amountOfTrainsInFile(); ++i) {
        if (((trains[i].getFrom() == user.getFrom()) || 
             (trains[i].getTo() == user.getTo())) && 
             (trains[i].getDeparture().toMin() >= user.getDeparture().toMin())) {
        // Kigyüjti azokat a vonatokat, melyeknek a felhasználó adataival egyezik az indulási vagy érkezési helye, 
        // illetve amik nem korábbiak az utazás időpontjától.
            if (trains[i].getFrom() == user.getFrom() && trains[i].getTo() == user.getTo()) {
            // Ha van olyan vonat, aminek megyegyezik az indulási helye és érkezési helye is a felhasználó adatival, 
            // akkor megtalálja a keresett vonatok egy halmazát.
            // A megtalált lehetséges vonatokat beteszi a "potentialTrainsOne" tárolóba.
                potentialTrainsOne.push_back(trains[i]);
            }
            else {
                for (int j = 0; j < amountOfTrainsInFile(); ++j) {
                    if (trains[i].getTo() == trains[j].getFrom() && 
                        trains[j].getTo() == user.getTo() && 
                        trains[j].getDeparture().toMin() > trains[i].getArrival().toMin()) {
                    // Ha feljebb, az előző feltételnek megfelelő egyetlen egy vonat sem létezik, akkor behoz a képbe egy második vonatot,
                    // aminek indulási helye megegyezik az első vonat érkezési helyével és érkezési helye megegyezik a felhasználó érkezési helyével, illetve
                    // későbbi az indulási időpontja az első vonat érkezési időpontjától.
                    // A megtalált lehetséges első vonatokat beteszi a "potentialTrainsOne" tárolóba, 
                    // a lehetséges másodikakat pedig a "potentialTrainsTwo"-ba.
                        potentialTrainsOne.push_back(trains[i]);
                        potentialTrainsTwo.push_back(trains[j]);
                    }
                }
            } 
        }
    }
    if (potentialTrainsOne.size() > 0 && potentialTrainsTwo.size() == 0) {
        // Ha nincs átszállás.
        Train minimumOne = potentialTrainsOne[0];
        for (int i = 0; i < potentialTrainsOne.size(); ++i) {
            if (potentialTrainsOne[i].getDeparture() < minimumOne.getDeparture())
            // A lehetséges első vonatok halmazában meghatározza a minimumot, tehát a felhasználó indulásához legközelebbi időponttal rendelkező vonatot.
                minimumOne = potentialTrainsOne[i];
        }
        ticket.addTrain(minimumOne);
    }
    else if (potentialTrainsOne.size() > 0 && potentialTrainsTwo.size() > 0) {
        // Ha van átszállás.
        Train minimumOne = potentialTrainsOne[0];
        Train minimumTwo = potentialTrainsTwo[0];
        for (int i = 0; i < potentialTrainsOne.size(); ++i) {
            if (potentialTrainsOne[i].getDeparture() < minimumOne.getDeparture())
            // A lehetséges első vonatok halmazában meghatározza a minimumot, tehát a felhasználó indulásához legközelebbi időponttal rendelkező vonatot.
                minimumOne = potentialTrainsOne[i];
        }
        for (int i = 0; i < potentialTrainsTwo.size(); ++i) {
            if (potentialTrainsTwo[i].getDeparture() < minimumTwo.getDeparture())
            // A lehetséges második vonatok halmazában meghatározza a minimumot, tehát az első vonat érkezéséhez legközelebbi időponttal rendelkező vonatot.
                minimumTwo = potentialTrainsTwo[i];
        }
        ticket.addTrain(minimumOne);
        ticket.addTrain(minimumTwo);
    }
}

/// A rendelés véglegesítése előtt megjeleníti a jegyre kerülő adatokat.
void System::checkData() {
    std::cout << "************************* ADATOK ELLENORZESE *************************" << std::endl;
    ticket.printData();
    if (ticket.getTrainsOnTicketSize() > 0) {
        std::cout << std::endl << "(1): Vasarlas" << std::endl;
        std::cout << "(2): Megszakitas es uj jegy vasarlasa" << std::endl;
        std:: cout << "(3): START Menu" << std::endl;
        int choice = 0;
        std::cin >> choice;
        std::ofstream file;
        file.open("data.txt", std::ofstream::app);
        if (!file) {
            throw std::runtime_error("Hiba tortent a fajl megnyitasakor!");
        }
        ticket.genOrderID();
	    switch(choice) {
	    case 1:
            ticket.printDataToFile(file);
            ticket.printTicketToNewFile();
            file.close();
            orderSubMenu();
		    break;
	    case 2:
            deleteTrainsFromStore();
            ticket.deleteCustomerAndTrains();
            file.close();
	        askPassanger();
		    break;
        case 3:
            deleteTrainsFromStore();
            ticket.deleteCustomerAndTrains();
            file.close();
            menu();
            break;
	    default:
		    std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
            //checkData();
		    break;
        }
    }
    else if (ticket.getTrainsOnTicketSize() == 0) {
        std::cout << std::endl << "(1): Megszakitas es uj jegy vasarlasa" << std::endl;
        std:: cout << "(2): START Menu" << std::endl;
        int choice = 0;
        std::cin >> choice;
	    switch(choice) {
	    case 1:
            deleteTrainsFromStore();
            ticket.deleteCustomerAndTrains();
	        askPassanger();
		    break;
        case 2:
            deleteTrainsFromStore();
            ticket.deleteCustomerAndTrains();
            menu();
            break;
	    default:
		    std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
            //checkData();
		    break;
        }
    }

}

/// A rendelés véglegesítése után valosít meg egy menüt.
void System::orderSubMenu() {
    //std::system("clear");
    std::cout << "********** A VASARLAS SIKERESEN MEGTORTENT! **********" << std::endl;
    std::cout << "(1): Uj jegy vasarlasa" << std::endl;
    std::cout << "(2): START Menu" << std::endl;
    int choice = 0;
    std::cin >> choice;
    switch(choice) {
	case 1:
        deleteTrainsFromStore();
        ticket.deleteCustomerAndTrains();
		askPassanger();
		break;
	case 2:
        deleteTrainsFromStore();
        ticket.deleteCustomerAndTrains();
	    menu();
		break;
	default:
		std::cout << "A beutott karakter egyik lehetosegnek sem feleltetheto meg!" << std::endl;
		//orderSubMenu();
		break;
    }
}