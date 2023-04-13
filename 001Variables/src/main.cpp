// Program with variables
#include <iostream>

int main()
{
    // Calorie calculator
    const int carbGrams = 10;
    const int fatGrams = 20;
    const int proteinGrams = 15;

    const int total_calories = carbGrams * 4 + fatGrams * 9 + proteinGrams * 4;
    std::cout << "There are " << total_calories << " total calories." << std::endl;

    // Weeks to days calculation
    const int weeks = 20;
    const int days = weeks * 7;
    std::cout << "There are " << days << " days in " << weeks << " week(s)." << std::endl;
    return 0;
}
