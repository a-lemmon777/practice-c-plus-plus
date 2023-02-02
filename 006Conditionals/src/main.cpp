// Program demonstrating conditional statements.
#include <iostream>

int main()
{
    std::cout << "Please enter your current altitude in feet: ";
    int altitude;
    std::cin >> altitude;

    std::cout << "Are you in a vehicle? Please enter the number of the choice that matches your situation."
        << std::endl;
    std::cout << "1: You're in a car." << std::endl;
    std::cout << "2: You're in a submarine." << std::endl;
    std::cout << "3: You're in an airplane." << std::endl;
    std::cout << "4: You're not in a vehicle." << std::endl;
    std::cout << "Enter the number of your choice: ";

    int vehicle_choice;
    std::cin >> vehicle_choice;

    if (vehicle_choice < 1 || vehicle_choice > 4) {
        std::cout << "Way to be a rebel and enter a non-standard choice. You're in a new shiny yacht now!" << std::endl;
        vehicle_choice = 5; // You're in a yacht.
    }

    std::cout << "Altitude: " << altitude << std::endl;
    std::cout << "Vehicle choice: " << vehicle_choice << std::endl;
    return 0;
}