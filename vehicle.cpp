#include "vehicle.h" // Let's us access the header file

// Constructor definition
Vehicle::Vehicle(string make, string model, string color, int mpg, double msrp) {
    // "This" is a shorthand for us to differentiate the class members and parameters
    this->make = make;
    this->model = model;
    this->color = color;
    this->mpg = mpg;
    this->msrp = msrp;
}

// The following are the getter/accessor definitions for vehicle
string Vehicle::getMake() {
    return make;
}

string Vehicle::getModel() {
    return model;
}

string Vehicle::getColor() {
    return color;
}

int Vehicle::getMPG() {
    return mpg;
}

double Vehicle::getMSRP() {
    return msrp;
}