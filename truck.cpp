// Necessary directives
#include <iostream>
#include <iomanip>
#include "truck.h"
using namespace std;

// Constructor definition (notice how we use the same "this" keyword to avoid naming conflicts like in vehicle.cpp)
Truck::Truck(string make, string model, string color, int mpg, double msrp, bool sidePanelStorage, bool autoReleaseTailgate) : Vehicle(make, model, color, mpg, msrp) {
    this->sidePanelStorage = sidePanelStorage;
    this->autoReleaseTailgate = autoReleaseTailgate;
}

// Truck's definition that overrides printDetails
void Truck::printDetails() {
    cout << fixed << setprecision(2); // Formatting so we get the full msrp
    cout << color << " " << make << " " << model << " (Truck) with " << mpg << " MPG and $" << msrp << " MSRP" << endl; // Gives the header information (first 4 attributes) for the truck in the inventory

    // Here, we use the ternary operator to determine if the specific truck in the inventory has the following two attributes (side panel storage and/or auto release tailgate) when printing the details
    cout << "-Has side panel storage: " << (sidePanelStorage ? "Yes" : "No") << endl;
    cout << "-Has auto-release tail gate: " << (autoReleaseTailgate ? "Yes" : "No") << endl << endl;
}