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

    /*
    * Negative
    *   Submarine: Enjoy the depths of the deep blue sea!
    *   Not in vehicle: Don't gawk at the eels, they're shy.
    *   Other: You've sunk your ride.
    * 
    * 0
    *   Submarine: Feels good to surface for some fresh air.
    *   Yacht: Cruising through the waves.
    *   Not in vehicle: It's a perfect day for a swim!
    *   Other: Oops, an unexpected detour into the sea!
    * 
    * 1 - 5,000 ft
    *   Submarine and Yacht: You've run aground!
    *   Car: Time to blast the road trip playlist!
    *   Airplane: Please prepare for takeoff.
    *   Not in vehicle: Just loitering around on solid ground I guess.
    * 
    * 5,000 - 30,000 ft
    *   Submarine and Yacht: You must have hitched a ride on a big tsunami to get on this mountain.
    *   Car: It's all downhill from here!
    *   Not in vehicle: You're an impressive mountaineer!
    *   Airplane: Watch out for mountains! Swerve around them if you have to.
    * 
    * > 30,000 ft
    *   Not in a vehicle: I hope you have a parachute!
    *   Airplane: Nice, cruising altitude. Bust out the snacks.
    *   Other: I'm pretty impressed you managed to get your vehicle up this high.
    */

    std::cout << "Altitude: " << altitude << std::endl;
    std::cout << "Vehicle choice: " << vehicle_choice << std::endl;
    return 0;
}