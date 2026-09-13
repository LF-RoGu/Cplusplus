#include <filesystem>
#include <iostream>
#include <bits/locale_facets_nonio.h>

// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
struct Node {
    int value;
    Node* left;
    Node* right;
};

void insert(Node*& root, int value);

void printInOrder(Node* root);
void printTree(Node* root, int space = 0);

int main()
{
    Node* root = nullptr;

    insert(root, 10);
    std::cout << "\nAfter inserting 10:\n";
    printTree(root);

    insert(root, 5);
    std::cout << "\nAfter inserting 5:\n";
    printTree(root);

    insert(root, 20);
    std::cout << "\nAfter inserting 20:\n";
    printTree(root);

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

void printInOrder(Node* root)
{
    if (root == nullptr)
    {
        return;
    }

    printInOrder(root->left);

    std::cout << root->value << " ";

    printInOrder(root->right);
}

void printTree(Node* root, int space)
{
    if (root == nullptr)
    {
        return;
    }

    const int DISTANCE = 5;
    space += DISTANCE;

    printTree(root->right, space);

    std::cout << '\n';

    for (int i = DISTANCE; i < space; i++)
    {
        std::cout << ' ';
    }

    std::cout << root->value << '\n';

    printTree(root->left, space);
}