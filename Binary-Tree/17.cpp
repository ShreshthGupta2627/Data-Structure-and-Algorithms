// Vertical order traversal
// Boundary Traversal of a Binary Tree
/* Write a program for the Anti-Clockwise Boundary traversal of a binary tree.*/

#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    Node *left, *right;
    int data;

    Node(int val)
    {
        left = right = NULL;
        data = val;
    }
};

void VerticalOrder(Node *root)
{
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;

    queue<tuple<Node *, int, int>> q;
    q.push({root, 0, 0});

    while (!q.empty())
    {
        auto [node, vertcal, lvl] = q.front();
        q.pop();

        nodes[vertcal][lvl].insert(node->data);

        if (node->left)
        {
            q.push({node->left, vertcal - 1, lvl + 1});
        }
        if (node->right)
        {
            q.push({node->right, vertcal + 1, lvl + 1});
        }
    }

    for (auto &it : nodes)
    {
        vector<int> col;
        for (auto &i : it.second)
        {
            col.insert(col.end(), i.second.begin(), i.second.end());
        }
        ans.push_back(col);
    }

    for (auto &it : ans)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
        cout << endl;
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->left->left = new Node(4);
    root->left->right = new Node(10);
    root->left->left->right = new Node(5);
    root->left->left->right->right = new Node(6);
    root->right = new Node(3);
    root->right->left = new Node(9);
    root->right->right = new Node(10);

    VerticalOrder(root);
    return 0;
}