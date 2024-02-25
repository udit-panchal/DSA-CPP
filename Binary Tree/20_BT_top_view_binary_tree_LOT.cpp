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

    vector<int> topView(node *root)
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

            if (mapping.find(horiz_dist) == mapping.end())
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
    bt.root->left->left->left = new node(8);
    bt.root->left->right = new node(5);
    bt.root->left->right->right = new node(9);
    bt.root->right->left = new node(6);
    bt.root->right->right = new node(7);
    bt.root->right->right->right = new node(10);
    bt.root->right->right->right->right = new node(11);

    //                   1
    //                 /   \ 
    //                /     \ 
    //               /       \ 
    //              2         3
    //             / \       / \ 
    //            4   5     6   7
    //           /     \         \ 
    //          8       9        10
    //                             \ 
    //                             11


    vector<int> result = bt.topView(bt.root);

    for (auto num : result)
        cout << num << " ";

    return 0;
}

/* Source : ChatGPT


    The topView function identifies the top view of a binary tree, capturing the nodes visible from the top. It initializes an empty result vector and conducts a level-order traversal using a queue and a map. 

    At each step, it records each node's horizontal distance from the root. If a new horizontal distance is encountered, indicating a unique view from the top, the node's data is stored in the map. 

    After traversal, the mapped data is consolidated into the result vector, ensuring nodes are ordered by horizontal distance. 

    Finally, the function returns this vector, representing the top view nodes of the tree. Through this systematic approach, topView provides insight into the tree's visibility from a top-down perspective.

*/