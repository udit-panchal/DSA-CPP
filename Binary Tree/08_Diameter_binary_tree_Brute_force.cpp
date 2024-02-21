#include <bits/stdc++.h>
using namespace std;

class Node
{

public:
    int data;
    Node *left;
    Node *right;

    Node(int data)
    {
        this->data = data;
        right = left = nullptr;
    }
};

class BinaryTree
{
public:
    Node *root;

    BinaryTree()
    {
        root = nullptr;
    }

    int height(Node *curr)
    {
        if (curr == NULL)
            return 0;

        int left = height(curr->left);
        int right = height(curr->right);

        return max(left, right) + 1;
    }

    int diameter(Node *curr)
    {
        if (curr == NULL)
        {
            return 0;
        }

        int left = diameter(curr->left);
        int right = diameter(curr->right);
        int leftandRight = height(curr->left) + height(curr->right);

        int ans = max(leftandRight, max(left, right));
        return ans;
    }
};

int main()
{

    BinaryTree bt;

    bt.root = new Node(1);

    bt.root->left = new Node(2);
    bt.root->right = new Node(3);

    bt.root->left->left = new Node(4);
    bt.root->left->left->left = new Node(23);
    bt.root->left->right = new Node(5);
    bt.root->left->right->right = new Node(45);
    bt.root->left->right->right->right = new Node(78);
    bt.root->left->right->right->right->right = new Node(67);
    bt.root->right->left = new Node(6);
    bt.root->right->right = new Node(7);

    ///////////////////////////////////  
    //                               //
    //                               //
    //               1               //
    //             /   \             //
    //           2       3           //
    //          / \     / \          //
    //         4   5   6   7         //
    //        /     \                //
    //       23      45              //
    //                \              //
    //                 78            //
    //                  \            //
    //                   67          //
    //                               //
    //                               //
    ///////////////////////////////////

    cout << "Diameter of Tree is : " << bt.diameter(bt.root) << endl;

    return 0;
}