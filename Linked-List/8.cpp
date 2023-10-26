// checking for palindromic linked list
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
node *reverse_ll(node *head)
{
    node *p, *q, *r;
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
void display_ll(node *p)
{
    while (p != NULL)
    {
        cout << p->data << ' ';
        p = p->nxt;
    }
    cout << endl;
}
bool detect_palindrome(node *p)
{
    // knive approch is that put all in array and check it out
    // 2nd approch is that move to mid using toutoise methode then reverse the second half and then if all are equal then it is palindrome
    if (head == NULL || head->nxt == NULL)
        return true;
    node *slow = head, *fast = head;
    while (fast->nxt != NULL && fast->nxt->nxt != NULL)
    {
        slow = slow->nxt;
        fast = fast->nxt->nxt;
    }
    slow->nxt = reverse_ll(slow->nxt);
    slow = slow->nxt;
    while (slow != NULL)
    {
        if (head->data != slow->data)
            return false;
        head = head->nxt;
        slow = slow->nxt;
    }
    return true;
}
int main()
{
    vector<int> v = {1, 2, 3, 4, 5, 4, 3, 2, 1};
    node *ll = create_ll(v);
    display_ll(ll);
    cout << detect_palindrome(ll) << endl;
    return 0;
}