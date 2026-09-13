#include <iostream>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
struct Node {
    int value;
    Node* left;
    Node* right;
};

void insert(Node*& root, int value);

int main()
{
    Node* root = nullptr;

    Node* firstNode = new Node();
    firstNode->value = 10;
    firstNode->left = nullptr;
    firstNode->right = nullptr;
    root = firstNode;

    Node* secondNode = new Node();
    secondNode->value = 5;
    secondNode->left = nullptr;
    secondNode->right = nullptr;
    root->left = secondNode;

    Node* fourthNode = new Node();
    fourthNode->value = 7;
    fourthNode->left = nullptr;
    fourthNode->right = nullptr;
    root->left->right = fourthNode;

    Node* fifthNode = new Node();
    fifthNode->value = 5;
    fifthNode->left = nullptr;
    fifthNode->right = nullptr;
    root->left->left = fifthNode;

    Node* thirdNode = new Node();
    thirdNode->value = 20;
    thirdNode->left = nullptr;
    thirdNode->right = nullptr;
    root->right = thirdNode;

    return 0;
}

void insert(Node*& root, int value)
{
    Node* newNode = new Node();

    newNode->value = value;
    newNode->left = nullptr;
    newNode->right = nullptr;

    // Empty tree
    if (root == nullptr)
    {
        root = newNode;
        return;
    }

    Node* current = root;

    while (true)
    {
        if (value < current->value)
        {
            // Empty position found on the left
            if (current->left == nullptr)
            {
                current->left = newNode;
                return;
            }

            current = current->left;
        }
        else if (value > current->value)
        {
            // Empty position found on the right
            if (current->right == nullptr)
            {
                current->right = newNode;
                return;
            }

            current = current->right;
        }
        else
        {
            // Duplicate value
            delete newNode;
            return;
        }
    }
}