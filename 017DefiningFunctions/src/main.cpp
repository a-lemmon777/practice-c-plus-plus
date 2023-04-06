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
float averageThreeNumbers(float first, float second, float third);

/* Examples of overloading */
float average(float first, float second)
{
    return (first + second) / 2.0;
}

float average(float first, float second, float third)
{
    return (first + second + third) / 3.0;
}

float average(float first, float second, float third, float fourth)
{
    return (first + second + third + fourth) / 4.0;
}

/* Overloading parameter matching */
// If you try to call printNum with a decimal point literal (a double), it won't know which function to call here.
void printNum(int value)
{
    std::cout << value << std::endl;
}

void printNum(float value)
{
    std::cout << value << std::endl;
}

// Can't overload with same name and parameter types, but different return type.
// The return type is not part of the function signature!
//double average(float first, float second);

// Defining a function with default parameters
void printPair(int first = 10, int second = 20)
{
    std::cout << first << " " << second << std::endl;
}

int main()
{
    sayHello();

    std::string sentence = "The cow jumped over the moon.";
    std::cout << "Sentence:" << std::endl << sentence << std::endl;
    std::cout << "Number of spaces in the sentence: " << countSpaces(sentence) << std::endl;

    std::vector<int> vectorOfInts = { 1, 2, 3, 4, 5, 6 };
    std::cout << "Largest number in the vector: " << getLargestNum(vectorOfInts) << std::endl;
    std::cout << "Average of 2.0, 2.5, and 3.0: " << averageThreeNumbers(2.0, 2.5, 3.0) << std::endl;
    std::cout << "Using 3 versions of overloaded functions:" << std::endl;
    std::cout << average(2.1, 2.2) << std::endl;
    std::cout << average(3.1, 3.2, 3.3) << std::endl;
    std::cout << average(4.1, 4.2, 4.3, 4.4) << std::endl;

    // This doesn't work, it's ambiguous which function signature to match.
    // Print num has two overloaded definitions, one that takes an int and one that takes a float.
    // Here, the double 5.0 could be converted to either int or float, so it won't compile.
    //printNum(5.0);

    // This works by using a floating point literal.
    printNum(5.0f);

    // The function printPair has two default parameters: first = 10, and second = 20.
    printPair();
    printPair(50, 60);
    printPair(100); // Here, only the second default will be used.

    // You can't do something like this to use a default for the first param but not the second param.
    //printPair(, 100); 

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

// The parameter names don't need to match the function declaration, but it'd be nicer if they did!
float averageThreeNumbers(float a, float b, float c)
{
    return (a + b + c) / 3.0;
}