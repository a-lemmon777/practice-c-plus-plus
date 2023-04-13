// Uses random number generation for a guessing game.
#include <cstdlib>
#include <ctime>
#include <iostream>

int main()
{
    // Generate a random number between 1 and 100 inclusive.
    std::srand(std::time(0));
    const int secretNumber = (std::rand() % 100) + 1;

    // Ask the player for a guess.
    int playerGuess = 0;
    int guessCount = 0;

    // Keep looping until the player guesses correctly.
    do
    {
        // Ask the player for a guess
        std::cout << "Please enter a number between 1 and 100 inclusive." << std::endl;
        std::cin >> playerGuess;
        guessCount++;

        // Tell the player if they guessed too high or too low.
        if (playerGuess < secretNumber)
            std::cout << "Your guess was too low. Try again!" << std::endl;
        else if (playerGuess > secretNumber)
            std::cout << "Your guess was too high. Try again!" << std::endl;

    } while (playerGuess != secretNumber);

    // Congratulate the player and tell them how many guesses it took.
    std::cout << "Congratulations, you guessed right! It took you " << guessCount << " guess(es).";
    return 0;
}
