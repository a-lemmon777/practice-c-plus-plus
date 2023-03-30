// Explores using the string type.
#include <iostream>
#include <string>

int main()
{
    // Declaring a string variable
    const std::string myString = "Hello";
    std::cout << myString << std::endl;

    // Using cin to stream user input into a string. Using cin will only get the text up to the first whitespace
    // character.
    std::string userName = "";
    std::cout << "Please enter your name: ";
    std::cin >> userName;
    std::cout << "Nice to meet you, " << userName << "!" << std::endl;

    // This will ensure that the newline the user had input with the enter key is not read by getline below.
    std::cin.ignore();

    // Using getline to get an entire line from the user, including spaces and tabs.
    std::string catSentence = "";
    std::cout << "Please write a sentence about cats." << std::endl;
    std::getline(std::cin, catSentence);
    std::cout << "Here's what you had to say about cats:" << std::endl;
    std::cout << catSentence << std::endl;
    std::string dogSentence = "";
    std::cout << "Please write a sentence about dogs." << std::endl;
    std::getline(std::cin, dogSentence);
    std::cout << "Here's what you had to say about dogs:" << std::endl;
    std::cout << dogSentence << std::endl;

    // Using the + operator for string concatenation.
    std::string firstString = "Happy ";
    std::string secondString = "Birthday!";
    std::string birthdayMessage = firstString + secondString;
    std::cout << birthdayMessage << std::endl;

    return 0;
}