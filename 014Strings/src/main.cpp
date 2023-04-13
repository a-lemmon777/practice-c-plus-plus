// Explores using the string type and the getline function.
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
    const std::string happyString = "Happy ";
    const std::string birthdayString = "Birthday!";
    const std::string birthdayMessage = happyString + birthdayString;
    std::cout << birthdayMessage << std::endl;

    const std::string beforePlus = "BeforeVariable";
    const std::string afterPlus = "AfterVariable";

    // It's ok to use the + operater if one of the operands is a C++ string.
    std::cout << (beforePlus + "AfterLiteral") << std::endl;
    std::cout << ("BeforeLiteral" + afterPlus) << std::endl;
    // It's not ok to use the + operater if both operands are literals, because they are C strings, not C++ strings.
    //std::cout << ("BeforeLiteral" + "AfterLiteral") << std::endl;

    // The string class can be used much like a vector.
    std::string hockeyString = "Hockey";
    std::cout << hockeyString[0] << std::endl;
    std::cout << hockeyString.at(1) << std::endl;
    std::cout << hockeyString.size() << std::endl;
    hockeyString.resize(30); // Expands the string, filling with null characters.
    std::cout << hockeyString.size() << std::endl;
    std::cout << (int)hockeyString[6] << std::endl;

    // You can also use .length() instead of .size().
    std::cout << hockeyString.length() << std::endl;

    // You can use == and != on strings. It checks the content of the strings, not the memory addresses.
    const std::string soccerString = "Soccer";
    const std::string otherSoccerString = "Soccer";
    std::cout << (soccerString == otherSoccerString) << std::endl;
    std::cout << (&soccerString) << std::endl;
    std::cout << (&otherSoccerString) << std::endl;

    // You can also use < and > operators on strings.
    const std::string horseString = "horse";
    const std::string horseStringCaps = "HORSE";
    const std::string horseFlyString = "horsefly";
    // All capital letters come before all lowercase letters on the ascii table, so capitals are lesser than lowercase.
    std::cout << (horseStringCaps < horseString) << std::endl;
    // If two strings have mostly the same contents, but one has some extra characters, the longer string is greater.
    std::cout << (horseString < horseFlyString) << std::endl;

    // You can convert C strings to C++ strings inline.
    std::cout << std::string("Bob").size() << std::endl;

    // You can check if a string is an empty string.
    const std::string emptyString = "";
    const bool isEmpty = emptyString.empty();
    std::cout << isEmpty << std::endl;

    // You can find the first position of one string in another. If not found, it will return string::npos.
    int indexFound = horseFlyString.find(horseString);
    std::cout << indexFound << std::endl;
    indexFound = emptyString.find(horseString);
    std::cout << (indexFound == std::string::npos) << std::endl;

    // You can use substr (substring) with a starting index and length as arguments.
    std::cout << horseFlyString.substr(5, 3) << std::endl;

    // You can use the replace function to replace a subset of a string with another string.
    std::string fearFloorString = "fear";
    // Uses iterators. The end index should be one larger than the last index you wish to replace.
    fearFloorString.replace(fearFloorString.begin() + 1, fearFloorString.begin() + 3, "loo");
    std::cout << fearFloorString << std::endl;
    // Here, the first argument is the beginning index, and the second argument is the length to replace.
    fearFloorString.replace(1, 3, "ea");
    std::cout << fearFloorString << std::endl;

    return 0;
}
