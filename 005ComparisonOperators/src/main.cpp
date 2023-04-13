// Program demonstrating comparison operators.
#include <iostream>

int main()
{
    std::cout << "Please enter your age: ";
    int age = 0;
    std::cin >> age;

    std::cout << "Some facts about you (0 means false, 1 means true):" << std::endl;
    std::cout << "You are a prankster and entered a negative age: " << (age < 0) << std::endl;
    std::cout << "You are the same age or younger than Grace Hopper when she invented the first compiler (46): "
        << (age <= 46) << std::endl;
    std::cout << "You survived longer than Julius Caesar (greater than 55): " << (age > 55) << std::endl;
    std::cout << "You are \"Over the Hill\" (40 or higher): " << (age >= 40) << std::endl;
    std::cout << "You are a newborn baby with amazing typing abilities (age 0): " << (age == 0) << std::endl;
    std::cout << "You are more or less than 100 years old, but not exactly a new centennial: " << (age != 100)
        << std::endl;
}
