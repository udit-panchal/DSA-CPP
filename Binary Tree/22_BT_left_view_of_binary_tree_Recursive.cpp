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

    vector<int> solve(node *root, vector<int> &result, int level)
    {

        if (root == NULL)
            return result;

        if (level == result.size())
            result.push_back(root->data);

        if (root->left)
            solve(root->left, result, level + 1);

        if (root->right)
            solve(root->right, result, level + 1);

        return result;
    }

    vector<int> leftview(node *root)
    {
        vector<int> ans;
        solve(root, ans, 0);
        return ans;
    }
};

int main()
{
    binaryTree bt;

    bt.root = new node(1);
    bt.root->left = new node(2);
    bt.root->right = new node(3);
    bt.root->left->left = new node(4);
    bt.root->left->right = new node(5);

    //                 1
    //               /   \ 
    //              2     3
    //             / \       
    //            4   5

    vector<int> result = bt.leftview(bt.root);

    for (auto num : result)
        cout << num << " ";

    return 0;
}

/* Source : ChatGPT



*/