// Iterative Inorder Traversal
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

void IterativeInOrder(Node *CurrNode)
{
    stack<Node *> st;
    vector<int> inorder;

    Node *curr = CurrNode;
    while (1)
    {
        if (curr != NULL)
        {
            st.push(curr);
            curr = curr->left;
        }
        else
        {
            if (st.empty())
                break;
            curr = st.top();
            st.pop();
            inorder.push_back(curr->data);
            curr = curr->right;
        }
    }

    for (auto &it : inorder)
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
    IterativeInOrder(root);
    // Tc = Sc =O(n)
    return 0;
}