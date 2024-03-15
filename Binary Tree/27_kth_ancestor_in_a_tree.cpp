
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
node *kth_ancestor(node *root, int &k, int n)
{
    if (root == NULL)
        return NULL;

    if (root->data == n || k == 0)
        return root;

    node *left = kth_ancestor(root->left, k, n);
    if (left != NULL)
    {
        if (k != INT_MAX)
        {
            k--;
            if (k == 0)
                return root;
        }
        return left;
    }

    node *right = kth_ancestor(root->right, k, n);
    if (right != NULL)
    {
        if (k != INT_MAX)
        {
            k--;
            if (k == 0)
                return root;
        }
        return right;
    }

    return NULL;
}

};

int main()
{
    binaryTree bt;

    bt.root = new node(1);

    bt.root->left = new node(5);
    bt.root->left->left = new node(4);
    bt.root->left->right = new node(2);

    bt.root->right = new node(3);
    bt.root->right->left = new node(6);
    bt.root->right->right = new node(7);

    //                  1
    //                /   \ 
    //              2       3
    //             / \     / \ 
    //            4   5   6   7
    int k = 2;
 
    node *result = bt.kth_ancestor(bt.root, k, 7);

    if (result && k != INT_MAX)
        cout << "Solution : " << result->data << endl;
    else
        cout << "No solution found" << endl;

    return 0;
}
