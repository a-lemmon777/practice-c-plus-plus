// Explores the details of using vectors.
#include <iostream>
#include <vector>

int GetFive()
{
    return 5;
}

void PrintVectorInfo(const std::vector<int>& vectorToPrint)
{
    std::cout << "Contents of vector: ";
    for (unsigned int i = 0; i < vectorToPrint.size(); i++)
        std::cout << vectorToPrint[i] << ' ';
    std::cout << std::endl;
    std::cout << "Size of vector: " << vectorToPrint.size() << std::endl;
    std::cout << "Capacity of vector: " << vectorToPrint.capacity() << std::endl;
    std::cout << "_________________________" << std::endl;
}

int main()
{
    // Using pushback
    std::vector<int> myVector;
    myVector.push_back(5);
    myVector.push_back(6);
    myVector.push_back(7);

    std::cout << "Added 3 items to myVector." << std::endl;
    PrintVectorInfo(myVector);

    // Resizing smaller
    myVector.resize(2);
    std::cout << "Resized myVector to size 2." << std::endl;
    PrintVectorInfo(myVector);
    
    // resizing larger
    // resizing larger with a specified value for the new elements.
    // resizing smaller

    // making a vector with an initial size
    // maybe initializing vectors inside functions vs outside functions.
    // Initializing a vector with brace notation.
    // Initializing a vector with brace notation and a matching size.
    // Initializing a vector with brace notation and smaller size.
    // Initializing a vector with brace notation and a bigger size.
    // Initializing a vector with all the same value.
    // Initializing with a size that's determined at runtime.

    // Assigning one vector to another
    // "Overwriting" a vector with another one
    // Assigning a vector to another, then modifying to see if it changes both.
    // Experimenting with const on a vector
    // accessing out of bounds with both square brackets and at()



    std::vector<int> otherVector = myVector;

    std::cout << myVector[0] << std::endl;
    std::cout << otherVector[0] << std::endl;
    
    myVector[0] = 8;

    std::cout << myVector[0] << std::endl;
    std::cout << otherVector[0] << std::endl;

    std::vector<float> floatVector(3);
    for (int i = 0; i < floatVector.size(); i++)
    {
        std::cout << floatVector[i] << std::endl;
    }

    std::vector<int> intVector = { 1, 2, 3, GetFive() };
    for (int i = 0; i < intVector.size(); i++)
    {
        std::cout << intVector[i] << std::endl;
    }

    int intArray[] = { 1, 2, 3, GetFive() };
    for (int i = 0; i < 4; i++)
    {
        std::cout << intArray[i] << std::endl;
    }

    //int badArray[getFive()];

    std::vector<int> initializedVector(3, 10);
    for (int i = 0; i < initializedVector.size(); i++)
    {
        std::cout << initializedVector[i] << std::endl;
    }

    std::vector<float> accounts(4, 100.00);

    accounts.resize(8, 200.00);

    for (int i = 0; i < accounts.size(); i++)
    {
        std::cout << accounts[i] << std::endl;
    }

    // Both of these lines throw an exception.
    //std::cout << accounts.at(10) << std::endl;
    //std::cout << accounts[10] << std::endl;

    return 0;
}