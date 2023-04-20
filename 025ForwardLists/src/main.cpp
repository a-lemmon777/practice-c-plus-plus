// Demonstrates using forward lists (singly-linked lists).
#include <forward_list>
#include <iostream>
#include <string>

class Tree
{
private:
    std::string m_name;

public:
    Tree() : m_name("")
    {
        std::cout << "Called default constructor." << std::endl;
    }

    Tree(std::string name) : m_name(name)
    {
        std::cout << "Called initialization constructor. Tree name: " << ToString() << std::endl;
    }

    Tree(const Tree& other) : m_name(other.m_name)
    {
        std::cout << "Called copy constructor. Tree name: " << ToString() << std::endl;
    }

    const std::string& ToString() const
    {
        return m_name;
    }
};

void PrintList(std::forward_list<Tree>& treeList)
{
    std::cout << "Trees in list: ";
    for (Tree& tree : treeList)
    {
        std::cout << "{" << tree.ToString() << "} ";
    }
    std::cout << std::endl;
}

void PrintDivider()
{
    std::cout << "----------------------" << std::endl;
}

int main()
{
    std::cout << "Making a default tree" << std::endl;
    Tree defaultTree;

    PrintDivider();
    std::cout << "Making a few trees." << std::endl;
    Tree elmTree("Elm");
    Tree oakTree("Oak");
    Tree poplarTree("Poplar");

    PrintDivider();
    std::cout << "Building a forward list from back to front." << std::endl;
    std::forward_list<Tree> backToFrontList;
    backToFrontList.push_front(poplarTree);
    backToFrontList.push_front(oakTree);
    backToFrontList.push_front(elmTree);
    PrintList(backToFrontList);

    PrintDivider();
    std::cout << "Building a forward list from front to back." << std::endl;
    std::forward_list<Tree> frontToBackList;
    std::forward_list<Tree>::iterator iterator = frontToBackList.before_begin();
    iterator = frontToBackList.insert_after(iterator, elmTree);
    iterator = frontToBackList.insert_after(iterator, oakTree);
    iterator = frontToBackList.insert_after(iterator, poplarTree);
    PrintList(frontToBackList);

    return 0;
}
