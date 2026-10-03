// Necessary guards and directives
#ifndef VEHICLE_H
#define VEHICLE_H
#include <string>
using namespace std;

class Vehicle {
protected: // We make these protected so that only the derived classes have access and can manipulate the attributes
    // Necessary attributes
    string make;
    string model;
    string color;
    int mpg;
    double msrp;

public:
    Vehicle(string make, string model, string color, int mpg, double msrp); // Constructor

    // Method declarations that we may use when searching the inventory
    string getMake();
    string getModel();
    string getColor();
    int getMPG();
    double getMSRP();

    virtual void printDetails() = 0; // Our virtual function definition that has a default value because it will be overriden in the derived classes with specific formats to enable runtime polymorphism

    virtual ~Vehicle() {} // Class destructor to avoid memory leaks (see the main.cpp for the loop that deletes them)
};

#endif // End guard