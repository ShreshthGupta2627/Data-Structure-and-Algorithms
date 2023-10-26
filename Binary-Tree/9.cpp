// pre - post - in order traversal in 1 traversal
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

void Traversals(Node *node)
{
    vector<int> PreOrder, PostOrder, InOrder;
    if (node == NULL)
    {
        return;
    }

    stack<pair<Node *, int>> st;
    st.push({node, 1});

    while (!st.empty())
    {
        auto it = st.top();
        st.pop();

        Node *curr = it.first;
        int lvl = it.second;

        if (lvl == 1)
        {
            PreOrder.push_back(curr->data);
            lvl++;
            // Pushing same for other traversal
            st.push({curr, lvl});

            if (curr->left != NULL)
            {
                // Pushing new character 1st time
                st.push({curr->left, 1});
            }
        }
        else if (lvl == 2)
        {
            InOrder.push_back({curr->data});
            lvl++;
            st.push({curr, lvl});

            if (curr->right != NULL)
            {
                // Pushing new character 1st time
                st.push({curr->right, 1});
            }
        }
        else
        {
            PostOrder.push_back(curr->data);
        }
    }
    cout << "PreOrder : ";
    for (auto &it : PreOrder)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "InOrder : ";
    for (auto &it : InOrder)
    {
        cout << it << " ";
    }
    cout << endl;

    cout << "PostOrder : ";
    for (auto &it : PostOrder)
    {
        cout << it << " ";
    }
    cout << endl;
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

    Traversals(root);
    return 0;
}