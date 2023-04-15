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

    // You can access and modify from the front, back, or anywhere in the middle, all in constant time.
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
    for (std::deque<std::string>::iterator iter = heroes.begin(); iter != heroes.end(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "________" << std::endl;

    // You can remove from both the front and back in constant time.
    heroes.pop_front();
    heroes.pop_back();

    // Using an index-based loop.
    for (int i = 0; i < heroes.size(); ++i)
    {
        std::cout << heroes[i] << std::endl;
    }
    std::cout << "________" << std::endl;

    // Check if the deque is empty.
    std::cout << "Are all the hereos gone?: " << heroes.empty() << std::endl;

    // Insert using an iterator. Inserting into the interior of a deque takes O(n) time.
    std::deque<std::string>::const_iterator iterator = heroes.cbegin();
    iterator += 2; // Move the iterator to index 2.
    heroes.insert(iterator, "Thefrish the Mighty");

    // Using a reverse iterator to traverse the deque in reverse.
    std::cout << "Printing in reverse." << std::endl;
    for (std::deque<std::string>::const_reverse_iterator iter = heroes.crbegin(); iter != heroes.crend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "________" << std::endl;

    // Erase using an iterator. Erasing from the interior of a deque takes O(n) time.
    iterator = heroes.cbegin() + 4; // Move the iterator to index 4.
    heroes.erase(iterator);

    for (auto iter = heroes.cbegin(); iter != heroes.cend(); ++iter)
    {
        std::cout << *iter << std::endl;
    }
    std::cout << "________" << std::endl;

    // Using assign to copy values from another container to a deque. This replaces any contents that were already there.
    sameHeroes.assign(heroes.cbegin(), heroes.cend());
    for (std::string hero : sameHeroes)
    {
        std::cout << hero << std::endl;
    }
    std::cout << "________" << std::endl;

    // You can also use assign for placing many copies of a single value into the deque.
    sameHeroes.assign(6, "Rupligator the Duplicator");
    for (std::string hero : sameHeroes)
    {
        std::cout << hero << std::endl;
    }
    std::cout << "________" << std::endl;

    // You can also use assign with an initializer list.
    sameHeroes.assign({ "Abrizor the Adept", "Belvrica the Bold" });
    for (std::string hero : sameHeroes)
    {
        std::cout << hero << std::endl;
    }
    std::cout << "________" << std::endl;

    // You can use clear to empty the deque.
    sameHeroes.clear();
    std::cout << "Number of heroes in sameHeroes: " << sameHeroes.size() << std::endl;

    return 0;
}
