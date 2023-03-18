// Uses an array to store bowling scores.
#include <iostream>

int main()
{
    int numberOfScores = 6;
    int bowlingScores[6] = { 100, 78, 138, 94, 164, 89 };

    // Finds the highest bowling score.
    int highestScore = bowlingScores[0];
    for (int i = 1; i < numberOfScores; i++) {
        if (bowlingScores[i] > highestScore) {
            highestScore = bowlingScores[i];
        }
    }

    std::cout << "The highest bowling score: " << highestScore << std::endl;

    return 0;
}