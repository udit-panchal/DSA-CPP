
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

    pair<int, int> solution(node *root)
    {
        if (root == NULL)
            return make_pair(0, 0);

        pair<int, int> left = solution(root->left);
        pair<int, int> right = solution(root->right);

        pair<int, int> result;

        result.first = root->data + left.second + right.second;
        result.second = max(left.first, left.second) + max(right.first, right.second);

        return result;
    }

    int getMax(node *root)
    {
        pair<int, int> ans = solution(root);
        return max(ans.first, ans.second);
    }
};

int main()
{
    binaryTree bt;

    bt.root = new node(1);

    bt.root->left = new node(2);
    bt.root->left->left = new node(1);
    // bt.root->left->right = new node(2);

    bt.root->right = new node(3);
    bt.root->right->left = new node(4);
    bt.root->right->right = new node(5);

    //                  1
    //                /   \ 
    //              2       3
    //             /       / \ 
    //            1       4   5

    int result = bt.getMax(bt.root);

    cout << "Max : " << result << endl;

    return 0;
}
