// Iterative Preorder Traversal
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

void IterativePreOrder(Node *CurrNode)
{
    stack<Node *> st;
    vector<int> preorder;
    // Put the node in stack
    // Now each time take a node out of stack print it
    // Now we need to go left then right child
    // Stack is lifo :. we have to push left after right child so left traversal completes first
    // Push node if right exist push right if left exist push left

    st.push(CurrNode);

    while (!st.empty())
    {
        auto node = st.top();
        st.pop();

        preorder.push_back(node->data);
        if (node->right)
        {
            st.push(node->right);
        }
        if (node->left)
        {
            st.push(node->left);
        }
    }

    for (auto &it : preorder)
    {
        cout << it << " ";
    }
}
int main()
{
    Node *root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    IterativePreOrder(root);
    // Tc = Sc =O(n)
    return 0;
}