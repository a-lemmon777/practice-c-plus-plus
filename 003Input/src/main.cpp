// Program demonstrating user input.
#include <iostream>

int main()
{
    int years = 0;
    std::cout << "Please enter your age in years: ";
    std::cin >> years;
    const int months = years * 12;
    std::cout << "You are about " << months << " months old." << std::endl;
    return 0;
}
