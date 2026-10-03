// Necessary guards and directives
#ifndef CAR_H
#define CAR_H
#include "vehicle.h"
using namespace std;

// Our derived class "Car" definition
class Car : public Vehicle {
private:
    // CAR-SPECIFIC attributes
    bool spareInTrunk;
    bool rearWindshieldWiper;

public:
    Car(string make, string model, string color, int mpg, double msrp, bool spareInTrunk, bool rearWindshieldWiper); // Car constructor

    void printDetails(); // Car's declaration for printDetails
};

#endif // End guard