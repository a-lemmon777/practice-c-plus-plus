// Explores using the string type and the getline function.
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <fstream>
using namespace std;

string ltrim(const string& str) {
    string s(str);

    s.erase(
        s.begin(),
        find_if(s.begin(), s.end(), not1(ptr_fun<int, int>(isspace)))
    );

    return s;
}

string rtrim(const string& str) {
    string s(str);

    s.erase(
        find_if(s.rbegin(), s.rend(), not1(ptr_fun<int, int>(isspace))).base(),
        s.end()
    );

    return s;
}

string gridChallenge(vector<string> grid) {
    const int stringLength = grid[0].length();
    for (std::string& row : grid)
    {
        row.resize(grid.size());
        std::sort(row.begin(), row.end());
    }
    for (int column = 0; column < stringLength; column++)
    {
        for (int row = 0; row < grid.size() - 1; row++)
        {
            //std::cout << "Comparing " << grid[row][column] << " > " << grid[row + 1][column] << std::endl;
            if (grid[row][column] > grid[row + 1][column])
            {
                //std::cout << "Not alphabetical." << std::endl;
                return "NO";
            }

        }
    }
    return "YES";
}

string gridChallenge2(vector<string> grid) {
    const int stringLength = grid[0].length();
    for (std::string& row : grid)
    {
        row.resize(grid.size());
        std::sort(row.begin(), row.end());
    }
    for (int i = 0; i < grid.size() - 1; i++)
    {
        if (grid[i] > grid[i + 1])
            return "NO";
    }
    return "YES";
}

int main()
{
    //cout << __cplusplus;
    //cout << std::filesystem::current_path();
    //ofstream fout(getenv("OUTPUT_PATH"));
    std::cout << "iv > ms cstring" << ("iv" > "ms") << std::endl;
    std::cout << "iv > ms c++string" << (std::string("iv") > std::string("ms")) << std::endl;
    std::fstream inFile("testCases.txt", std::fstream::in);

    string t_temp;
    getline(inFile, t_temp);

    int t = stoi(ltrim(rtrim(t_temp)));

    for (int t_itr = 0; t_itr < t; t_itr++) {
        string n_temp;
        getline(inFile, n_temp);

        int n = stoi(ltrim(rtrim(n_temp)));

        vector<string> grid(n);
        if (t_itr == 79)
        {
            std::cout << "In 79." << std::endl;
        }

        for (int i = 0; i < n; i++) {
            string grid_item;
            getline(inFile, grid_item);

            grid[i] = grid_item;
            if (grid[i].length() != n)
            {
                cout << "AHHHHHHHHH" << " t_itr: " << t_itr << " i: " << i << std::endl;
            }
        }
        std::string result1 = gridChallenge(grid);
        std::string result2 = gridChallenge2(grid);
        if (result1 != result2)
        {
            cout << "OOPS The algorithms give different results!" << std::endl;
            cout << "t_itr: " << t_itr << std::endl;
            cout << "result 1: " << result1 << " result 2: " << result2 << std::endl;
        }

        /*
        if (79 <= t_itr && t_itr <= 79)
        {
            result2 = gridChallenge2(grid);
        }
        else
        {
            result1 = gridChallenge(grid);
        }
        if (75 <= t_itr && t_itr <= 80)
        {
            cout << "AHHHHHHHHH" << " t_itr: " << t_itr << " n: " << n << std::endl;
        }
        */

        //string result = gridChallenge(grid);

        //fout << result << "\n";
    }
    inFile.close();
    //fout.close();

    return 0;
}
    /*
    const std::string format = "Hello %0.6f\n";
    const std::string otherFormat = "Bye %.6f\n";
    const std::string defaultPrecisionFormat = "Yolo %f\n";
    const double myNumber = 0.123456789;
    std::printf(format.c_str(), myNumber);
    std::printf(otherFormat.c_str(), myNumber);
    std::printf(defaultPrecisionFormat.c_str(), myNumber);
    std::printf("First%5dLast\n", 8);
    std::printf("First%05dLast\n", 8);
    const int eight = -8;
    std::printf("First%hhdLast\n", eight);
    std::printf("First%fLast\n", 8);
    std::vector<int> myVector = { 5, 4, 3, 2, 1 };
    std::sort(myVector.begin(), myVector.end());
    for (auto element : myVector)
        std::cout << element << std::endl;
    return 0;
    */
    /*
    * #### fstream stuff ####
    std::fstream outFile("PathToMyfile", std::fstream::out | std::fstream::app);
    std::fstream outFile("PathToMyfile", std::fstream::trunc);
    std::fstream::in;
    std::fstream::out;
    std::fstream::app; // add to the end, nothing is erased or deleted.
    std::fstream::ate; // add to the end. There are ways to move around in the file if you want.
    std::fstream::trunc; // overwrite as far as the new data goes, but keep old data.
    // completely clear whole file and write from the beginning
    std::fstream::binary;

    outFile << "asdf" << std::endl;
    outFile.close();

    std::fstream inFile("PathToMyFile", std::fstream::in);
    std::string myString = "";
    for (std::getline(inFile, myString); !inFile.eof(); std::getline(inFile, myString))
    {
        // Do something;
    }
    while (true)
    {
        std::getline(inFile, myString);
        if (inFile.eof())
            break;
    }

    // Writing address to file
    std::fstream addressFile("PathToFile", std::fstream::out);
    addressFile << "My Name" << std::endl;
    addressFile << "1234 Easy St." << std::endl;
    addressFile << "Somewhere, CA 99999" << std::endl;
    addressFile.close();

    // Reading in list of doubles, finding the average
    std::fstream numberFile("PathToFile", std::fstream::in);
    double numberRead = 0.0;
    double total = 0.0;
    int count = 0;
    while (true)
    {
        numberFile >> numberRead;
        if (numberFile.eof())
            break;
        total += numberRead;
        count++;
    }
    numberFile.close();
    std::cout << "The average was: " << (total / count) << std::endl;
    */
