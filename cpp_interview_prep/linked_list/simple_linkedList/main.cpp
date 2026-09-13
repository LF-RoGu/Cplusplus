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
    Node* newNode = new Node();
    Node* secondNode = new Node();
    Node* thirdNode = new Node();

    // Initialize first node
    //(*newNode).value = 10;
    newNode->value = 10;
    newNode->next = nullptr;

    // Now the head aims to the new node
    head = newNode;

    secondNode->value = 20;
    secondNode->next = nullptr;
    // Connect the head to the second Node
    head->next = secondNode;

    thirdNode->value = 30;
    thirdNode->next = nullptr;
    secondNode->next = thirdNode;

    Node* current = head;

    while (current != nullptr)
    {
        std::cout << current->value << '\n';
        current = current->next;
    }

    return 0;
}
