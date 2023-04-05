// Demonstrates writing functions.
#include <iostream>
#include <string>
#include <vector>

// Defining a void function.
void sayHello()
{
    std::cout << "Hello" << std::endl;
    // Having a return statement is optional, it can be useful for exiting the function early.
    return;
}

// Defining a function with a return value.
int countSpaces(std::string inputString)
{
    int count = 0;
    for (char character : inputString)
    {
        if (character == ' ')
            count++;
    }
    return count;
}

// If you want to define a function later in the file than when it's called, you must write a
// function declaration (aka function prototype) earlier in the file than when it's called.
// Don't forget the semicolon at the end here!
int getLargestNum(std::vector<int> vectorToSearch);

int main()
{
    sayHello();

    std::string sentence = "The cow jumped over the moon.";
    std::cout << "Sentence:" << std::endl << sentence << std::endl;
    std::cout << "Number of spaces in the sentence: " << countSpaces(sentence) << std::endl;

    std::vector<int> vectorOfInts = { 1, 2, 3, 4, 5, 6 };
    std::cout << "Largest number in the vector: " << getLargestNum(vectorOfInts) << std::endl;

    return 0;
}

// This is the function definition, consisting of 2 parts: the function header and the function body.
// The function declaration (aka function prototype) is written above main so the function can be called in main.
int getLargestNum(std::vector<int> vectorToSearch)
{
    if (vectorToSearch.size() == 0)
        return -1; // No numbers to search.
    int max = vectorToSearch[0];
    for (int i = 1; i < vectorToSearch.size(); i++)
    {
        if (vectorToSearch[i] > max)
            max = vectorToSearch[i];
    }
    return max;
}