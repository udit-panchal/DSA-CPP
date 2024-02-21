#include <bits/stdc++.h>
using namespace std;

// Representation of tree
class Node
{
public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        this->left = nullptr;
        this->right = nullptr;
    }
};

// Binary tree class for all functions and operations
class BinaryTree
{
public:
    // creating root node;
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    void insert()
    {
        root = insertNode(root);
    }

    // function for iserting element in tree
    Node *insertNode(Node *root)
    {
        cout << "Enter the data: " << endl;
        int data;
        cin >> data;

        // if Tree is empty, create initial root.
        if (root == nullptr)
        {
            // return nullptr when input is -1
            if (data == -1)
                return nullptr;

            root = new Node(data);
        }

        // when tree is not empty
        else
        {
            // return nullptr when input is -1;
            if (data == -1)
                return nullptr;

            // get data and create root for left
            cout << "Enter data for left insertion of " << data << endl;
            root->left = insertNode(root->left);

            // get data and create root for right
            cout << "Enter data for right insertion of " << data << endl;
            root->right = insertNode(root->right);
        }
        return root;
    }
};

int main()
{
    BinaryTree bt;

    bt.insert();

    //      1
    //     / \ 
    //    2   3
    //   / \ / \ 
    //  4  5 6  7
}
