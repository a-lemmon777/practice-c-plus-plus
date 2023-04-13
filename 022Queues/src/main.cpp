// Demonstrates using queues.
#include <iostream>
#include <queue>

int main()
{
    std::queue<std::string> ferrisWheelQueue;

    // Adding people to the back of the queue.
    ferrisWheelQueue.push("Greg");
    ferrisWheelQueue.push("Monique");
    ferrisWheelQueue.push("Lisa");

    // Checking if the queue is empty.
    std::cout << "Is the queue empty?: " << ferrisWheelQueue.empty() << std::endl;

    // Getting the size of the queue.
    std::cout << "Queue size: " << ferrisWheelQueue.size() << std::endl;

    // Accessing the front of the queue. Since it returns by reference, the value there can be modified.
    std::cout << "Person at the front: " << ferrisWheelQueue.front() << std::endl;
    ferrisWheelQueue.front().append("ggg");
    std::cout << "Person at the front: " << ferrisWheelQueue.front() << std::endl;

    // Accessing the back of the queue. Since it returns by reference, the value there can be modified.
    std::cout << "Person at the back: " << ferrisWheelQueue.back() << std::endl;
    ferrisWheelQueue.back().append("aaa");
    std::cout << "Person at the back: " << ferrisWheelQueue.back() << std::endl;

    // Remove someone from the front of the queue.
    ferrisWheelQueue.pop();
    std::cout << "Person at the front: " << ferrisWheelQueue.front() << std::endl;

    // Queues can be initialized like this.
    std::queue<int> intQueue({ 3, 8, 10, 12 });

    // Looping over (and emptying) a queue with an unconventional-looking for loop.
    for (; !intQueue.empty(); intQueue.pop())
    {
        std::cout << intQueue.front() << " ";
    }
    std::cout << std::endl;


    return 0;
}