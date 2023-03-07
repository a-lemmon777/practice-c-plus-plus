// This program imports the CMath library and uses some of its functions.
#include <cmath>
#include <iostream>

int main()
{
    std::cout << "3 squared is " << std::pow(3, 2) << "." << std::endl;
    std::cout << "The floor of 4.5 is " << std::floor(4.5) << "." << std::endl;
    std::cout << "The max of 2.2 and 3.3 is " << std::fmax(2.2, 3.3) << "." << std::endl;
    return 0;
}