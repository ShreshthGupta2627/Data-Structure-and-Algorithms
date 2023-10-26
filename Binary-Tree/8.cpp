// Iterative inorder unsing two stack and 1 stackd

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
void postOrder2Stack(Node *node)
{
    stack<Node *> stk1, stk2;
    if (node == NULL)
    {
        return;
    }

    stk1.push(node);
    while (!stk1.empty())
    {
        auto it = stk1.top();
        stk1.pop();

        if (it->left != NULL)
        {
            stk1.push(it->left);
        }
        if (it->right != NULL)
        {
            stk1.push(it->right);
        }

        stk2.push(it);
    }

    while (!stk2.empty())
    {
        cout << stk2.top()->data << " ";
        stk2.pop();
    }
}

void postOrder1Stack(Node *node)
{
    stack<Node *> stk;
    vector<int> PostOrder;

    if (node == NULL)
    {
        return;
    }

    while (node != NULL || !stk.empty())
    {
        if (node != NULL)
        {
            stk.push(node);
            node = node->left;
        }
        else
        {
            Node *temp = stk.top()->right;
            if (temp == NULL)
            {
                temp = stk.top();
                stk.pop();
                PostOrder.push_back(temp->data);

                while (!stk.empty() && stk.top()->right == temp)
                {
                    temp = stk.top();
                    stk.pop();
                    PostOrder.push_back(temp->data);
                }
            }
            else
            {
                node = temp;
            }
        }
    }

    for (auto &it : PostOrder)
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
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->left->left = new Node(7);
    root->right->left->left->left = new Node(8);

    postOrder2Stack(root);
    postOrder1Stack(root);
    return 0;
}