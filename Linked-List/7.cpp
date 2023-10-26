// Cycle  detection
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
void create_cycle(node *h1)
{
    node *temp = h1, *last;
    while (temp != NULL)
    {
        last = temp;
        temp = temp->nxt;
    }
    node *loop = h1->nxt;
    last->nxt = loop;
}
void detect_loop(node *p)
{
    node *slow = p, *quick = p;
    while (slow != NULL)
    {
        slow = slow->nxt;
        quick = quick->nxt->nxt;
        if (slow == quick)
        {
            cout << "LOOP" << endl;
            break;
        }
    }
}
int main()
{
    vector<int> v = {5, 6, 1, 8, 4, 5};
    node *h1 = create_ll(v);
    create_cycle(h1);
    detect_loop(h1);
}