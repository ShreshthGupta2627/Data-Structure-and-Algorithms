// In Order Traversal of bt
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

void InOrder(Node *CurrNode)
{
    if (CurrNode == NULL)
    {
        return;
    }
    InOrder(CurrNode->left);
    cout << CurrNode->data << " ";
    InOrder(CurrNode->right);
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    InOrder(root);
    // Tc = Sc =O(n)
    return 0;
}