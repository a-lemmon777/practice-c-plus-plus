// Demonstrates using maps.
#include <iostream>
#include <map>
#include <string>

int main()
{
    // Maps don't necessarily have things in the order you added them.
    std::map<std::string, int> flowerCounts;

    // Adding to the map with square bracket notation.
    // The square brackets actually create a new element with the given key, and returns a reference to the value.
    // Then assignment can be used on the reference.
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
    std::cout << "Inserting Orchid second time. Success? " << insertReturn.second << std::endl;
    std::cout << "There should be 30 Orchids: " << flowerCounts.at("Orchid") << std::endl;

    // Another example of insert.
    flowerCounts.insert(std::pair<std::string, int>("Lily", 5));

    // Adding with emplace. You can pass the key and value separately, rather than needing to construct the pair
    // yourself. It returns a pair of iterator and bool, just like insert().
    insertReturn = flowerCounts.emplace("Carnation", 4);

    // Looking up the value of a key with square brackets. Careful! It will add the key if it's not there.
    std::cout << "Number of tulips: " << flowerCounts["Tulip"] << std::endl;

    // Looking up a key that isn't there with square brackets.
    // Returns 0. Careful! It will add the key if it's not there.
    std::cout << "Number of dandelions: " << flowerCounts["Dandelion"] << std::endl;

    // For safer access, use at().
    std::cout << "Number of roses: " << flowerCounts.at("Rose") << std::endl;

    // You can use at() to get a reference to the value. If you want you can then alter that value..
    flowerCounts.at("Rose") = 100;

    // at() will throw an exception if the key isn't found.
    //flowerCounts.at("AAAAAAA");

    // You can get access to a whole key/value pair with find().
    std::map<std::string, int>::iterator iter = flowerCounts.find("Daisy");
    std::cout << "Found: " << iter->first << ", Value: " << iter->second << std::endl;
    // You can modify the value if you want, but not the key.
    iter->second = 10000;
    //iter->first = "Porcupine";


    // If the element doesn't exist, find() will return an iterator to past-the-end, equal to map.end().
    // With that iterator, you won't be able to do ->first or ->second.
    iter = flowerCounts.find("Llama");
    //std::cout << "Found: " << iter->first << ", Value: " << iter->second << std::endl;

    // Check if a key already exists with count. Since keys must be unique with maps, count will return only 0 or 1.
    std::cout << "Is Squirrel in the map?: " << flowerCounts.count("Squirrel") << std::endl;
    std::cout << "Is Rose in the map?: " << flowerCounts.count("Rose") << std::endl;

    // You can remove an element by key with erase(). It will return 1 if the element was removed and 0 if not.
    int erased = flowerCounts.erase("Daisy");
    std::cout << "Daisy erased?: " << erased << std::endl;

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

    // You can clear the whole map with clear().
    flowerCounts.clear();
    std::cout << "The map flowerCounts was cleared. Size: " << flowerCounts.size();
}
