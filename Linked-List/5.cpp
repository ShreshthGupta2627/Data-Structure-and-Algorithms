// Adding two numbers given as linked list
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
node *sum(node *l1, node *l2)
{
    node *dummy = new node;
    dummy->nxt = NULL;
    node *temp = dummy;
    int carry = 0;
    while (l1 != NULL || l2 != NULL || carry)
    {
        int sum = 0;
        if (l1 != NULL)
        {
            sum += l1->data;
            l1 = l1->nxt;
        }
        if (l2 != NULL)
        {
            sum += l2->data;
            l2 = l2->nxt;
        }
        sum += carry;
        carry = sum / 10;
        node *tempnew;
        tempnew = new node;
        tempnew->data = (sum % 10);
        tempnew->nxt = NULL;
        temp->nxt = tempnew;
        temp = temp->nxt;
    }
    return dummy->nxt;
}
int main()
{
    vector<int> rev_no_1 = {9, 2, 3, 1};
    vector<int> rev_no_2 = {2, 7, 6};
    node *n1, *n2, *n3;
    n1 = create_ll(rev_no_1);
    n2 = create_ll(rev_no_2);
    n3 = sum(n1, n2);
    display_ll(n3);
    return 0;
}