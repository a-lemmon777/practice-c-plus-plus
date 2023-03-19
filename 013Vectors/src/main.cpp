// A
#include <iostream>
#include <vector>

int getFive()
{
    return 5;
}

int* getArray()
{
    int smallArray[] = { 8, 9, 10 };
    return smallArray;
}

int main()
{
    std::vector<int> myVector;
    myVector.push_back(5);

    std::cout << myVector[0] << std::endl;

    std::vector<int> otherVector = myVector;

    std::cout << myVector[0] << std::endl;
    std::cout << otherVector[0] << std::endl;
    
    myVector[0] = 8;

    std::cout << myVector[0] << std::endl;
    std::cout << otherVector[0] << std::endl;

    std::vector<float> floatVector(3);
    for (int i = 0; i < floatVector.size(); i++) {
        std::cout << floatVector[i] << std::endl;
    }

    std::vector<int> intVector = { 1, 2, 3, getFive() };
    for (int i = 0; i < intVector.size(); i++) {
        std::cout << intVector[i] << std::endl;
    }

    int intArray[] = { 1, 2, 3, getFive() };
    for (int i = 0; i < 4; i++) {
        std::cout << intArray[i] << std::endl;
    }

    //int badArray[getFive()];

    std::vector<int> initializedVector(3, 10);
    for (int i = 0; i < initializedVector.size(); i++) {
        std::cout << initializedVector[i] << std::endl;
    }

    std::vector<float> accounts(4, 100.00);

    accounts.resize(8, 200.00);

    for (int i = 0; i < accounts.size(); i++) {
        std::cout << accounts[i] << std::endl;
    }

    //std::cout << accounts.at(10) << std::endl;
    //std::cout << accounts[10] << std::endl;

    return 0;
}