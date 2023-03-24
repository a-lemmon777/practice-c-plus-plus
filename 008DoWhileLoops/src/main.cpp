// Uses a do while loop to implement a guessing game for the user.
#include <iostream>

int main()
{
    std::cout << "Let's play a guessing game!" << std::endl;
    std::cout << "Imagine 23 hats placed on a table in a row." << std::endl;
    std::cout << "Each hat has a number on it according to its position: the leftmost hat is 1 and the rightmost "
        "hat is 23." << std::endl;
    std::cout << "A friendly hamster named Douglas is hiding under a random hat. If you check under a hat and Douglas "
        "is not there, you must put the hat back." << std::endl;
    std::cout << "Then Douglas will move one hat further away from the one you guessed, if he can." << std::endl;
    std::cout << "See how many guesses it takes for you to find Douglas!" << std::endl;
    std::cout << std::endl;

    std::cout << "To start please enter any integer to seed the humble random number generator: ";
    int seed = 0;
    std::cin >> seed;
    std::cout << "Thanks! Douglas has found a random hat to hide under!" << std::endl;

    /*
    * To get Douglas' starting place, we need to generate a pseudorandom number based on the seed the user entered.
    * A crude but simple way to generate a pseudorandom number is to use a linear congruential generator. The parameters
    * chosen below comply with the Hull-Dobell Theorem so all hats should be a possible starting location for Douglas.
    */
    const int modulus = 23;
    // This formula ensures that adjustedSeed is between 0 and 22 inclusive even if the user entered a negative number.
    const int adjustedSeed = ((seed % modulus) + modulus) % modulus;
    const int multiplier = 5;
    const int increment = 1;
    // Uses a linear congruential generator to generate a number from 0 to 22 inclusive.
    int hidingSpot = ((adjustedSeed * multiplier) + increment) % modulus;
    // Add one to convert the hidingSpot to be a one-based index rather than zero-based index.
    hidingSpot++;

    int numGuesses = 0;
    bool isGuessCorrect = false;
    int guess = 0;
    do
    {
        std::cout << std::endl << "Please choose a hat to look under, from 1 to 23: ";
        std::cin >> guess;
        numGuesses++;
        if (guess < 1)
        {
            std::cout << "The number you entered is below the range, using 1 as the guess instead." << std::endl;
            guess = 1;
        }
        else if (guess > 23)
        {
            std::cout << "The number you entered is above the range, using 23 as the guess instead." << std::endl;
            guess = 23;
        }
        
        isGuessCorrect = (guess == hidingSpot);
        if (guess < hidingSpot)
        {
            std::cout << "You guessed too low. Douglas was in a higher-numbered hat!" << std::endl;
            // Douglas moves up a hat unless he's already in hat 23.
            if (hidingSpot < 23)
                hidingSpot++;
            std::cout << "Douglas has moved one hat higher! (unless he was already in the highest hat)" << std::endl;
        }
        else if (guess > hidingSpot)
        {
            std::cout << "You guessed too high. Douglas was in a lower-numbered hat!" << std::endl;
            // Douglas moves down a hat unless he's already in hat 1.
            if (hidingSpot > 1)
                hidingSpot--;
            std::cout << "Douglas has moved one hat lower! (unless he was already in the lowest hat)" << std::endl;
        }
    } while (!isGuessCorrect);

    std::cout << "Yay! You found Douglas! It took you " << numGuesses << " guess(es). Thanks for playing!" << std::endl;

    return 0;
}