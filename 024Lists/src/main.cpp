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
        std::cout << "Copy constructed a GroceryItem: " << ToString() << std::endl;
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

    std::string ToString() const
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
    std::cout << "Making some grocery items and a sandwich list for the next examples." << std::endl;
    GroceryItem slicedBread("Sliced Bread", 1);
    GroceryItem peanutButter("Peanut Butter", 1);
    GroceryItem jelly("Jelly", 1);
    GroceryItem baguette("Baguette", 3);
    std::list<GroceryItem> sandwichList{ slicedBread, peanutButter, jelly };

    PrintDivider();
    std::cout << "I think the assign operator and function completely replace the elements in a list with newly"
        " specified elements." << std::endl;
    std::cout << "They will \"reuse\" any existing elements in the list by using the element type's assignment"
        " operator." << std::endl;
    std::cout << "This means that the existing elements will be modified in-place with new data for its member"
        " variables." << std::endl;
    std::cout << "If there are more old elements than new elements, any extra old ones will be removed." << std::endl;
    std::cout << "If there are more new elements than old elements, the extra new elements will be newly constructed."
        << std::endl;

    PrintDivider();
    std::cout << "Operator assigning to a list." << std::endl;
    std::cout << "Starting a list with 2 kinds of bread." << std::endl;
    std::list<GroceryItem> assignedList;
    assignedList.push_back(slicedBread);
    assignedList.push_back(baguette);
    PrintList(assignedList);
    std::cout << "Operator assigning here." << std::endl;
    assignedList = sandwichList;
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Operator assigning to a list using move assignment." << std::endl;
    std::cout << "Starting a list with 2 kinds of bread." << std::endl;
    assignedList.clear();
    assignedList.push_back(slicedBread);
    assignedList.push_back(baguette);
    PrintList(assignedList);
    std::cout << "Operator assigning here." << std::endl;
    assignedList = std::move(sandwichList);
    PrintList(assignedList);
    std::cout << "The list we moved from is now empty. The compiler warns we're using a moved from object."
        << std::endl;
    PrintList(sandwichList);

    PrintDivider();
    std::cout << "Operator assigning to a list with pre-constructed items using a braced init list." << std::endl;
    std::cout << "Starting a list with 2 kinds of bread." << std::endl;
    assignedList.clear();
    assignedList.push_back(slicedBread);
    assignedList.push_back(baguette);
    PrintList(assignedList);
    std::cout << "Operator assigning here." << std::endl;
    assignedList = { slicedBread, peanutButter, jelly };
    std::cout << "A copy constructor is needed for each item to construct the braced init list." << std::endl;
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Operator Assigning to a list with a braced init list, but newly constructing each object within the"
        " braces." << std::endl;
    std::cout << "Starting a list with 2 kinds of bread." << std::endl;
    assignedList.clear();
    assignedList.push_back(slicedBread);
    assignedList.push_back(baguette);
    PrintList(assignedList);
    std::cout << "Operator assigning here." << std::endl;
    assignedList = { GroceryItem("Sliced Bread", 1), GroceryItem("Peanut Butter", 1), GroceryItem("Jelly", 1) };
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assigning over a 2-element list with 1 new element." << std::endl;
    assignedList.assign(1, pickleItem);
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assiging over a 1-element list with 1 new element with the same member variable values (but different"
        " address)." << std::endl;
    assignedList.assign(1, pickleItem);
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assigning over a 1-element list with 1 new element. These elements are identical, sharing an address."
        << std::endl;
    GroceryItem& existingItem = assignedList.front();
    assignedList.assign(1, existingItem);
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assigning over a 1-element list with 2 new elements." << std::endl;
    assignedList.assign(2, pumpkinItem);
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Proving that each element has its own address, even though they're all copied from the same item."
        << std::endl;
    GroceryItem tomatoItem("Tomato", 9);
    GroceryItem& tomatoRef = tomatoItem;
    assignedList.assign(5, tomatoRef);
    PrintList(assignedList);
    std::cout << "Each item should have a different address:" << std::endl;
    for (GroceryItem& item : assignedList)
    {
        std::cout << &item << std::endl;
    }

    PrintDivider();
    std::cout << "Assigning using iterators." << std::endl;
    assignedList.assign(lotsOfPickles.begin(), lotsOfPickles.end());
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Assigning using pre-constructed items using a braced init list." << std::endl;
    assignedList.assign({ appleItem, pumpkinItem, tofuItem });
    PrintList(assignedList);

    PrintDivider();
    std::cout << "Reducing list to 1 item." << std::endl;
    assignedList.resize(1);
    PrintList(assignedList);
    std::cout << "Assigning using a braced init list, but newly constructing each object within the braces."
        << std::endl;
    assignedList.assign({ GroceryItem("Salt", 1), GroceryItem("Pepper", 1) });
    PrintList(assignedList);

    return 0;
}
