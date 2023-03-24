// Program demonstrating conditional statements.
#include <iostream>

int main()
{
    std::cout << "Please enter your current altitude in feet: ";
    int altitude = 0;
    std::cin >> altitude;

    std::cout << "Are you in a vehicle? Please enter the number of the choice that matches your situation."
        << std::endl;
    std::cout << "1: You're in a car." << std::endl;
    std::cout << "2: You're in a submarine." << std::endl;
    std::cout << "3: You're in an airplane." << std::endl;
    std::cout << "4: You're not in a vehicle." << std::endl;
    std::cout << "Enter the number of your choice: ";

    int vehicle_choice = 0;
    std::cin >> vehicle_choice;

    if (vehicle_choice < 1 || vehicle_choice > 4)
    {
        std::cout << "Way to be a rebel and enter a non-standard choice. You're in a new shiny yacht now!" << std::endl;
        vehicle_choice = 5; // You're in a yacht.
    }

    std::cout << "Altitude: " << altitude << std::endl;
    std::cout << "Vehicle choice: ";
    if (vehicle_choice == 1)
        std::cout << "car";
    else if (vehicle_choice == 2)
        std::cout << "submarine";
    else if (vehicle_choice == 3)
        std::cout << "airplane";
    else if (vehicle_choice == 4)
        std::cout << "no vehicle";
    else
        std::cout << "yacht";
    std::cout << std::endl;

    if (altitude < 0)
    {
        if (vehicle_choice == 2) // submarine
            std::cout << "Enjoy the depths of the deep blue sea!" << std::endl;
        else if (vehicle_choice == 4) // no vehicle
            std::cout << "Don't gawk at the eels, they're shy." << std::endl;
        else
            std::cout << "You've sunk your ride." << std::endl;
    }
    else if (altitude == 0)
    {
        if (vehicle_choice == 2) // submarine
            std::cout << "Feels good to surface for some fresh air." << std::endl;
        else if (vehicle_choice == 4) // no vehicle
            std::cout << "It's a perfect day for a swim!" << std::endl;
        else if (vehicle_choice == 5) // yacht
            std::cout << "Cruising through the waves." << std::endl;
        else
            std::cout << "Oops, an unexpected detour into the sea!" << std::endl;
    }
    else if (altitude <= 5000)
    {
        if (vehicle_choice == 1) // car
            std::cout << "Time to blast the road trip playlist!" << std::endl;
        else if (vehicle_choice == 2 || vehicle_choice == 5) // submarine or yacht
            std::cout << "You've run aground!" << std::endl;
        else if (vehicle_choice == 3) // airplane
            std::cout << "Please prepare for takeoff." << std::endl;
        else // no vehicle is the only possibility left
            std::cout << "Just loitering around on solid ground I guess." << std::endl;
    }
    else if (altitude <= 30000)
    {
        if (vehicle_choice == 1) // car
            std::cout << "It's all downhill from here!" << std::endl;
        else if (vehicle_choice == 2 || vehicle_choice == 5) // submarine or yacht
            std::cout << "You must have hitched a ride on a big tsunami to get on this mountain." << std::endl;
        else if (vehicle_choice == 3) // airplane
            std::cout << "Watch out for mountains! Swerve around them if you have to." << std::endl;
        else // no vehicle is the only possibility left
            std::cout << "You're an impressive mountaineer!" << std::endl;
    }
    else
    {
        if (vehicle_choice == 3) // airplane
            std::cout << "Nice, cruising altitude. Bust out the snacks." << std::endl;
        else if (vehicle_choice == 4) // no vehicle
            std::cout << "I hope you have a parachute!" << std::endl;
        else
            std::cout << "I'm pretty impressed you managed to get your vehicle up this high." << std::endl;
    }

    return 0;
}