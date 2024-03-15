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

    void solve(node *root, int k, int &count, vector<int> &path)
    {
        if (root == NULL)
            return;

        path.push_back(root->data);

        solve(root->left, k, count, path);
        solve(root->right, k, count, path);

        int sum = 0;
        for (int i = path.size() - 1; i >= 0; i--)
        {
            sum += path[i];
            if (sum == k)
                count++;
        }

        path.pop_back();
    }

    int k_sum_path(node *root, int k)
    {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
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


    int result = bt.k_sum_path(bt.root, 10);
    cout << "Solution : " << result << endl;
    return 0;
}
