// Print root to node path
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left, *right;

    Node()
    {
        this->left = NULL;
        this->right = NULL;
    }

    Node(int x)
    {
        this->data = x;
        this->left = NULL;
        this->right = NULL;
    }
};

bool dfs(Node *root, int key, vector<int> &path)
{
    if (root == NULL)
    {
        return 0;
    }

    if (root->data == key)
    {
        return 1;
    }

    if (root->left != NULL)
    {
        path.push_back(root->left->data);
        if (dfs(root->left, key, path))
        {
            return 1;
        }
        path.pop_back();
    }

    if (root->right != NULL)
    {
        path.push_back(root->right->data);
        if (dfs(root->right, key, path))
        {
            return 1;
        }
        path.pop_back();
    }
    return 0;
}

int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->right->right = new Node(5);

    vector<int> path;
    path.push_back(root->data);
    dfs(root, 4, path);

    for (auto &it : path)
    {
        cout << it << " ";
    }
    return 0;
}