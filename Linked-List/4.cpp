// Merge two sorted list in new list
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *nxt;
} *head1 = NULL, *head2 = NULL;
node *create_ll(node *head, vector<int> &v)
{
    node *t, *p;
    head = new node;
    head->data = v[0];
    head->nxt = NULL;
    p = new node;
    p = head;
    for (int i = 1; i < v.size(); i++)
    {
        t = new node;
        t->data = v[i];
        t->nxt = NULL;
        p->nxt = t;
        p = p->nxt;
    }
    return head;
}
void display_ll(node *p)
{
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->nxt;
    }
    cout << endl;
}
node *merge_into_one(node *p, node *q)
{
    if (p == NULL)
        return q;
    if (q == NULL)
        return p;
    node *third, *last;
    if (p->data < q->data)
    {
        third = p;
        last = p;
        p = p->nxt;
        last->nxt = NULL;
    }
    else
    {
        third = q;
        last = q;
        q = q->nxt;
        last->nxt = NULL;
    }
    while (p->nxt != NULL && q->nxt != NULL)
    {
        if (p->data < q->data)
        {
            last->nxt = p;
            last = p;
            p = p->nxt;
            last->nxt = NULL;
        }
        else
        {
            last->nxt = q;
            last = q;
            q = q->nxt;
            last->nxt = NULL;
        }
    }
    if (p != NULL)
    {
        last->nxt = p;
    }
    else if (q != NULL)
    {
        last->nxt = q;
    }
    return third;
}
int main()
{
    vector<int> v = {1, 3, 4, 7, 9};
    vector<int> v2 = {2, 5, 6, 8};
    node *l1 = create_ll(head1, v);
    node *l2 = create_ll(head2, v2);
    display_ll(l1);
    display_ll(l2);
    node *ans = merge_into_one(l1, l2);
    display_ll(ans);
    return 0;
}