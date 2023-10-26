// Reverse a linked list in a group of k
// Ex : 1 2 3 4 5  &  k=2  =>  2 1 4 3 5
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
int length(node *h)
{
    int i = 0;
    node *t = h;
    while (t != NULL)
    {
        i++;
        t = t->nxt;
    }
    return i;
}
node *solve(node *head, int k)
{
    if (head == NULL || head->nxt == NULL)
    {
        return head;
    }
    node *dummy = new node;
    dummy->data = 0;
    dummy->nxt = NULL;
    dummy->nxt = head;
    node *curr = dummy, *nex = dummy, *pre = dummy;
    int count = 0;
    count = length(head);
    while (count >= k)
    {
        curr = pre->nxt;
        nex = curr->nxt;
        for (int i = 1; i < k; i++)
        {
            curr->nxt = nex->nxt;
            nex->nxt = pre->nxt;
            pre->nxt = nex;
            nex = curr->nxt;
        }
        pre = curr;
        count -= k;
    }
    return dummy->nxt;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8};
    int k = 3;
    node *list = create_ll(v);
    display_ll(list);
    node *t = solve(list, k);
    display_ll(t);
    return 0;
}