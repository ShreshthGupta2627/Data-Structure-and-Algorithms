// Flatering a linked list
/*Given a Linked List of size N, where every node represents a sub-linked-list and contains two pointers:
(i) a nxt pointer to the nxt node,
(ii) a bottom pointer to a linked list where this node is head.
Each of the sub-linked-list is in sorted order.
Flatten the Link List such that all the nodes appear in a single level while maintaining the sorted order.
Note: The flattened list will be printed using the bottom pointer instead of the nxt pointer.*/
#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *nxt;
    struct node *bottom;

    node(int x)
    {
        data = x;
        nxt = NULL;
        bottom = NULL;
    }
};
void printList(node *node)
{
    while (node != NULL)
    {
        cout << node->data << " ";
        node = node->bottom;
    }
    cout << endl;
}
node *merge2list(node *a, node *b)
{
    node *temp = new node(0);
    node *res = temp;
    while (a != NULL && b != NULL)
    {
        if (a->data < b->data)
        {
            temp->bottom = a;
            temp = temp->bottom;
            a = a->bottom;
        }
        else
        {
            temp->bottom = b;
            temp = temp->bottom;
            b = b->bottom;
        }
    }
    if (a)
        temp->bottom = a;
    else
        temp->bottom = b;
    return res->bottom;
}
node *flatten(node *root)
{
    if (root == NULL || root->nxt == NULL)
        return root;
    root->nxt = flatten(root->nxt);
    root = merge2list(root, root->nxt);
    return root;
}
int main(void)
{

    int t;
    cin >> t;
    while (t--)
    {
        int n, m, flag = 1, flag1 = 1;
        struct node *temp = NULL;
        struct node *head = NULL;
        struct node *pre = NULL;
        struct node *tempB = NULL;
        struct node *preB = NULL;
        cin >> n;
        int work[n];
        for (int i = 0; i < n; i++)
            cin >> work[i];
        for (int i = 0; i < n; i++)
        {
            m = work[i];
            --m;
            int data;
            scanf("%d", &data);
            temp = new node(data);
            temp->nxt = NULL;
            temp->bottom = NULL;

            if (flag)
            {
                head = temp;
                pre = temp;
                flag = 0;
                flag1 = 1;
            }
            else
            {
                pre->nxt = temp;
                pre = temp;
                flag1 = 1;
            }
            for (int j = 0; j < m; j++)
            {

                int temp_data;
                cin >> temp_data;
                tempB = new node(temp_data);

                if (flag1)
                {
                    temp->bottom = tempB;
                    preB = tempB;
                    flag1 = 0;
                }
                else
                {
                    preB->bottom = tempB;
                    preB = tempB;
                }
            }
        }
        node *fun = head;
        node *fun2 = head;
        node *root = flatten(head);
        printList(root);
    }
    return 0;
}
/* node structure  used in the program
struct node{
    int data;
    struct node * nxt;
    struct node * bottom;

    node(int x){
        data = x;
        nxt = NULL;
        bottom = NULL;
    }

};
*/