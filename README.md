# Car Dealership Inventory Management System

A C++ console application for managing a car dealership's vehicle inventory. The system allows dealerships to add vehicles, search by attributes, and track both cars and trucks with vehicle-specific features using runtime polymorphism and object-oriented design patterns.

## Overview

Car Dealership Inventory Management System is a desktop application built in C++ that allows dealership staff to:

- add new cars and trucks to the inventory
- view the complete current inventory with detailed specifications
- search for vehicles by make, model, or color
- access detailed information for specific vehicles
- manage vehicle-specific attributes (spare tire, windshield wipers for cars; side storage, tailgate for trucks)
- maintain organized inventory with type-safe vehicle management

This project demonstrates advanced object-oriented programming through inheritance, polymorphism, and dynamic memory management for a real-world business application.

## Why This Project Matters

Car dealerships manage dozens or hundreds of vehicles with varying specifications and features. Without a structured inventory system, tracking vehicles, searching for specific models, and managing vehicle-specific attributes becomes error-prone and time-consuming. This application provides dealership staff with an efficient way to organize, search, and display vehicle information through a clean console interface.

## Features

- Add cars and trucks with make, model, color, MPG, and MSRP
- Store vehicle-specific attributes (cars: spare tire, rear windshield wiper; trucks: side panel storage, auto-release tailgate)
- View complete current inventory with formatted output
- Search inventory by make, model, or color
- Retrieve detailed information for specific vehicles
- Input validation for safe data entry
- Runtime polymorphism for flexible vehicle type handling
- Proper memory management to prevent memory leaks
- Pre-loaded sample inventory for demonstration

## Technical Stack

- Language: C++
- Programming Paradigm: Object-oriented programming with inheritance and polymorphism
- Core Concepts: virtual functions, derived classes, dynamic memory allocation, std::vector, pointers, encapsulation
- Design Patterns: Template Method Pattern (base class with overridden methods)

## Application Design

The application uses a three-tier class hierarchy with polymorphic behavior:

- Vehicle (Base Class): Abstract base class defining the interface for all vehicles. Contains common attributes (make, model, color, MPG, MSRP) and defines a pure virtual printDetails() method.
- Car (Derived Class): Extends Vehicle to represent automobiles. Adds car-specific attributes: spare tire in trunk and rear windshield wiper support. Overrides printDetails() to display car-specific information.
- Truck (Derived Class): Extends Vehicle to represent trucks. Adds truck-specific attributes: side panel storage and auto-release tailgate. Overrides printDetails() to display truck-specific information.
- Inventory Management: Uses a vector of Vehicle pointers to store heterogeneous vehicle objects, enabling runtime polymorphism through dynamic dispatch.
- Menu System: Four main operations—add vehicle, display inventory, search, and view details—implemented with pass-by-reference parameter passing for efficiency.

This structure demonstrates proper separation of concerns, code reusability through inheritance, and extensibility for future vehicle types.

## Project Structure

```text
Car-Dealership/
├── main.cpp                                                          # Menu system and inventory operations
├── vehicle.h / vehicle.cpp                                           # Base Vehicle class definition
├── car.h / car.cpp                                                   # Car class (derived from Vehicle)
├── truck.h / truck.cpp                                               # Truck class (derived from Vehicle)
├── The Car Dealership Inventory.sln                                  # Visual Studio solution file
├── README.md
└── Ramirez Joaquin - Software Design Document Car Dealership Inventory.pdf
```

## How to Run

1. Clone the repository.
2. Open "The Car Dealership Inventory.sln" in Visual Studio.
3. Build the solution.
4. Run the application.
5. Use the menu to add vehicles, search, and view inventory details.

## Example Workflow

1. The application loads a pre-populated inventory of 6 sample vehicles (3 cars and 3 trucks).
2. Select "Output Current Inventory" to view all vehicles in a formatted table.
3. Select "Search" and filter by color, make, or model to find specific vehicles.
4. Select "Add a Vehicle" to input a new car or truck with its specifications.
5. Select "Output a Specific Vehicle" to retrieve detailed info by make, model, and color.
6. Exit the menu to gracefully terminate the program and clean up memory.

## Key Design Decisions

- Polymorphism: Virtual functions allow each vehicle type to display its details in a format specific to its characteristics without casting or type-checking in the main loop.
- Dynamic Memory: Vehicle pointers enable storing derived class instances in a single container, essential for handling multiple vehicle types uniformly.
- Encapsulation: The Vehicle class marks data members as protected so only derived classes can access them, preventing unauthorized modification.
- Pass-by-Reference: Menu functions use reference parameters to avoid copying large vector objects and enable in-place modifications to inventory.
- Memory Management: Explicit deletion loop in main() ensures all dynamically allocated vehicle objects are freed, preventing memory leaks.

## Software Design Document

The full design document for this project is available in the repository:

[Ramirez, Joaquin - Software Design Document Car Dealership Inventory](./Ramirez%20Joaquin%20-%20Software%20Design%20Document%20Car%20Dealership%20Inventory.pdf)

## Final Notes

Car Dealership Inventory Management System demonstrates solid software engineering practices including inheritance hierarchies, runtime polymorphism, dynamic memory management, and clean menu-driven architecture. It is a practical portfolio project showcasing experience with object-oriented design patterns and business logic implementation in C++.
