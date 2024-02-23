#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int data)
    {
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        this->root = NULL;
    }

    bool is_identical(node *r1, node *r2)
    {
        if (r1 == NULL && r2 == NULL)
            return true;

        if (r1 == NULL && r2 != NULL || r1 != NULL && r2 == NULL)
            return false;

        bool left = is_identical(r1->left, r2->left);
        bool right = is_identical(r1->right, r2->right);

        bool value = r1->data == r2->data;

        return (left && right && value);
    }
};

int main()
{
    binaryTree b1;
    b1.root = new node(1);
    b1.root->left = new node(2);
    b1.root->right = new node(3);

    //               tree 1
    //                  1
    //                /   \ 
    //              2       3

    binaryTree b2;
    b2.root = new node(1);
    b2.root->left = new node(2);
    b2.root->right = new node(3);
    // b2.root->left->right = new node(4);

    //               tree 2
    //                  1
    //                /   \ 
    //              2       3

    cout << "IsIdential : " << b1.is_identical(b1.root, b2.root) << endl;

    return 0;
}