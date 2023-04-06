// Demonstrates using references for variables, parameters, and return types.
#include <iostream>
#include <string>

void CallByValNum(int copyArgNum)
{
    std::cout << &copyArgNum << "<- copyArgNum address" << std::endl;
}

void CallByRefNum(int& refArgNum)
{
    std::cout << &refArgNum << "<- refArgNum address" << std::endl;
}

void CallByConstRefNum(const int& constRefArgNum)
{
    std::cout << &constRefArgNum << "<- constRefArgNum address" << std::endl;
}

class NumReturner
{
public:
    int ReturnByValNum()
    {
        std::cout << &memberNum << "<- memberNum address from ReturnByValNum" << std::endl;
        return memberNum;
    }

    int& ReturnByRefNum()
    {
        std::cout << &memberNum << "<- memberNum address from ReturnByRefNum" << std::endl;
        return memberNum;
    }

    const int& ReturnByConstRefNum()
    {
        std::cout << &memberNum << "<- memberNum address from ReturnByConstRefNum" << std::endl;
        return memberNum;
    }

private:
    int memberNum = 7;
};

int main()
{
    int num = 5;

    int copyNum = num;
    std::cout << "num and copyNum addresses the same? " << (&num == &copyNum) << std::endl;
    std::cout << &num << "<- num address" << std::endl;
    std::cout << &copyNum << "<- copyNum address: " << std::endl;

    int& refNum = num;
    std::cout << "num and refNum addresses the same? " << (&num == &refNum) << std::endl;
    std::cout << &num << "<- num address" << std::endl;
    std::cout << &refNum << "<- refNum address: " << std::endl;

    const int& constRefNum = num;
    std::cout << "num and constRefNum addresses the same? " << (&num == &constRefNum) << std::endl;
    std::cout << &num << "<- num address" << std::endl;
    std::cout << &constRefNum << "<- constRefNum address: " << std::endl;

    std::cout << "Comparing parameter flavors: pass by value, pass by reference, and pass by const reference."
        << std::endl;
    std::cout << &num << "<- num address" << std::endl;
    CallByValNum(num);
    CallByRefNum(num);
    CallByConstRefNum(num);

    NumReturner numReturner;
    std::cout << "Comparing return flavors: return by value, return by reference, and return by const reference."
        << std::endl;
    // Can't print address directly from call, need to store the returned value first.
    int returnByValNum = numReturner.ReturnByValNum(); 
    std::cout << &returnByValNum << "<- returnByValNum address" << std::endl;
    std::cout << &numReturner.ReturnByRefNum() << "<- ReturnByRefNum address" << std::endl;
    std::cout << &numReturner.ReturnByConstRefNum() << "<- ReturnByConstRefNum address" << std::endl;
        
    return 0;
}