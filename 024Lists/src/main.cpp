// Demonstrates using lists (doubly-linked lists).
#include <iostream>
#include <list>
#include <string>

class GroceryListItem
{
private:
    std::string m_foodName;
    int m_quantity;

public:
    GroceryListItem() : m_foodName(""), m_quantity(0)
    {
        std::cout << "Constructed a default GroceryListItem" << std::endl;
    }

    GroceryListItem(std::string foodName, int quantity) : m_foodName(foodName), m_quantity(quantity)
    {
        std::cout << "Constructed a GroceryListItem: {" << m_foodName << ", " << m_quantity << "}" << std::endl;
    }

    friend std::ostream& operator<<(std::ostream& out, const GroceryListItem& item);
};

std::ostream& operator<<(std::ostream& stream, const GroceryListItem& item)
{
    stream << "{" << item.m_foodName << ", " << item.m_quantity << "}";
    return stream;
}

int main()
{
    GroceryListItem myItem("Pickles", 8);
    std::cout << myItem << std::endl;

    return 0;
}
