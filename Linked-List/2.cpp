// Deletion of 'k'th node from end
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
void del_last(node *p, int k, int n)
{
    if (k == n)
    {
        node *t = head;
        head = head->nxt;
        delete t;
        p = head;
    }
    else
    {
        int from_front = n - k;
        node *prev;
        while (from_front != 0)
        {
            prev = p;
            p = p->nxt;
            from_front--;
        }
        prev->nxt = p->nxt;
        p = head;
    }
}
int main()
{
    int n = 10;
    vector<int> v = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int k = 10; // i.e delete kth term from end
    node *p = create_ll(v);
    display_ll(p);
    del_last(p, k, n);
    display_ll(head);
    return 0;
}