// Necessary directives and libraries
#include <iostream>
#include <vector>
#include "car.h"
#include "truck.h"
using namespace std;

// Our menu function declarations that will be defined at the end of the file that each take in the inventory as a parameter through pass-by-reference
void addVehicle(vector<Vehicle*>& inventory);
void printList(vector<Vehicle*>& inventory);
void searchPrintInventory(vector<Vehicle*>& inventory);
void printVehicle(vector<Vehicle*>& inventory);

int main() {

    vector<Vehicle*> inventory; // Our working inventory system that is composed of vehicle pointers that each point to a derived vehicle object to enable runtime polymorphism

    // Here is our hard-coded preloaded data of six vehicles created with their respective constructors that are then pushed back onto the inventory. See the SDD attached for a better overview
    inventory.push_back(new Car("Toyota", "Camry", "Silver", 32,27495.50, true, false));
    inventory.push_back(new Truck("Ford", "F-150" ,"Black", 20,41560.75, true, false));
    inventory.push_back(new Car("Honda", "Accord", "Blue",30,28940.60, true, false));
    inventory.push_back(new Truck("Chevrolet", "Silverado 1500", "Red", 19,43620.85, false, true));
    inventory.push_back(new Car("Hyundai", "Elantra", "White", 36,22325.40,false, true));
    inventory.push_back(new Truck("Toyota", "Tacoma" ,"Gray", 21,34980.95, true, true));

    int option = -1; // Menu option (MO) declaration set to -1 so the while loop that comes next can execute

    cout << "Welcome to our car dealership's inventory management system! ";

    // This is our working menu that iterates until the menu option received is 5
    while (option != 5) {
        cout << "Please select one of the following menu options below!" << endl;
        cout << "1. Add a Vehicle" << endl << "2. Output the Current Inventory" << endl << "3. Search the Current Inventory by Make, Model, or Color" << endl << "4. Output a Specific Vehicle's Information" << endl <<  "5. Exit" << endl << endl;
        cin >> option; // Asks the user for their menu option
        cout << endl;

        // Menu option 1 (add a vehicle)
        if (option == 1) {
            addVehicle(inventory);
        }

        // Menu option 2 (output current inventory)
        else if (option == 2) {
            printList(inventory);
        }

        // Menu option 3 (search by a specific attribute and output a list)
        else if (option == 3) {
            searchPrintInventory(inventory);
        }

        // Menu option 4 (output a specific vehicle's information)
        else if (option == 4) {
            printVehicle(inventory);
        }

        // Menu option 5 (exits the loop and outputs the thank you message)
        else if (option == 5) {
            break; // Exits the loop
        }

        else {
           cout << "Sorry! Invalid menu option." << endl << endl; // If the number is not a valid menu option, this executes
        }
    }

    cout << "Thank you for using our car inventory system! Have an amazing day!" << endl; // Thank you messag

    // Deletes every object (or vehicle) that the pointer references to in our inventory to avoid a memory leak
    for (int i = 0; i < inventory.size(); i++) {
        Vehicle* v = inventory[i];
        delete v;
    }

    return 0;
}

// Add a vehicle's definition (MO 1)
void addVehicle(vector<Vehicle*>& inventory){
    // The following attributes are declared and given values to be used as parameters for the constructor to make a car or truck object to be added to the inventory
    string type, make, model, color;
    int mpg;
    double msrp;
    string a,b;

    cout << "Enter vehicle type (Car/Truck): ";
    cin >> type;

    cout << "Make: ";
    cin >> make;

    cout << "Model: ";
    cin >> model;

    cout << "Color: ";
    cin >> color;

    cout << "MPG: ";
    cin >>mpg;

    cout << "MSRP: ";
    cin >> msrp;

    // If the type is a car (as specified by the user), we ask the user if the car has the following two attributes, and using that, we make a car object that is added to the inventory
    if (type == "Car") {
        cout << "Spare in trunk (Yes/No): ";
        cin >> a;

        cout<<"Rear windshield wiper (Yes/No): ";
        cin >> b;

        cout << endl;

        inventory.push_back(new Car(make, model, color, mpg, msrp, (a == "Yes"), (b == "Yes"))); // The boolean parameters are evaluated based on the user input
    }

    // If the type is a truck (as specified by the user), we ask the user if the truck has the following two attributes, and using that, we make a truck object that is added to the inventory
    else {
        cout << "Side panel storage (Yes/No): ";
        cin >> a;

        cout << "Auto-release tail gate (Yes/No): ";
        cin >> b;

        cout << endl;

        inventory.push_back(new Truck(make, model, color, mpg, msrp, (a=="Yes"), (b=="Yes"))); // The boolean parameters are evaluated based on the user input
    }

    cout<< "Done. The vehicle has been added!" << endl << endl; // Tells the user that the vehicle is added
}

// Print the list's definition (M0 2)
void printList(vector<Vehicle*>& inventory) {
    cout << endl << "Current Inventory" << endl << "----------------------" << endl; // Header formatting

    // We are essentially iterating through the inventory and for each "v" (of type "Vehicle*" which is a pointer), we print the details using the printDetail method determined at runtime
    for (int i = 0; i < inventory.size(); i++) {
        Vehicle* v = inventory[i]; // Each vehicle in the inventory is at a specific index
        v->printDetails(); // Prints the details
        cout << endl; // Formatting
    }

}

// Search and print inventory's definition (MO 3)
void searchPrintInventory(vector<Vehicle*>& inventory) {
    // Function members declarations
    int choice;
    string value; // The value the user will enter based off if they are searching by make, model, or color. For example, if by color, the value they enter can be "Green"
    bool found = false; // Tracks whether at least one matching vehicle has been found during the search 

    // Asks the user if they want to search by make, model, or color
    cout << "Search by Make (1), Model (2), or Color (3): ";
    cin >> choice;
    cout << endl;

    // Prompts the user to enter the specified attribute they wish to search by, like "Toyota" if by make, "Corolla" if by model, or "White" if by color
    cout << "Enter the make, model, or color depending on what you just chose: ";
    cin >> value;
    cout << endl;

    for (int i = 0; i < inventory.size(); i++) {
        Vehicle* v = inventory[i]; // Tells the for loop that each element at the given index is a pointer object

        // If the user's value matches the make, model, or color, then output the make, model, and color
        if((choice == 1 && v->getMake() == value) || (choice == 2 && v->getModel() == value) || (choice == 3 && v->getColor() == value)) {
            // Since found is false, this will execute automatically BUT ONLY ONCE because we do not want to print out the header multiple times
            if (!found) {
                // Our header for all of the vehicles with the make, model, or color
                cout << "The vehicles in the inventory with the ";

                if (choice == 1) {
                    cout << "make ";
                }
                if (choice == 2) {
                    cout << "model ";
                }
                if (choice == 3) {
                    cout << "color ";
                }

                cout << "\"" << value << "\" are:" << endl;
            }
            cout << "-" << v->getColor() << " "<< v->getMake() << " " << v->getModel() << endl; // Output's the make, model, and color
            found = true; // Sets found to true so that we do not print the header again and so that we do not print that no match was found
        }
    }

    cout << endl;

    // Executes when no match is found in the previous loop
    if (!found) {
        cout << "Sorry! No such vehicle was found with your specified attribute." << endl << endl;
    }
}

// Print a specific vehicle's information definition (MO 4)
void printVehicle(vector<Vehicle*>& inventory) {
    // Necessary attribute declarations
    string make, model, color;
    bool found = false; // Our tracker, like in the previous function, keeps track of if a vehicle is found or not first

    // Asks the user for the make, model, and color
    cout << "Make: ";
    cin >> make;

    cout << "Model: ";
    cin >> model;

    cout << "Color: ";
    cin >> color;
    cout << endl;

    // We iterate through the inventory to check if the user's parameters match an item (or vehicle) in our inventory, and if it does, print its details and flip "found" to true so the other message does not display
    for (int i = 0; i < inventory.size(); i++) {
        Vehicle* v = inventory[i]; // Tells the for loop that each element at the given index is a pointer object
        if(v->getMake() == make && v->getModel() == model && v->getColor() == color) {
            cout << "VEHICLE INFORMATION:" << endl; // Header info
            v->printDetails(); // Display the vehicle's information!

            found = true; // Flip found to true so the other message won't display
        }
    }

    // Displays if the vehicle is not found in the inventory
    if (!found) {
        cout << "Sorry! Unfortunately, no such vehicle exists in our inventory." << endl << endl;
    }
}