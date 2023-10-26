// Intersection of two linked list
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
node *solve(node *l1, node *l2)
{
    // basic approch is compare for each node ( just like n2 bubble sort )
    // 2nd methode is store the address of nodes in two hash table and find if they are same or not
    // 3rd(second best) symultaneously find length of both the link list and make two dummy nodes pointing at head move the head of longer list by diff. then symaltaneously move both the nodes if they coincide then that is intersection point and if they dont collide the intersection does not exist TC: O(max(m,n)) + O(abs(m-n)) + O(min(m,n))
    // 4th(best) assign dummy nodes to both and if any node reaches null shift it to head of other linked list and proccede they will meet this time if intersection is there they will points at same location within the second iterations if not they there is no intersection
    if (l1 == NULL || l2 == NULL)
    {
        return NULL;
    }
    node *a, *b;
    a = l1, b = l2;
    while (a != b)
    {
        // for the end of first iteration we replace it with another list head after one complete iteration it will end
        if (a == NULL && b == NULL)
            return NULL;
        a = (a == NULL) ? l2 : a->nxt;
        b = (b == NULL) ? l1 : b->nxt;
    }
    return a;
}
int main()
{
    vector<int> l1 = {4, 8, 4, 5};
    vector<int> l2 = {5, 6, 1, 8, 4, 5};
    node *n1, *n2, *n3;
    n2 = create_ll(head2, l2);
    n1 = create_ll(head1, l1);
    display_ll(n1);
    display_ll(n2);
    n3 = solve(n1, n2);
    cout << n3->data << endl;
    return 0;
}