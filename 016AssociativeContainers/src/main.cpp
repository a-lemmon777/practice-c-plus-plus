// Uses several kinds of multitype containers.
#include <iostream>
#include <string>
#include <utility>

int main()
{
    // Using the pair type.
    std::pair<std::string, int> person;
    person.first = "Barb";
    person.second = 62;
    std::cout << person.first << " is " << person.second << " years old." << std::endl;
    std::pair<std::string, int> otherPerson("Jenny", 44);
    person.swap(otherPerson);
    std::cout << "Person: " << person.first << " " << person.second << std::endl;
    std::cout << "OtherPerson: " << otherPerson.first << " " << otherPerson.second << std::endl;
    person = std::make_pair("Jordan", 38);
    std::cout << "Person: " << person.first << " " << person.second << std::endl;

    return 0;
}