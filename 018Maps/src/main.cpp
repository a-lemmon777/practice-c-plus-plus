// Demonstrates using maps.
#include <iostream>
#include <map>
#include <string>

int main()
{
    // Maps don't necessarily have things in the order you added them.
    std::map<std::string, int> flowerCounts;

    // Adding to the map with square bracket notation.
    flowerCounts["Tulip"] = 12;
    flowerCounts["Daisy"] = 10;
    flowerCounts["Rose"] = 20;

    // Adding with insert.
    // Insert returns a pair with 2 parts: An iterator to the element added (or the element that was already there)
    // and a boolean that's true if the element was added or false if the key was already in the map.
    std::pair<std::map<std::string, int>::iterator, bool> insertReturn;
    insertReturn = flowerCounts.insert({ "Orchid", 30 });
    std::cout << "Inserting Orchid first time. Success? " << insertReturn.second << std::endl;
    insertReturn = flowerCounts.insert({ "Orchid", 10000 });
    std::cout << "Inserting Orchid first time. Success? " << insertReturn.second << std::endl;
    std::cout << "There should be 30 Orchids: " << flowerCounts.at("Orchid") << std::endl;

    // Another example of insert.
    flowerCounts.insert(std::pair<std::string, int>("Lily", 5));

    // Adding with emplace. You can pass the key and value separately, rather than needing to pair them yourself.
    flowerCounts.emplace("Carnation", 4);

    // Looking up the value of a key with square brackets. Careful! It will add the key if it's not there.
    std::cout << "Number of tulips: " << flowerCounts["Tulip"] << std::endl;

    // Looking up a key that isn't there with square brackets.
    // Returns 0. Careful! It will add the key if it's not there.
    std::cout << "Number of dandelions: " << flowerCounts["Dandelion"] << std::endl;

    // For safer access, use at().
    std::cout << "Number of roses: " << flowerCounts.at("Rose") << std::endl;

    // You can use at() to alter the value at a key.
    flowerCounts.at("Rose") = 100;

    // at() will throw an exception if the key isn't found.
    //flowerCounts.at("AAAAAAA");

    // Getting the number of entries (size)
    std::cout << "Number of entries in map: " << flowerCounts.size() << std::endl;

    // Iterating through the entries
    // They seem to be in alphabetical order.
    std::cout << "Iterating with a while loop:" << std::endl;
    std::map<std::string, int>::iterator it = flowerCounts.begin();
    while (it != flowerCounts.end())
    {
        std::cout << it->first << ": " << it->second << std::endl;
        it++;
    }

    // Iterating through with a range-based for loop.
    std::cout << "Iterating with a range-based for loop:" << std::endl;
    // Could also use (std::map<std::string, int>::value_type pair : flowerCounts)
    // OR (auto pair : flowerCounts)
    for (std::pair<std::string, int> pair : flowerCounts)
    {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    // Iterating through with an old-style for loop.
    std::cout << "Iterating with an old-style for loop:" << std::endl;
    // You could also use auto for the iterator type.
    for (std::map<std::string, int>::iterator it = flowerCounts.begin(); it != flowerCounts.end(); it++)
    {
        std::cout << it->first << ": " << it->second << std::endl;
    }

    /* Things to try */
    // Add
    // Lookup
    // Update a value at a key
    // Move a value to a different key
    // Remove
    // Check if a key exists
    // Clear
    // Iterate through
}