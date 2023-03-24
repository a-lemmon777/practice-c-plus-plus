// Explores the details of declaring, initializing, and accessing arrays.
#include <iostream>

// Elements of uninitialized arrays declared outside functions will be a zero of the array base type.
int arrayOutsideFunction[3];

int GetFive()
{
    return 5;
}

int main()
{
    // Elements of uninitialized arrays declared inside functions are not guaranteed
    // to be a zero of the array base type.
    int arrayInsideFunction[3];

    std::cout
        << "Elements of uninitialized arrays declared outside functions will be a zero of the array base type."
        << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << arrayOutsideFunction[i] << std::endl;
    }

    std::cout
        << "Elements of uninitialized arrays declared inside functions are not guaranteed"
        << " to be a zero of the array base type."
        << std::endl;
    for (int i = 0; i < 3; i++)
    {
        std::cout << arrayInsideFunction[i] << std::endl;
    }

    // Some C++ compilers won't allow non-constant array sizes.
    //int runtimeSizeArray[GetFive()];

    // Arrays can be declared with an explicit size.
    int arrayWithSize[2];

    // Arrays can be declared and initialized at the same time.
    int initializedArray[4] = { 5, 6, 7, 8 };

    // Arrays can be partially initialized. The rest of the elements will be a zero of the base type if the array
    // is declared outside a function, and not guaranteed to be zero if declared inside a function.
    int partiallyInitializedArray[5] = { 1, 2 };

    // An initialized array can infer its size.
    int inferredSizeArray[] = { 9, 10, 11 };

    // If not initialized, the array must include a size.
    //int arrayWithoutSize[];

    int arrayToCopy[3] = { 12, 13, 14 };

    // This does not work.
    //int copiedArray[3] = arrayToCopy;

    int lengthThreeArray[3] = { 15, 16, 17 };

    // Reading or writing out of bounds does not throw an exception. Be careful!
    //std::cout << lengthThreeArray[8];
    //lengthThreeArray[8] = 18;

    const int numberOfScores = 6;
    const int bowlingScores[6] = { 100, 78, 138, 94, 164, 89 };

    // No elements can be modified in a const array.
    //bowlingScores[0] = 3000;

    // Finds the highest bowling score.
    int highestScore = bowlingScores[0];
    for (int i = 1; i < numberOfScores; i++)
    {
        if (bowlingScores[i] > highestScore)
            highestScore = bowlingScores[i];
    }

    std::cout << "The highest bowling score: " << highestScore << std::endl;

    return 0;
}