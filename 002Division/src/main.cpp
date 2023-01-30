// Program demonstrating integer division and the modulus operator.
#include <iostream>

int main()
{
    std::cout << "10 / 3 == " << 10 / 3 << std::endl; // Should truncate to 3.
    std::cout << "-10 / 3 == " << -10 / 3 << std::endl; // Should truncate to -3.
    std::cout << "10 / -3 == " << 10 / -3 << std::endl; // Should truncate to -3.
    std::cout << "-10 / -3 == " << -10 / -3 << std::endl; // Should truncate to 3.

    /*
    * The modulo operater has different behavior in various programming languages when used with negative operands.
    * In C/C++, it is defined such that (a % b) == a - ((a / b) * b). Since integer division always truncates (rounds
    * toward 0), the magnitude of ((a / b) * b) is lesser than or equal to the magnitude of 'a'. Because of this, the
    * sign of the modulo result must match the sign of the first operand (unless the result is 0 of course).
    * 
    * Another way to think of this is to determine the largest multiple of the denominator (with the same sign as the
    * numerator) whose magnitude is smaller or equal to the magnitude of the numerator. Subtract this number from the
    * numerator to obtain the modulo result.
    */

    // Should be 1.
    std::cout << "10 % 3 == " << 10 % 3 << std::endl;

    // Should be -1.
    std::cout << "-10 % 3 == " << -10 % 3 << std::endl;

    // Should be 1.
    std::cout << "10 % -3 == " << 10 % -3 << std::endl;

    // Should be -1.
    std::cout << "-10 % -3 == " << -10 % -3 << std::endl;

    return 0;
}