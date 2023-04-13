// Explores usages of stringstream.
#include <iostream>
#include <sstream>
#include <string>

int main()
{
    // You cannot use getline to write into a stringstream.
    //std::stringstream userInputStream;
    //std::getline(std::cin, userInputStream);

    // You must use getline into a string first, then make a stringstream from the string.
    std::string userInput;
    std::cout << "Please enter your first name: " << std::endl;
    std::getline(std::cin, userInput);
    std::stringstream userInputStream(userInput);
    std::cout << "Your name was read in to a string, and that string was used to make a stringstream!" << std::endl;

    // Does the extraction operator (>>) read past whitespace with stringstreams? No, stops at first whitespace.
    std::stringstream twoWordStream("Basket Weaving");
    std::string oneWordString;
    twoWordStream >> oneWordString; // Will only stream until the first whitespace, just like cin works.
    std::cout << "Should print \"Basket\": " << oneWordString << std::endl;

    // Does the extraction operator (>>) skip over multiple whitespace characters in a row with stringstreams? Yes.
    std::stringstream extraSpacesStream("Apple  \n   Banana");
    std::string appleString;
    std::string bananaString;
    extraSpacesStream >> appleString; // Will only stream until the first whitespace, just like cin works.
    extraSpacesStream >> bananaString; // Skips over all the whitespace. Will store just "Banana".
    std::cout << "Should print \"Apple\": " << appleString << std::endl;
    std::cout << "Should print \"Banana\": " << bananaString << std::endl;
    
    // Can you append onto an already initialized stream? Not like this!
    std::stringstream overwritingStream("abcdefghij");
    overwritingStream << "0123";
    overwritingStream << "ZYX";
    // Perhaps surprisingly, it doesn't append to the end, but starts overwriting from the beginning.
    std::cout << "Should print \"0123ZYXhij\": " << overwritingStream.str() << std::endl;

    // If you want to start writing at the end, move the output position indicator to the end.
    std::stringstream appendingStream("abcdefghij");
    // The 0 in seekp is an offset.
    // Since we want to go exactly at the end, we don't want it to be negative or positive here.
    appendingStream.seekp(0, std::ios::end);
    appendingStream << "0123";
    appendingStream << "ZYX";
    std::string resultString = appendingStream.str();
    std::cout << "Should print \"abcdefghij0123ZYX\": " << resultString << std::endl;

    // Write to, then read from, a stringstream.
    std::stringstream readWrite;
    readWrite << "Age " << 5 << "Weight " << 150.0;
    std::string ageString;
    int age;
    std::string weightString;
    double weight;
    readWrite >> ageString >> age >> weightString >> weight;
    std::cout << ageString << " " << age << " " << weightString << " " << weight << std::endl;

    // Does reading and writing affect where each reading and writing leaves off? No.
    std::stringstream sportStream;
    sportStream << "Swimming " << "Diving ";
    std::string swim;
    sportStream >> swim; // Read from the beginning.
    sportStream << "Fencing " << "Climbing "; // Write from where we left off writing, not reading.
    std::string dive;
    sportStream >> dive; // Read from where we left off reading, not writing.
    std::cout << "Swimming and Diving: " << swim << dive << std::endl;
    std::cout << "Entire sportStream: " << sportStream.str() << std::endl;

    // Using getline to read from a stringstream.
    std::stringstream addressStream("Bob Bobson\n123 Easy Street"); // No newline after street, it works fine.
    std::string name;
    std::string street;
    std::getline(addressStream, name);
    std::getline(addressStream, street);
    std::cout << "Name: " << name << " Street: " << street << std::endl;

    // Using a while loop to read from a stringstream.
    std::stringstream multilineStream1("AAA\nBBB\nCCC"); // No newline at the end.
    int iterations = 0;
    // tellg() returns the position that the "getter" indicator is in.
    std::cout << "multilineStream1.tellg(): " << multilineStream1.tellg() << std::endl;
    // Just like eof() for filestreams, eof() only returns true once you've tried to read past the end of the stream.
    // This will happen after reading "CCC" since getline will try to read a newline that isn't there.
    while (!multilineStream1.eof()) 
    {
        iterations++;
        std::cout << "Num iterations (starting at 1): " << iterations << std::endl;
        std::string line;
        std::getline(multilineStream1, line);
        std::cout << "multilineStream1.tellg(): " << multilineStream1.tellg() << std::endl;
        std::cout << line << std::endl;
    }
    std::cout << "While loop is done." << std::endl;

    // Trying the same thing as above, but with a newline at the end of the stream.
    std::stringstream multilineStream2("DDD\nEEE\nFFF\n"); // Newline at the end here!
    iterations = 0;
    std::cout << "multilineStream2.tellg(): " << multilineStream2.tellg() << std::endl;
    // This has 4 iterations instead of 3.
    // I suppose this makes sense, you could consider the 4th line to be an empty string.
    while (!multilineStream2.eof())
    {
        iterations++;
        std::cout << "Num iterations (starting at 1): " << iterations << std::endl;
        std::string line = "blah"; // This becomes an empty string for the last iteration.
        std::getline(multilineStream2, line);
        std::cout << "multilineStream2.tellg(): " << multilineStream2.tellg() << std::endl;
        std::cout << line << std::endl;
    }
    std::cout << "While loop is done." << std::endl;

    // How does looping over a stream that hasn't been given an initial string behave? Reads a single empty string.
    std::stringstream streamNoString;
    iterations = 0;
    std::cout << "streamNoString.tellg(): " << streamNoString.tellg() << std::endl; // Starts at 0.
    // This has 1 iteration.
    while (!streamNoString.eof())
    {
        iterations++;
        std::cout << "Num iterations (starting at 1): " << iterations << std::endl;
        std::string line = "blah"; // This gets set to empty string by getline().
        std::getline(streamNoString, line);
        std::cout << "streamNoString.tellg(): " << streamNoString.tellg() << std::endl; // Is -1 here.
        std::cout << line << std::endl;
    }
    std::cout << "While loop is done." << std::endl;

    // How does looping over a stream that has been given an initial empty string behave? Reads a single empty string.
    std::stringstream streamEmptyString("");
    iterations = 0;
    std::cout << "streamEmptyString.tellg(): " << streamEmptyString.tellg() << std::endl; // Starts at 0.
    // This has 1 iteration.
    while (!streamEmptyString.eof())
    {
        iterations++;
        std::cout << "Num iterations (starting at 1): " << iterations << std::endl;
        std::string line = "blah"; // This gets set to empty string by getline().
        std::getline(streamEmptyString, line);
        std::cout << "streamEmptyString.tellg(): " << streamEmptyString.tellg() << std::endl; // Is -1 here.
        std::cout << line << std::endl;
    }
    std::cout << "While loop is done." << std::endl;

    // Can you write to a const stringstream? No.
    const std::stringstream constOutStream;
    // Won't compile.
    //constOutStream << "falcon";

    // Can you read from a const stringstream? No.
    const std::stringstream constInStream("duck");
    std::string duck;
    // Neither line will compile.
    //constInStream >> duck;
    //std::getline(constInStream, duck);

    // You can use ostringstream (o for output) for solely writing to the stream.
    std::ostringstream outStream;
    outStream << "eagle";
    std::cout << outStream.str() << std::endl;

    // You can use istringstream (i for input) for solely reading from the stream.
    std::istringstream inStream("goose");
    std::string goose;
    inStream >> goose;
    std::cout << goose << std::endl;

    return 0;
}
