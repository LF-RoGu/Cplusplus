#include <iostream>

struct Node
{
    // Value
    int value;
    // Address of the next Node
    Node* next;
};

void insertBack(Node*& head, int value);
bool contains(Node* head, int value);
bool removeValue(Node*& head, int value);
void reverseList(Node*& head);
void printList(Node* head);
void deleteList(Node*& head);

int main()
{
    Node* head = nullptr;

    insertBack(head, 10);
    insertBack(head, 20);
    insertBack(head, 30);
    insertBack(head, 40);

    printList(head);

    std::cout << "Contains 30: "
              << contains(head, 30)
              << '\n';

    std::cout << "Contains 50: "
              << contains(head, 99)
              << '\n';

    printList(head);

    removeValue(head, 30);
    printList(head);

    removeValue(head, 10);
    printList(head);

    std::cout << "Before reverse:\n";
    printList(head);

    reverseList(head);

    std::cout << "After reverse:\n";
    printList(head);

    deleteList(head);
    std::cout << "After delete:\n";
    printList(head);

    return 0;
}

void insertBack(Node*& head, int value){
    Node* newNode = new Node();

    newNode->value = value;
    newNode->next = nullptr;

    // Case 1: empty list
    if (head == nullptr)
    {
        head = newNode;
        return;
    }

    // Case 2: list already contains nodes
    Node* current = head;

    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

void printList(Node* head)
{
    Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->value;

        if (current->next != nullptr)
        {
            std::cout << " -> ";
        }

        current = current->next;
    }

    std::cout << '\n';
}

bool contains(Node* head, int value)
{
    Node* current = head;

    while (current != nullptr)
    {
        if (current->value == value)
        {
            return true;
        }

        current = current->next;
    }

    return false;
}

bool removeValue(Node*& head, int value)
{
    if (head == nullptr)
    {
        return false;
    }

    // Case 1: remove the head node
    if (head->value == value)
    {
        Node* nodeToDelete = head;

        head = head->next;

        delete nodeToDelete;

        return true;
    }

    // Case 2: search after the head
    Node* current = head;

    while (current->next != nullptr)
    {
        if (current->next->value == value)
        {
            Node* nodeToDelete = current->next;
            // Connect current Node to the next available.
            current->next = current->next->next;

            delete nodeToDelete;

            return true;
        }

        current = current->next;
    }

    return false;
}

void reverseList(Node*& head)
{
    Node* previous = nullptr;
    Node* current = head;
    Node* next = nullptr;

    while (current != nullptr)
    {
        next = current->next;

        current->next = previous;

        previous = current;

        current = next;
    }

    head = previous;
}

void deleteList(Node*& head)
{
    Node* current = head;

    while (current != nullptr)
    {
        Node* next = current->next;

        delete current;

        current = next;
    }

    head = nullptr;
}