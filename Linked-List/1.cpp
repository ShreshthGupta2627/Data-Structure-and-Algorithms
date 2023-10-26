// Reversing a linked list
#include <bits/stdc++.h>
using namespace std;
class Node
{
public:
    int data;
    Node *nxt;

    Node()
    {
        this->nxt = NULL;
    }
} *head = NULL;
// Deleting a node of only pointer to it is given and pointer to head is denied the we can proccede as : node->data=node->nxt->data          node->nxt=node->nxt->nxt
Node *create_ll(vector<int> &v)
{
    Node *t, *p;
    head = new Node;
    head->data = v[0];
    // head->nxt = NULL;
    p = new Node;
    p = head;
    for (int i = 1; i < v.size(); i++)
    {
        t = new Node;
        t->data = v[i];
        // t->nxt = NULL;
        p->nxt = t;
        p = p->nxt;
    }
    return head;
}
void display_ll(Node *p)
{
    while (p != NULL)
    {
        cout << p->data << " ";
        p = p->nxt;
    }
    cout << endl;
}
Node *reverse_ll(Node *head)
{
    Node *p, *q, *r;
    p = head;
    q = NULL;
    r = NULL;
    while (p != NULL)
    {
        r = q;
        q = p;
        p = p->nxt;
        q->nxt = r;
    }
    head = q;
    return head;
}
int main()
{
    vector<int> v = {1, 3, 2, 4};
    Node *ans = create_ll(v);
    display_ll(ans);
    Node *rev = reverse_ll(ans);
    display_ll(rev);
    return 0;
}