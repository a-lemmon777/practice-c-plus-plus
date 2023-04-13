// Demonstrates using deques.
#include <deque>
#include <iostream>
#include <string>

int main()
{
    // Deques can be initialized like this.
    std::deque<std::string> heroes{ "Gargoth the Tough", "Salvin the Quick", "Xilayna the Fierce" };
    
    // You could also use parenthesis.
    std::deque<std::string> sameHeroes({ "Gargoth the Tough", "Salvin the Quick", "Xilayna the Fierce" });
    
    // Checking the size.
    std::cout << "Number of heroes: " << heroes.size() << std::endl;

    // You can access and modify from the front, back, or anywhere in the middle.
    // Access to the front and back takes constant time.
    heroes.front().append("est");
    heroes[1].append("e");
    heroes.at(1).append("st");
    heroes.back().append("st");

    // Range-based for loop.
    for (std::string hero : heroes)
    {
        std::cout << hero << std::endl;
    }
    std::cout << "________" << std::endl;

    // You can add to both the front and back in constant time.
    heroes.push_front("Remilda the Wise");
    heroes.push_front("Kelwin the Brave");
    heroes.push_back("Breeloo the Vulgar");
    heroes.push_back("Enpira the Tall");

    // Looping with an iterator.
    for (std::deque<std::string>::iterator iter = heroes.begin(); iter != heroes.end(); iter++)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "________" << std::endl;

    // You can remove from both the front and back in constant time.
    heroes.pop_front();
    heroes.pop_back();

    // Using an index-based loop.
    for (int i = 0; i < heroes.size(); i++)
    {
        std::cout << heroes[i] << std::endl;
    }
    std::cout << "________" << std::endl;

    // Check if the deque is empty.
    std::cout << "Are all the hereos gone?: " << heroes.empty() << std::endl;

    return 0;
}
