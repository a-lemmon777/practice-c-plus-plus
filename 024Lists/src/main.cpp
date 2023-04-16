// Demonstrates using lists (doubly-linked lists), focusing on how the functions impact underlying element construction.
#include <iostream>
#include <list>
#include <string>
#include <utility>

class GroceryItem
{
private:
    std::string m_foodName;
    int m_quantity;

public:
    GroceryItem() : m_foodName(""), m_quantity(0)
    {
        std::cout << "Constructed a default GroceryItem: " << ToString() << std::endl;
    }

    GroceryItem(std::string foodName, int quantity) : m_foodName(foodName), m_quantity(quantity)
    {
        std::cout << "Constructed a GroceryItem: " << ToString() << std::endl;
    }

    GroceryItem(const GroceryItem& other) : m_foodName(other.m_foodName), m_quantity(other.m_quantity)
    {
        std::cout << "Constructed a GroceryItem with a copy constructor: " << ToString() << std::endl;
    }

    GroceryItem& operator=(const GroceryItem& other)
    {
        std::cout << "GroceryItem assignment operator. Old data: " << ToString();
        if (this == &other)
        {
            std::cout << " The two references are identical. No need to copy member variables!" << std::endl;
            return *this;
        }

        m_foodName = other.m_foodName;
        m_quantity = other.m_quantity;
        std::cout << " New data: " << ToString() << std::endl;
        return *this;
    }

    std::string ToString()
    {
        return "{" + m_foodName + ", " + std::to_string(m_quantity) + "}";
    }
};

// If the list is not passed by reference, a copy constructor will be called for every item!
void PrintList(std::list<GroceryItem>& groceryList)
{
    std::cout << "List contents: ";
    // If the items are not gotten by reference, a copy constructor will be called for every item!
    for (GroceryItem& item : groceryList)
    {
        std::cout << item.ToString() << " ";
    }
    std::cout << std::endl;
}

void PrintDivider()
{
    std::cout << "----------------------" << std::endl;
}

int main()
{
    GroceryItem defaultItem;
    GroceryItem pickleItem("Pickles", 8);
    GroceryItem copiedItem(pickleItem);
    std::cout << pickleItem.ToString() << std::endl;

    PrintDivider();
    std::cout << "Making a list with 3 default items." << std::endl;
    std::list<GroceryItem> groceryList(3);
    PrintList(groceryList);

    PrintDivider();
    std::cout << "Making a list initialized with pre-constructed Pickles item 3 times." << std::endl;
    std::list<GroceryItem> lotsOfPickles(3, pickleItem);
    PrintList(lotsOfPickles);

    PrintDivider();
    std::cout << "Creating some more items." << std::endl;
    GroceryItem appleItem("Apples", 4);
    GroceryItem pumpkinItem("Pumpkins", 2);
    GroceryItem tofuItem("Tofu", 3);

    PrintDivider();
    std::cout << "Making a list with pre-constructed items using a braced init list." << std::endl;
    // Copy constructors are still used twice for each item even if you don't use parentheses like this:
    //std::list<GroceryItem> bracedInitList{ appleItem, pumpkinItem, tofuItem };
    std::list<GroceryItem> bracedInitList({ appleItem, pumpkinItem, tofuItem });
    std::cout << "Whoa! The copy constructor was used twice for each item!" << std::endl;
    PrintList(bracedInitList);

    PrintDivider();
    std::cout << "Using a not-by-reference range-based for loop to print the items." << std::endl;
    std::cout << "A copy constructor is used for each item!" << std::endl;
    for (GroceryItem item : bracedInitList)
    {
        std::cout << item.ToString() << " ";
    }
    std::cout << std::endl;

    PrintDivider();
    std::cout << "Making a list with a braced init list, but newly constructing each object within the braces."
        << std::endl;
    std::cout << "Only one copy constructor per item this time." << std::endl;
    std::list<GroceryItem> bracedInitWithConstructors({ GroceryItem("Spaghetti", 2), GroceryItem("Sauce", 1) });
    PrintList(bracedInitWithConstructors);

    PrintDivider();
    std::cout << "Making a list using an iterator." << std::endl;
    std::list<GroceryItem> iteratorList(bracedInitList.begin(), bracedInitList.end());
    PrintList(iteratorList);

    PrintDivider();
    std::cout << "Making a list with the list copy constructor." << std::endl;
    std::list<GroceryItem> copyConstructorList(bracedInitList);
    PrintList(copyConstructorList);

    PrintDivider();
    std::cout << "Making a list with the list move constructor." << std::endl;
    std::list<GroceryItem> moveConstructorList(std::move(copyConstructorList));
    PrintList(moveConstructorList);
    std::cout << "The list we moved from is now empty. The compiler warns we're using a moved from object."
        << std::endl;
    PrintList(copyConstructorList);

    PrintDivider();
    std::list<GroceryItem> assignedList;
    std::cout << "Assigning to a list using copy assignment." << std::endl;
    assignedList = moveConstructorList;
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assigning to a list using move assignment." << std::endl;
    assignedList.clear();
    assignedList = std::move(moveConstructorList);
    PrintList(assignedList);
    std::cout << "The list we moved from is now empty. The compiler warns we're using a moved from object."
        << std::endl;
    PrintList(moveConstructorList);

    PrintDivider();
    std::cout << "Assigning to a list with pre-constructed items using a braced init list." << std::endl;
    assignedList.clear();
    assignedList = { appleItem, pumpkinItem, tofuItem };
    std::cout << "Whoa! The copy constructor was used twice for each item!" << std::endl;
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assigning to a list with a braced init list, but newly constructing each object within the braces."
        << std::endl;
    std::cout << "Only one copy constructor per item this time." << std::endl;
    assignedList.clear();
    assignedList = { GroceryItem("Salt", 1), GroceryItem("Pepper", 1) };
    PrintList(assignedList);

    return 0;
}
