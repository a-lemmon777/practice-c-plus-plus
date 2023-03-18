// A
#include <iostream>
#include <vector>

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

    return 0;
}