// Calculate the Diameter of a Binary Tree
/*Find the Diameter of a Binary Tree. Diameter is the length of the longest path between any 2 nodes in the tree and this path may or may not pass from the root.*/

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
int diameter(Node *node, int &dia)
{
    if (node == NULL)
    {
        return 0;
    }

    int leftHeight = diameter(node->left, dia);
    int rightHeight = diameter(node->right, dia);
    dia = max(dia, leftHeight + rightHeight);
    // Add 1 i.e root of subtree
    return 1 + max(leftHeight, rightHeight);

    // TC : O(n)
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->left->left = new Node(8);

    int dia = 0;
    diameter(root, dia);
    cout << dia << endl;
    return 0;
}