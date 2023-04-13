// Demonstrates using stacks.
#include <iostream>
#include <stack>
#include <string>

int main()
{
    std::stack<int> intStack;
    intStack.push(5);
    intStack.push(6);
    intStack.push(7);

    std::cout << "Top of the stack: " << intStack.top() << std::endl;

    // This removes the top of the stack, but does not return it.
    intStack.pop();

    std::cout << "Top of the stack: " << intStack.top() << std::endl;

    // Check if the stack is empty.
    std::cout << "Is the stack empty?: " << intStack.empty() << std::endl;

    // Get the size of the stack.
    std::cout << "Stack size: " << intStack.size() << std::endl;

    std::stack<int> otherStack;
    otherStack.push(2);

    // Exchanges contents of one stack with another.
    intStack.swap(otherStack);

    std::cout << "Stack size of intStack: " << intStack.size() << std::endl;
    std::cout << "Stack size of otherStack: " << otherStack.size() << std::endl;

    return 0;
}