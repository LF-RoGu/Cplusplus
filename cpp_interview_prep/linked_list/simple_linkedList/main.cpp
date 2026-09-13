#include <iostream>

struct Node
{
    // Value
    int value;
    // Address of the next Node
    Node* next;
};

void insertFront(Node*& head, int value);
void insertBack(Node*& head, int value);
bool insertAtPosition(Node*& head, int value, int position);
bool contains(Node* head, int value);
bool removeValue(Node*& head, int value);
void reverseList(Node*& head);
void printList(Node* head);
void deleteList(Node*& head);

int main()
{
    Node* head = nullptr;

    insertBack(head, 10);
    printList(head);
    insertBack(head, 20);
    printList(head);
    insertBack(head, 30);
    printList(head);

    insertFront(head, 5);
    printList(head);

    insertAtPosition(head, 15, 1);
    printList(head);

    return 0;
}

void insertFront(Node*& head, int value)
{
    Node* newNode = new Node();

    newNode->value = value;
    newNode->next = head;

    head = newNode;
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

bool insertAtPosition(Node*& head, int value, int position)
{
    if (position < 0)
    {
        return false;
    }

    if (position == 0)
    {
        insertFront(head, value);
        return true;
    }

    Node* current = head;

    for (int i = 0; i < position - 1; i++)
    {
        if (current == nullptr)
        {
            return false;
        }

        current = current->next;
    }

    if (current == nullptr)
    {
        return false;
    }

    Node* newNode = new Node();
    newNode->value = value;

    newNode->next = current->next;
    current->next = newNode;

    return true;
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