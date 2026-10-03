# Car Dealership Inventory Management System

A C++ console application for managing a car dealership inventory. The system allows staff to add vehicles, search by key details, and track cars and trucks with different features using inheritance and polymorphism.

## Overview

- Add new cars and trucks to the inventory
- View the full inventory with vehicle details
- Search by make, model, or color
- Manage vehicle-specific attributes for each class

This project demonstrates object-oriented programming through inheritance, polymorphism, and dynamic memory management.

## Why This Project Matters

Car dealerships manage many vehicles with different specifications. Without a structured system, tracking inventory and finding specific cars becomes difficult and time-consuming. This application simulates a way for staff to manage and review vehicle information efficiently.

## Features

- Inventory tracking for cars and trucks
- Search by make, model, or color
- Vehicle-specific attributes for each class
- Polymorphic storage using vector<Vehicle*> and raw pointer memory management

## Technical Stack

- Language: C++
- Programming Paradigm: Object-oriented programming
- Core Concepts: inheritance, polymorphism, vectors, raw pointers
- Design Approach: modular class hierarchy and dynamic dispatch

## Application Design

- Vehicle: shared base class for common attributes
- Car: subclass with car-specific data and methods
- Truck: subclass with truck-specific data and methods
- Inventory Manager: stores derived objects in vector<Vehicle*> for runtime polymorphic behavior

This structure keeps the code reusable and makes it easier to add new vehicle types later.

## Project Structure

```text
Car-Dealership/
├── main.cpp
├── vehicle.h
├── vehicle.cpp
├── car.h
├── car.cpp
├── truck.h
├── truck.cpp
├── README.md
└── Ramirez Joaquin - Software Design Document Car Dealership Inventory.pdf
```

## How to Run

1. Clone the repository.
2. Open the project in Visual Studio.
3. Build the solution.
4. Run the application.
5. Use the menu to add, search, and view vehicles.

## Example Workflow

- Add a new car or truck to the inventory
- Search for a vehicle by make or color
- View detailed information for a selected vehicle
- Continue managing inventory as new stock arrives

## Testing and Validation

The program includes validation for user input and checks key menu functions to ensure inventory operations work correctly. It also confirms that vehicle-specific information is displayed accurately for each class.

## Software Design Document

The full design document for this project is available in the repository:

[Ramirez, Joaquin - Software Design Document Car Dealership Inventory](./Ramirez%20Joaquin%20-%20Software%20Design%20Document%20Car%20Dealership%20Inventory.pdf)
