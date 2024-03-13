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

    void solve(node *root, int sum, int &maxsum, int len, int &maxlen)
    {
        if (root == NULL)
        {
            if (len > maxlen)
            {
                maxlen = len;
                maxsum = sum;
            }
            else if (len == maxlen)
            {
                maxsum = max(sum, maxsum);
            }
            return;
        }

        sum = sum + root->data;

        solve(root->left, sum, maxsum, len + 1, maxlen);
        solve(root->right, sum, maxsum, len + 1, maxlen);
    }

    int longestBoodline(node *root)
    {

        int len = 0;
        int maxLen = 0;

        int sum = 0;
        int maxSum = INT_MIN;

        solve(root, sum, maxSum, len, maxLen);

        return maxSum;
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

    bt.root->right = new node(5);
    bt.root->right->left = new node(2);
    bt.root->right->right = new node(3);

    //           5
    //          / \ 
    //         2   5
    //        / \ / \ 
    //       7  1 2  3
    //          /
    //         6

    int result = bt.longestBoodline(bt.root);
    cout << "Solution : " << result << endl;
    return 0;
}
