#include <iostream>
#include <fstream>
using namespace std;

class SinglyLinkedListNode {
public:
    int data;
    SinglyLinkedListNode* next;

    SinglyLinkedListNode(int node_data) {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList {
public:
    SinglyLinkedListNode* head;
    SinglyLinkedListNode* tail;

    SinglyLinkedList() {
        this->head = nullptr;
        this->tail = nullptr;
    }

    void insert_node(int node_data) {
        SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

        if (!this->head) {
            this->head = node;
        }
        else {
            this->tail->next = node;
        }

        this->tail = node;
    }
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
    while (node) {
        fout << node->data;

        node = node->next;

        if (node) {
            fout << sep;
        }
    }
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
    while (node) {
        SinglyLinkedListNode* temp = node;
        node = node->next;

        free(temp);
    }
}

// Complete the mergeLists function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */
void addNode(SinglyLinkedListNode*& resultHead, SinglyLinkedListNode*& resultTail, SinglyLinkedListNode* nodeToAdd)
{
    std::cout << "Adding " << nodeToAdd->data << std::endl;
    if (resultHead == nullptr)
    {
        std::cout << "Setting head and tail" << std::endl;
        resultHead = nodeToAdd;
        resultTail = nodeToAdd;
    }
    else
    {
        std::cout << "Adding to the tail" << std::endl;
        resultTail->next = nodeToAdd;
        resultTail = resultTail->next; // We did need this!
    }
}

void mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2, SinglyLinkedListNode*& resultHead, SinglyLinkedListNode*& resultTail)
{
    if (head1 == nullptr && head2 == nullptr) {
        std::cout << "In head1 == nullptr && head2 == nullptr" << std::endl;
        return;
    }
    else if (head1 == nullptr)
    {
        std::cout << "head1 == nullptr" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head2;
        head2 = head2->next;
        nodeToAdd->next = nullptr;
        addNode(resultHead, resultTail, nodeToAdd);
    }
    else if (head2 == nullptr)
    {
        std::cout << "head2 == nullptr" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head1;
        head1 = head1->next;
        nodeToAdd->next = nullptr;
        addNode(resultHead, resultTail, nodeToAdd);
    }
    else if (head1->data <= head2->data) {
        std::cout << "head1->data <= head2->data" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head1;
        head1 = head1->next;
        nodeToAdd->next = nullptr;
        addNode(resultHead, resultTail, nodeToAdd);
    }
    else // head2 < head1
    {
        std::cout << "head2 < head1" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head2;
        head2 = head2->next;
        nodeToAdd->next = nullptr;
        addNode(resultHead, resultTail, nodeToAdd);
    }
    mergeLists(head1, head2, resultHead, resultTail);
    return;
}

SinglyLinkedListNode* mergeLists(SinglyLinkedListNode* head1, SinglyLinkedListNode* head2) {
    if (!head1 && !head2) {
        std::cout << "In head1 == nullptr && head2 == nullptr" << std::endl;
        return nullptr;
    }
    else if (!head1 || (head1->data > head2->data))
    {
        std::cout << "head1 == nullptr" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head2;
        nodeToAdd->next = mergeLists(head1, head2->next);
        return nodeToAdd;
    }
    else if (!head2 || head1->data <= head2->data)
    {
        std::cout << "head2 == nullptr" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head1;
        nodeToAdd->next = mergeLists(head1->next, head2);
        return nodeToAdd;
    }
    else if (head1->data <= head2->data) {
        std::cout << "head1->data <= head2->data" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head1;
        nodeToAdd->next = mergeLists(head1->next, head2);
        return nodeToAdd;
    }
    else // head2 < head1
    {
        std::cout << "head2 < head1" << std::endl;
        SinglyLinkedListNode* nodeToAdd = head2;
        nodeToAdd->next = mergeLists(head1, head2->next);
        return nodeToAdd;
    }
}

int main()
{
    ofstream fout("output.txt");
    ifstream fin("input.txt");

    int tests;
    fin >> tests;
    fin.ignore(numeric_limits<streamsize>::max(), '\n');

    for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
        SinglyLinkedList* llist1 = new SinglyLinkedList();

        int llist1_count;
        fin >> llist1_count;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist1_count; i++) {
            int llist1_item;
            fin >> llist1_item;
            fin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist1->insert_node(llist1_item);
        }

        SinglyLinkedList* llist2 = new SinglyLinkedList();

        int llist2_count;
        fin >> llist2_count;
        fin.ignore(numeric_limits<streamsize>::max(), '\n');

        for (int i = 0; i < llist2_count; i++) {
            int llist2_item;
            fin >> llist2_item;
            fin.ignore(numeric_limits<streamsize>::max(), '\n');

            llist2->insert_node(llist2_item);
        }

        SinglyLinkedListNode* llist3 = mergeLists(llist1->head, llist2->head);

        print_singly_linked_list(llist3, " ", fout);
        fout << "\n";

        free_singly_linked_list(llist3);
    }

    fout.close();

    return 0;
}
