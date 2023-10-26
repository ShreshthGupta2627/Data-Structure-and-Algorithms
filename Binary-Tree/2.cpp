// Pre Order Traversal of Binar Tree
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

void preOrder(Node *CurrNode)
{
    if (CurrNode == NULL)
    {
        return;
    }
    cout << CurrNode->data << " ";
    preOrder(CurrNode->left);
    preOrder(CurrNode->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    cout << "Pre Order Traversal of Binary Tree is : ";
    preOrder(root);
    // Tc = Sc =O(n)
    return 0;
}