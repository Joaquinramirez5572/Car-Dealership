// Necessary guards and directives
#ifndef TRUCK_H
#define TRUCK_H
#include "vehicle.h"
using namespace std;

// Our derived class "Car" definition
class Truck : public Vehicle {
private:
    // TRUCK-SPECIFIC attributes
    bool sidePanelStorage;
    bool autoReleaseTailgate;

public:
    Truck(string make, string model, string color, int mpg, double msrp, bool sidePanelStorage, bool autoReleaseTailgate); // Car constructor

    void printDetails(); // Truck's declaration for printDetails
};

#endif // End guard