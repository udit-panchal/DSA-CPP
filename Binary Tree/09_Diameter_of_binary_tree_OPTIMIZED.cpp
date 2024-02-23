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

    pair<int, int> diameterOfBinaryTree(Node *curr)
    {
        // If the current node is NULL (reached leaf node), return a pair representing the diameter and height of the subtree (0, 0)
        if (curr == NULL)
        {
            pair<int, int> p = make_pair(0, 0);
            return p;
        }

        // Recursively calculate the diameter and height of the left subtree
        pair<int, int> left = diameterOfBinaryTree(curr->left);

        // Recursively calculate the diameter and height of the right subtree
        pair<int, int> right = diameterOfBinaryTree(curr->right);

        // Possible diameters:
        // - op1: Diameter of the left subtree
        // - op2: Diameter of the right subtree
        // - op3: Diameter passing through the current node (sum of heights of left and right subtrees)
        int op1 = left.first;
        int op2 = right.first;
        int op3 = left.second + right.second;

        // Update the answer:
        // - Diameter is the maximum of op1, op2, and op3
        // - Height is the maximum height of left and right subtrees plus one (to include the current node)
        pair<int, int> ans;

        ans.first = max(op1, max(op2, op3));             // Diameter
        ans.second = max(left.second, right.second) + 1; // Height
        return ans;
    }

    int diameter(Node *root)
    {
        return diameterOfBinaryTree(root).first;
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