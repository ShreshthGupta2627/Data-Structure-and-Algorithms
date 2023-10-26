// Right and left view of binary tree
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

void rvHelper(Node *node, int lvl, vector<int> &view)
{
    if (node == NULL)
    {
        return;
    }

    if (view.size() == lvl)
    {
        view.push_back(node->data);
    }

    if (node->right != NULL)
        rvHelper(node->right, lvl + 1, view);

    if (node->left != NULL)
        rvHelper(node->left, lvl + 1, view);
}
void rightView(Node *root)
{
    vector<int> view;
    rvHelper(root, 0, view);
    for (auto &it : view)
    {
        cout << it << " ";
    }
    return;
}

void lvHelper(Node *node, int lvl, vector<int> &view)
{
    if (node == NULL)
    {
        return;
    }

    if (view.size() == lvl)
    {
        view.push_back(node->data);
    }
    if (node->left != NULL)
        lvHelper(node->left, lvl + 1, view);

    if (node->right != NULL)
        lvHelper(node->right, lvl + 1, view);
}
void leftView(Node *root)
{
    vector<int> view;
    lvHelper(root, 0, view);
    for (auto &it : view)
    {
        cout << it << " ";
    }
    return;
}

int main()
{
    Node *root;
    root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    rightView(root);
    cout << endl;
    leftView(root);
    return 0;
}