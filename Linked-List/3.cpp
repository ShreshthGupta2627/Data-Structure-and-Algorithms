// middle of link list in case of even size return 2nd one
#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    int data;
    node *nxt;
} *head = NULL;
node *create_ll(vector<int> &v)
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
int mid_of_list(node *p)
{
    // TC O(n)
    int n = 0;
    while (p != NULL)
    {
        n++;
        p = p->nxt;
    }
    p = head;
    if (n & 1)
    {
        for (int i = 0; i < (n + 1) / 2 - 1; i++)
        {
            p = p->nxt;
        }
    }
    else
    {
        for (int i = 0; i < n / 2 + 1 - 1; i++)
        {
            p = p->nxt;
        }
    }
    return p->data;
}
int mid_of_list_tortoiseWay(node *p)
{
    // TC O(n/2)
    node *q, *r;
    q = p;
    r = q;
    while (q != NULL && q->nxt != NULL)
    {
        // slow tortoise
        r = r->nxt;
        // fast tortoise
        q = q->nxt->nxt;
    }
    return r->data;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    node *p = create_ll(v);
    display_ll(p);
    // cout << mid_of_list(p);
    cout << mid_of_list_tortoiseWay(p);
    return 0;
}