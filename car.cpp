// Necessary directives
#include <iostream>
#include <iomanip>
#include "car.h"
using namespace std;

// Constructor definition (notice how we use the same "this" keyword to avoid naming conflicts like in vehicle.cpp)
Car::Car(string make, string model, string color, int mpg, double msrp, bool spareInTrunk, bool rearWindshieldWiper) : Vehicle(make, model, color, mpg, msrp) {
    this->spareInTrunk = spareInTrunk;
    this->rearWindshieldWiper = rearWindshieldWiper;
}

// Car's definition that overrides printDetails
void Car::printDetails() {
    cout << fixed << setprecision(2); // Formatting so we get the full msrp
    cout << color << " " << make << " " << model << " (Car) with " << mpg << " MPG and $" << msrp << " MSRP" << endl; // Gives the header information (first 4 attributes) for the car in the inventory

    // Here, we use the ternary operator to determine if the specific car in the inventory has the following two attributes (spare in trunk and/or rear windshield wiper) when printing the details
    cout << "-Spare in the trunk: " << (spareInTrunk ? "Yes" : "No") << endl;
    cout << "-Has rear windshield wiper: " << (rearWindshieldWiper ? "Yes" : "No") << endl << endl;
}