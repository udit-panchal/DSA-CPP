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

    pair<bool, int> isSumTree(node *root)
    {
        if (root == NULL)
            return make_pair(true, 0);

        if (root->left == NULL && root->right == NULL)
            return make_pair(true, root->data);

        pair<bool, int> leftAns = isSumTree(root->left);
        pair<bool, int> rightAns = isSumTree(root->right);

        bool left = leftAns.first;
        bool right = rightAns.first;

        bool condition = root->data == leftAns.second + rightAns.second;

        pair<bool, int> ans;

        if (left && right && condition)
        {
            ans.first = true;
            ans.second = 2 * root->data;
        }
        else
        {
            ans.first = false;
        }

        return ans;
    }

    bool isSum(node *root)
    {
        return isSumTree(root).first;
    }
};

int main()
{
    binaryTree bt;

    // Test Case: Tree where sum property is violated

//           10
//          /  \ 
//         5    5
//        / \ 
//       3   2

    // bt.root = new node(3);
    // bt.root->left = new node(2);
    // bt.root->right = new node(1);
    // bt.root->left->left = new node(3);
    // bt.root->left->right = new node(2);

    // cout << "Test Case 1: is sum tree? : " << bt.isSum(bt.root) << endl;

//           10
//          /  \ 
//         5    5
//        / \  / \ 
//       2   3 4  1

    // bt.root = new node(10);

    // bt.root->left = new node(5);
    // bt.root->left->left = new node(2);
    // bt.root->left->right = new node(3);

    // bt.root->right = new node(5);
    // bt.root->right->left = new node(4);
    // bt.root->right->right = new node(1);

    // cout << "Test Case 2: is sum tree? " << bt.isSum(bt.root) << endl;

    return 0;
}