// Demonstrates defining, throwing, catching, and handling exceptions.
#include <cmath>
#include <exception>
#include <iostream>
#include <stdexcept>
#include <vector>

// Throwing a programmer-defined exception.
double carefulSqrt(double input)
{
    if (input < 0)
    {
        std::exception invalidArgumentException;
        throw invalidArgumentException;
    }
    return std::sqrt(input);
}

// Constructing and throwing an exception in one line.
void throwOneLinerException()
{
    throw std::exception();
}

// Throwing different exception types.
void updateHamsterWeight(std::vector<double> hamsterWeights, int indexToUpdate, double newWeight)
{
    if (indexToUpdate < 0)
        throw std::out_of_range("Hamster index can't be negative.");
    if (indexToUpdate >= hamsterWeights.size())
        throw std::out_of_range("Hamster index is too high.");
    if (newWeight < 0)
        throw std::invalid_argument("Hamster weight can't be negative.");
    hamsterWeights[indexToUpdate] = newWeight;
}

int main()
{
    // Catching a built-in exception.
    try
    {
        std::vector<double> emptyVector;
        double doesntExist = emptyVector.at(0);
    }
    catch (const std::exception& e)
    {
        std::cout << "You caught an exception!" << std::endl;
    }

    // Catching a programmer-defined exception.
    try
    {
        carefulSqrt(-4);
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught a programmer-defined exception!" << std::endl;
    }

    try
    {
        throwOneLinerException();
    }
    catch (const std::exception& e)
    {
        std::cout << "Caught another one!" << std::endl;
    }

    // Uses multiple catch blocks to handle different exception types.
    // If the type of exception doesn't match the first catch block, the next catch block will try to match it.
    // The what() function will return the exception's message.
    try
    {
        std::vector<double> hamsterWeights = { 2.5 };
        updateHamsterWeight(hamsterWeights, 10, 3.5);
    }
    catch (const std::invalid_argument& e)
    {
        std::cout << e.what() << std::endl;
    }
    catch (const std::out_of_range& e)
    {
        std::cout << e.what() << std::endl;
    }

    return 0;
}