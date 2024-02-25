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

    vector<int> bottomView(node *root)
    {
        vector<int> result;
        if (root == nullptr)
        {
            return result;
        }

        map<int, int> mapping;
        queue<pair<node *, int>> q;

        q.push({root, 0});

        while (!q.empty())
        {
            pair<node *, int> temp = q.front();
            q.pop();

            node *frontNode = temp.first;
            int horiz_dist = temp.second;

            mapping[horiz_dist] = frontNode->data;

            if (frontNode->left)
                q.push({frontNode->left, horiz_dist - 1});

            if (frontNode->right)
                q.push({frontNode->right, horiz_dist + 1});
        }

        for (auto i : mapping)
            result.push_back(i.second);

        return result;
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

    vector<int> result = bt.bottomView(bt.root);

    for (auto num : result)
        cout << num << " ";

    return 0;
}

/* Source : ChatGPT



*/