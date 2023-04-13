// Explores the details of using vectors.
#include <iostream>
#include <vector>

std::vector<int> vectorOutsideOfFunction(4);

int GetFive()
{
    return 5;
}

void PrintVectorInfo(const std::vector<int>& vectorToPrint)
{
    std::cout << "Contents of vector: ";
    for (unsigned int i = 0; i < vectorToPrint.size(); i++)
        std::cout << vectorToPrint[i] << ' ';
    std::cout << std::endl;
    std::cout << "Size of vector: " << vectorToPrint.size() << std::endl;
    std::cout << "Capacity of vector: " << vectorToPrint.capacity() << std::endl;
    std::cout << "_________________________" << std::endl;
}

int main()
{
    // Using pushback.
    std::vector<int> myVector;
    myVector.push_back(5);
    myVector.push_back(6);
    myVector.push_back(7);

    std::cout << "Added 3 items to myVector." << std::endl;
    PrintVectorInfo(myVector);

    // Resizing smaller.
    myVector.resize(2);
    std::cout << "Resized myVector to size 2." << std::endl;
    PrintVectorInfo(myVector);

    // Resizing larger.
    myVector.resize(4);
    std::cout << "Resized myVector to size 4." << std::endl;
    PrintVectorInfo(myVector);

    // Resizing larger with a specified value for the new elements.
    myVector.resize(6, 8);
    std::cout << "Resized myVector to size 6, with a value of 8 being specified for the new elements." << std::endl;
    PrintVectorInfo(myVector);

    // Removing elements at the end.
    myVector.pop_back();
    std::cout << "Popped the back of the vector." << std::endl;
    PrintVectorInfo(myVector);

    // Getting the first and last elements
    std::cout << "First element: " << myVector.front() << " Last element: " << myVector.back() << std::endl;
    std::cout << std::endl;

    // Making a vector with an initial size.
    std::vector<int> vectorWithInitialSize(3);
    std::cout << "Declared a vector with an initial size of 3." << std::endl;
    PrintVectorInfo(vectorWithInitialSize);

    // Inspecting a vector declared outside of a function.
    std::cout << "Declared a vector with initial size of 4 outside a function." << std::endl;
    PrintVectorInfo(vectorOutsideOfFunction);

    // Initializing a vector with brace notation.
    std::vector<int> vectorWithBraceNotation = { 1, 2, 3 };
    std::cout << "Declared a vector initialized with brace notation." << std::endl;
    PrintVectorInfo(vectorWithBraceNotation);

    // Initializing a vector with brace notation and a matching size. This is not valid.
    //std::vector<int> vectorWithBraceNotationAndMatchingSize(2){ 4, 5 };

    // Initializing a vector with all the same value.
    std::vector<int> vectorFilledWithSingleValue(5, 9);
    std::cout << "Declared a vector with size 5, with all values set to 9." << std::endl;
    PrintVectorInfo(vectorFilledWithSingleValue);

    // Initializing with a size that's determined at runtime.
    std::vector<int> vectorWithSizeDeterminedAtRuntime(GetFive());
    std::cout << "Declared a vector whose size is determined at runtime. You couldn't do this with an array."
        << std::endl;
    PrintVectorInfo(vectorWithSizeDeterminedAtRuntime);

    // Assigning one vector to another
    std::vector<int> vector1 = { 10, 11, 12 };
    std::vector<int> vector2 = vector1;
    std::cout << "Declared a vector using the assignment operator with another vector." << std::endl;
    PrintVectorInfo(vector2);

    // "Overwriting" a vector with another one
    std::vector<int> vector3 = { 13, 14, 15 };
    std::vector<int> vector4 = { 1, 2, 3 };
    vector4 = vector3;
    std::cout << "Overwrote a vector with another vector using the assignment operator." << std::endl;
    PrintVectorInfo(vector4);

    // Assigning a vector to another, then modifying the first to see if it changes both.
    std::vector<int> vector5 = { 16, 17, 18 };
    std::vector<int> vector6 = vector5;
    vector5[0] = 0;
    std::cout << "Assigned one vector to another, then modified the first to see if both variables reference the "
        "same vector in memory. They are indeed separate copies." << std::endl;
    PrintVectorInfo(vector6);

    // Experimenting with const on a vector. Modifying the elements of the vector is not allowed by the compiler.
    const std::vector<int> constVector = { 19, 20, 21 };
    //constVector[0] = 0;
    //constVector.push_back(22);

    // Accessing out of bounds with both square brackets and at(). They both throw exceptions.
    std::vector<int> vectorToAccessOutOfBounds = { 22, 23, 24 };
    //std::cout << vectorToAccessOutOfBounds[10] << std::endl;
    //std::cout << vectorToAccessOutOfBounds.at(10) << std::endl;

    return 0;
}
