// Program using booleans and boolean operators.
#include <iostream>

int main()
{
    std::cout << "For this program, false will print as 0 and true will print as 1." << std::endl;
    const bool isMoonCheese = false;
    const bool isPigFlying = false;
    const bool isGiraffeTall = true;
    const bool isWaterWet = true;
    
    std::cout << "isMoonCheese: " << isMoonCheese << std::endl;
    std::cout << "isPigFlying: " << isPigFlying << std::endl;
    std::cout << "isGiraffeTall: " << isGiraffeTall << std::endl;
    std::cout << "isWaterWet: " << isWaterWet << std::endl;
    
    // Not operator
    std::cout << "!isMoonCheese: " << !isMoonCheese << std::endl;
    std::cout << "!isWaterWet: " << !isWaterWet << std::endl;

    // And operator
    std::cout << "isMoonCheese && isPigFlying: " << (isMoonCheese && isPigFlying) << std::endl;
    std::cout << "isMoonCheese && isWaterWet: " << (isMoonCheese && isWaterWet) << std::endl;
    std::cout << "isGiraffeTall && isWaterWet: " << (isGiraffeTall && isWaterWet) << std::endl;

    // Or operator
    std::cout << "isMoonCheese || isPigFlying: " << (isMoonCheese || isPigFlying) << std::endl;
    std::cout << "isMoonCheese || isWaterWet: " << (isMoonCheese || isWaterWet) << std::endl;
    std::cout << "isGiraffeTall || isWaterWet: " << (isGiraffeTall || isWaterWet) << std::endl;

    return 0;
}
