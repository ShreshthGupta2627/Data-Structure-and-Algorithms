// Zigzag traversalof binary tree
/*Given the root of a binary tree, return the zigzag level order traversal of Binary Tree. (i.e., from left to right, then right to left for the next level and alternate between)*/

// Checking if two given tree are identical or not
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

void Zigzag(Node *root)
{
    if (root == NULL)
    {
        return;
    }

    vector<vector<int>> ans;
    bool f = 0;

    queue<Node *> q;
    q.push(root);
    while (!q.empty())
    {
        int sz = q.size();

        vector<int> temp;
        temp.clear();

        for (int i = 0; i < sz; i++)
        {
            auto curr = q.front();
            q.pop();
            temp.push_back(curr->data);

            if (curr->left)
            {
                q.push(curr->left);
            }

            if (curr->right)
            {
                q.push(curr->right);
            }
        }
        if (f)
        {
            reverse(temp.begin(), temp.end());
        }
        ans.push_back(temp);
        f = !f;
    }

    for (auto &it : ans)
    {
        for (auto &i : it)
        {
            cout << i << " ";
        }
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);

    Zigzag(root);
    return 0;
}