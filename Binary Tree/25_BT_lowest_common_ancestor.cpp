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
        this->left = nullptr;
        this->right = nullptr;
    }
};

class binaryTree
{
public:
    node *root;

    binaryTree()
    {
        this->root = nullptr;
    }

    node *lowestCommonAncestor(node *root, int n1, int n2)
    {
        if (root == NULL)
            return NULL;

        if (root->data == n1 || root->data == n2)
            return root;

        node *left = lowestCommonAncestor(root->left, n1, n2);
        node *right = lowestCommonAncestor(root->right, n1, n2);

        if (left != NULL && right != NULL)
            return root;

        else if (left != NULL && right == NULL)
            return left;

        else if (left == NULL && right != NULL)
            return right;

        else
            return NULL;
    }
};

int main()
{
    binaryTree bt;

    bt.root = new node(4);
    bt.root->left = new node(2);
    bt.root->left->left = new node(7);
    bt.root->left->right = new node(1);
    bt.root->left->right->left = new node(6);
    // bt.root->left->right->right = new node(9);

    bt.root->right = new node(5);
    bt.root->right->left = new node(11);
    bt.root->right->right = new node(3);

    //            4
    //          /   \ 
    //         2     5
    //        / \   / \ 
    //       7   1 11   3
    //          /
    //         6

    node *result = bt.lowestCommonAncestor(bt.root, 7, 3);
    cout << "Solution : " << result->data << endl;
    return 0;
}
