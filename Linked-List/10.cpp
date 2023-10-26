// Given the head of a linked list, return the node where the cycle begins. If there is no cycle, return null.
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
node *solve1(node *h)
{
    set<node *> s;
    int prevs = 0, flag = 0;
    while (h != NULL)
    {
        s.insert(h);
        if (s.size() == prevs)
        {
            flag = 1;
            break;
        }
        h = h->nxt;
        prevs = s.size();
    }

    if (flag)
        return h;
    return NULL;
}

// Fast pointer methode
node *solve2(node *h)
{
    // Move fastand slow till they collide and then move a new ptr from heat and slow ptr symultaneously when they meet its a points of start
    if (h == NULL)
        return NULL;
    node *slow = h, *fast = h, *entry = h;
    while (fast->nxt && fast->nxt->nxt)
    {
        slow = slow->nxt;
        fast = fast->nxt->nxt;
        if (slow == fast)
        {
            while (slow != entry)
            {
                slow = slow->nxt;
                entry = entry->nxt;
            }
            return entry;
        }
    }
    return NULL;
}
int main()
{
    int n = 7;
    vector<int> a = {1, 2, 3, 4, 5, 6, 7};
    node *t1, *t2, *t3;
    t1 = create_ll(a);
    t3 = t1;
    t2 = t1;
    int m = 4;
    while (m--)
    {
        t2 = t2->nxt;
    }
    while (t3->nxt != NULL)
    {
        t3 = t3->nxt;
    }
    t3->nxt = t2;
    node *t4, *t5;
    t4 = solve1(t1);
    cout << t4->data << endl;
    t5 = solve2(t1);
    cout << t5->data << endl;
    return 0;
}