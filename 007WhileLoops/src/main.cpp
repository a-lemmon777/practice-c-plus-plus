// Uses a while loop to list the Fibonacci sequence up to the first item that exceeds 1 million.
#include <iostream>

int main()
{
    std::cout << "Listing the Fibonacci sequence up to the first item that exceeds 1 million:" << std::endl;
    int previousItem = 0;
    int currentItem = 1;
    int nextItem;
    std::cout << previousItem;
    std::cout << ", " << currentItem;
    while (currentItem <= 1000000) {
        nextItem = previousItem + currentItem;
        previousItem = currentItem;
        currentItem = nextItem;
        std::cout << ", " << currentItem;
    }
    return 0;
}