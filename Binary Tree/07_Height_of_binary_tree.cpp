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
        left = right = nullptr;
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

    int bt_Height(Node *root)
    {
        // check if the current node is empty, if empty return 0;
        if (root == nullptr)
            return 0;

        // Recursive call to calculate the height of the left & right subtree
        int left = bt_Height(root->left);
        int right = bt_Height(root->right);

        // return the max height of the left and right subtree and plus 1 for curr root.
        
        return max(left, right) + 1;
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

    cout << " Height of this tree is : " << bt.bt_Height(bt.root);

    return 0;
}