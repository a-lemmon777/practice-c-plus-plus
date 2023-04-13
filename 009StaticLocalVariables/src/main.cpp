// Demonstrates using static local variables, which stay in memory for the entire execution of the program.
#include <iostream>

int main()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            /*
            * staticLocalVariable will be declared and initialized only once for the whole program.
            * The memory will persist for the whole execution of the program, even when out of scope. The variable is
            * inaccessible when out of scope, but can be accessed again if the scope is entered again.
            */
            static int staticLocalVariable = 0;
            std::cout << staticLocalVariable << std::endl;
            staticLocalVariable++;
        }
        // The line below would not compile since staticLocalVariable is out of scope here.
        // std::cout << staticLocalVariable << std::endl;
    }

    // The line below would not compile since staticLocalVariable is out of scope here.
    // std::cout << staticLocalVariable << std::endl;
    return 0;
}
